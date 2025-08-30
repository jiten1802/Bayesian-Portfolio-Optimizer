#pragma once
#include <Eigen/Dense>
#include <fstream>
#include <tuple>
#include <cmath>
using namespace Eigen;

std::tuple<double, double, double> evaluate(const MatrixXd& R, const VectorXd& w) {
    int n = R.rows();
    VectorXd port_ret(n);
    
    // Compute portfolio returns
    for (int i = 0; i < n; ++i) {
        port_ret(i) = R.row(i).dot(w);
    }
    
    // Compute mean
    double mean = 0.0;
    for (int i = 0; i < n; ++i) {
        mean += port_ret(i);
    }
    mean /= static_cast<double>(n);
    
    // Compute standard deviation
    double variance = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = port_ret(i) - mean;
        variance += diff * diff;
    }
    variance /= static_cast<double>(n);
    double stddev = std::sqrt(variance);
    
    // Compute Sharpe ratio
    double sharpe = mean / stddev;
    
    return {mean, stddev, sharpe};
}

void saveCSV(const std::string& filename, const VectorXd& w) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < w.size(); ++i) {
            file << w(i) << "\n";
        }
        file.close();
    }
}
