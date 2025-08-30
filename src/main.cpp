#include <iostream>
#include "data_loader.h"
#include "bayesian_niw.h"
#include "portfolio_optimizer.h"
#include "utils.h"

int main() {
    auto R = loadCSV("data/returns.csv");
    std::cout << "Loaded data with " << R.rows() << " rows and " << R.cols() << " columns\n";

    NIW prior{VectorXd::Zero(R.cols()), 1.0, MatrixXd::Identity(R.cols(), R.cols()), static_cast<double>(R.cols() + 2)};
    VectorXd mu_n;
    MatrixXd Sigma_n;
    prior.update(R, mu_n, Sigma_n);
    
    std::cout << "Posterior mean: " << mu_n.transpose() << "\n";
    std::cout << "Posterior covariance:\n" << Sigma_n << "\n";

    double lambda = 1.0;  // Reduced from 10.0
    VectorXd w = optimize(mu_n, Sigma_n, lambda);
    
    std::cout << "Raw weights: " << w.transpose() << "\n";
    
    // Normalize weights to sum to 1
    double sum = w.sum();
    if (std::abs(sum) > 1e-10) {
        w = w / sum;
    }
    
    std::cout << "Normalized weights: " << w.transpose() << "\n";

    auto result = evaluate(R, w);
    double exp_ret = std::get<0>(result);
    double vol = std::get<1>(result);
    double sharpe = std::get<2>(result);
    saveCSV("weights.csv", w);

    std::cout << "Weights:\n" << w.transpose() << "\n";
    std::cout << "Expected Return: " << exp_ret << ", Volatility: " << vol << ", Sharpe: " << sharpe << "\n";
    return 0;
}
