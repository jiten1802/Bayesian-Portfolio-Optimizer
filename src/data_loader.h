#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>
using namespace Eigen;

MatrixXd loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<double>> data;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream linestream(line);
        std::string cell;
        std::vector<double> row;
        while (std::getline(linestream, cell, ',')) {
            row.push_back(std::stod(cell));
        }
        data.push_back(row);
    }
    int rows = data.size(), cols = data[0].size();
    MatrixXd mat(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mat(i, j) = data[i][j];
    return mat;
}
