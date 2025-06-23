#pragma once
#include <Eigen/Dense>
#include "qp_solver.h"
using namespace Eigen;

VectorXd optimize(const VectorXd& mu, const MatrixXd& Sigma, double lambda) {
    MatrixXd H = 2 * lambda * Sigma;
    VectorXd f = mu;
    return solve_qp(H, f);
}
