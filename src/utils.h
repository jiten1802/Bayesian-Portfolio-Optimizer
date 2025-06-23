#pragma once
#include <Eigen/Dense>
#include <fstream>
using namespace Eigen;

std::tuple<double, double, double> evaluate(const MatrixXd& R, const VectorXd& w) {
    VectorXd port_ret = R * w;
    double mean = port_ret.mean();
    double stddev = std::sqrt((port_ret.array() - mean).square().mean());
    double sharpe = mean / stddev;
    return {mean, stddev, sharpe};
}

void saveCSV(const std::string& filename, const VectorXd& w) {
    std::ofstream file(filename);
    for (int i = 0; i < w.size(); ++i)
        file << w[i] << "\n";
}
