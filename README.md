# Bayesian Portfolio Optimizer

A C++ implementation of a **Bayesian Portfolio Optimizer** using the **Normal-Inverse-Wishart (NIW)** prior and **Quadratic Programming** to find the optimal asset weights under uncertainty. This project combines modern Bayesian statistics with mean-variance portfolio theory.

---

## Features

- Bayesian posterior estimation of mean and covariance (NIW conjugate prior)
- Risk-return trade-off optimization using quadratic programming (QP)
- Enforces portfolio constraints:
  - Fully invested: sum of weights = 1
  - No short-selling: weights ≥ 0
- Computes Sharpe ratio, expected return, and volatility
- Efficient and fast (header-only Eigen + QuadProg++)

---

## Output Example

```
Weights:
0.21  0.34  0.45
Expected Return: 0.0163
Volatility: 0.0058
Sharpe: 2.81
```

---

## Project Structure

```
BayesianPortfolioOptimizer/
├── CMakeLists.txt
├── README.md
├── data/
│   └── returns.csv          # Input: Historical returns (rows = time, cols = assets)
├── external/
│   └── QuadProg++/          # Quadratic programming solver
├── src/
│   ├── main.cpp
│   ├── data_loader.h
│   ├── bayesian_niw.h
│   ├── qp_solver.h
│   ├── portfolio_optimizer.h
│   └── utils.h
```

---

## Dependencies

- [Eigen 3](https://eigen.tuxfamily.org) – header-only linear algebra library
- [QuadProg++](https://github.com/liuq/QuadProgpp) – quadratic programming solver
- CMake ≥ 3.10
- C++17 compiler (MSVC, g++, clang++)

---

## Sample Input: data/returns.csv

```
0.01,0.02,0.015
0.012,0.018,0.013
0.011,0.019,0.016
0.013,0.017,0.014
```

---

## Build Instructions (Windows/Linux)

1. Clone or download the repo:

```bash
git clone https://github.com/yourusername/BayesianPortfolioOptimizer.git
cd BayesianPortfolioOptimizer
```

2. Create build directory and compile:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

3. Run the optimizer:

```bash
./optimizer    # or optimizer.exe on Windows
```

Output will print the weights and save them to `weights.csv`.

---

## Theory

We assume:

- Asset returns follow a multivariate normal distribution
- The prior distribution on mean and covariance is Normal-Inverse-Wishart (NIW):

  - μ ~ N(μ₀, Σ / κ₀)  
  - Σ ~ Inverse-Wishart(Ψ₀, ν₀)

After observing the return matrix `R ∈ ℝⁿˣᵈ`, we compute the posterior estimates of mean and covariance:

- μₙ, Σₙ

Then solve the following quadratic optimization problem:

Minimize:

```
(1/2) * wᵗ * Σₙ * w - μₙᵗ * w
```

Subject to:

```
∑ wᵢ = 1
wᵢ ≥ 0
```

This produces an optimal weight vector `w` for portfolio allocation based on the Bayesian estimates.

---

## Learning Goals

- Understand how Bayesian inference refines parameter estimates
- Learn to implement constrained quadratic optimization
- Work with real-world financial return data
- Apply Eigen and CMake in a modular C++ project

---

## To-Do

- Add support for short selling (negative weights)
- Use Monte Carlo sampling instead of MAP estimate
- Add CSV logging of all performance metrics

---

## License

MIT License — free for personal and commercial use.

---


