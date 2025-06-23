#pragma once
#include <Eigen/Dense>
#include "QuadProg++.hh"
using namespace Eigen;

VectorXd solve_qp(const MatrixXd& H, const VectorXd& f) {
    int n = f.size();
    quadprogpp::Vector<double> g(n), x(n);
    quadprogpp::Matrix<double> G(n, n), CE(n, 1), CI(n, n);
    quadprogpp::Vector<double> ce0(1), ci0(n);

    for (int i = 0; i < n; ++i) g[i] = -f[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            G[i][j] = H(i, j);

    ce0[0] = 1.0;
    for (int i = 0; i < n; ++i) CE[i][0] = 1.0;

    for (int i = 0; i < n; ++i) {
        ci0[i] = 0.0;
        for (int j = 0; j < n; ++j)
            CI[j][i] = (i == j) ? 1.0 : 0.0;
    }

    quadprogpp::solve_quadprog(G, g, CE, ce0, CI, ci0, x);

    VectorXd w(n);
    for (int i = 0; i < n; ++i) w[i] = x[i];
    return w;
}
