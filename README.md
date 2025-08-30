# Bayesian Portfolio Optimizer

A C++ implementation of a **Bayesian Portfolio Optimizer** using the **Normal-Inverse-Wishart (NIW)** prior and **Quadratic Programming** to find optimal asset weights under uncertainty.

## Overview

This project implements Bayesian portfolio optimization that:
- Uses NIW conjugate prior for mean and covariance estimation
- Optimizes risk-return trade-off using quadratic programming
- Enforces portfolio constraints (fully invested, no short-selling)
- Computes performance metrics (Sharpe ratio, expected return, volatility)

## Project Structure

```
Bayesian-Portfolio-Optimizer/
├── src/                    # Source code
│   ├── main.cpp           # Main program
│   ├── bayesian_niw.h     # NIW prior implementation
│   ├── portfolio_optimizer.h # Portfolio optimization
│   ├── qp_solver.h        # Quadratic programming solver
│   ├── data_loader.h      # CSV data loading
│   └── utils.h            # Utility functions
├── external/              # External libraries
│   ├── QuadProd++/        # QuadProg++ solver
│   └── eigen/             # Eigen linear algebra library
├── data/                  # Data files
│   └── returns.csv        # Sample return data
├── build/                 # Build directory
└── CMakeLists.txt         # Build configuration
```

## Dependencies

- **CMake 3.10+** - Build system
- **MinGW-w64** - C++ compiler (Windows)
- **C++17** - Language standard
- **Eigen 3.3.9** - Linear algebra (auto-downloaded)
- **QuadProg++** - Quadratic programming solver (included)

## Quick Start

1. **Clone and build:**
   ```bash
   git clone <repository-url>
   cd Bayesian-Portfolio-Optimizer
   mkdir build && cd build
   cmake .. -G "MinGW Makefiles"
   cmake --build .
   ```

2. **Run the optimizer:**
   ```bash
   ./optimizer.exe
   ```

3. **Output:**
   - Console: Portfolio weights and performance metrics
   - File: `weights.csv` with optimal asset weights

## Input Data Format

The program expects `data/returns.csv` with:
- Each row = time period
- Each column = asset
- Values = percentage returns (e.g., 0.01 = 1%)

Example:
```
0.01,0.02,0.015
0.012,0.018,0.013
0.011,0.019,0.016
```

## Algorithm

1. **Bayesian Update:** Update NIW prior with historical returns
2. **Posterior Estimation:** Compute posterior mean and covariance
3. **Optimization:** Solve quadratic program for optimal weights
4. **Evaluation:** Calculate portfolio performance metrics

## Output

- **Optimal weights:** Asset allocation percentages
- **Expected return:** Portfolio expected return
- **Volatility:** Portfolio standard deviation  
- **Sharpe ratio:** Risk-adjusted return measure

## License

This project is open source and available under the MIT License.


