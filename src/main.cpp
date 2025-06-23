#include <iostream>
#include "data_loader.h"
#include "bayesian_niw.h"
#include "portfolio_optimizer.h"
#include "utils.h"

int main() {
    auto R = loadCSV("data/returns.csv");

    NIW prior{VectorXd::Zero(R.cols()), 1.0, MatrixXd::Identity(R.cols(), R.cols()), R.cols() + 2};
    VectorXd mu_n;
    MatrixXd Sigma_n;
    prior.update(R, mu_n, Sigma_n);

    double lambda = 10.0;
    VectorXd w = optimize(mu_n, Sigma_n, lambda);

    auto [exp_ret, vol, sharpe] = evaluate(R, w);
    saveCSV("weights.csv", w);

    std::cout << "Weights:\n" << w.transpose() << "\n";
    std::cout << "Expected Return: " << exp_ret << ", Volatility: " << vol << ", Sharpe: " << sharpe << "\n";
    return 0;
}
