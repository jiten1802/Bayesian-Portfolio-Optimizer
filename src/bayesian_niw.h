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
        VectorXd ybar = R.colwise().mean();
        MatrixXd centered = R.rowwise() - ybar.transpose();
        MatrixXd S = centered.transpose() * centered;
        double kn = kappa0 + n;
        double nun = nu0 + n;
        MatrixXd Psi_n = Psi0 + S + (kappa0 * n / kn) * (ybar - mu0) * (ybar - mu0).transpose();
        mu_n = (kappa0 * mu0 + n * ybar) / kn;
        Sigma_n = Psi_n / (nun - p - 1);
    }
};
