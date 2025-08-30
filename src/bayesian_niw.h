#pragma once
#include <Eigen/Dense>
using namespace Eigen;

struct NIW {
    VectorXd mu0;
    double kappa0;
    MatrixXd Psi0;
    double nu0;

    void update(const MatrixXd& R, VectorXd& mu_n, MatrixXd& Sigma_n) {
        int n = R.rows(), p = R.cols();
        
        // Compute sample mean
        VectorXd ybar = R.colwise().mean();
        
        // Compute sample covariance manually to avoid type issues
        MatrixXd S = MatrixXd::Zero(p, p);
        for (int i = 0; i < n; ++i) {
            VectorXd diff = R.row(i).transpose() - ybar;
            S += diff * diff.transpose();
        }
        S = S / static_cast<double>(n);
        
        double kn = kappa0 + static_cast<double>(n);
        double nun = nu0 + static_cast<double>(n);
        
        // Update parameters with explicit type casting
        VectorXd temp1 = kappa0 * mu0;
        VectorXd temp2 = static_cast<double>(n) * ybar;
        mu_n = (temp1 + temp2) / kn;
        
        VectorXd diff = ybar - mu0;
        MatrixXd outer_product = diff * diff.transpose();
        
        MatrixXd temp3 = static_cast<double>(n) * S;
        MatrixXd temp4 = (kappa0 * static_cast<double>(n) / kn) * outer_product;
        MatrixXd Psi_n = Psi0 + temp3 + temp4;
        
        Sigma_n = Psi_n / (nun - static_cast<double>(p) - 1.0);
    }
};
