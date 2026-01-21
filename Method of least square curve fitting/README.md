# 📈 Least Squares Polynomial Curve Fitting (C)

## 📌 Description
This program implements the **Least Squares Method** to fit a polynomial curve of a given degree to a set of observed data points.  
It determines the polynomial that **minimizes the sum of squared errors** between the actual data values and the predicted values.

The system of equations obtained from the least squares formulation is solved using **Gaussian Elimination with Partial Pivoting**, which improves numerical stability.

---

## 🎯 Objective
To determine the best-fitting polynomial of degree **m**:

y = a₀ + a₁x + a₂x² + ··· + aₘxᵐ

such that the **sum of squared residuals** is minimized:

S = Σ [ yᵢ − (a₀ + a₁xᵢ + a₂xᵢ² + ··· + aₘxᵢᵐ) ]²

---

## 🧠 Mathematical Foundation

### 🔹 Normal Equations
Minimizing the error function leads to **(m + 1) normal equations**:

Σ yᵢ = a₀ n + a₁ Σ xᵢ + a₂ Σ xᵢ² + ··· + aₘ Σ xᵢᵐ  

Σ xᵢ yᵢ = a₀ Σ xᵢ + a₁ Σ xᵢ² + ··· + aₘ Σ xᵢᵐ⁺¹  

⋮  

Σ xᵢᵐ yᵢ = a₀ Σ xᵢᵐ + a₁ Σ xᵢᵐ⁺¹ + ··· + aₘ Σ xᵢ²ᵐ  

Solving these equations gives the polynomial coefficients  
a₀, a₁, a₂, … , aₘ.

---

## ⚙️ Algorithm Overview

### Step 1: Input Phase
1. Input number of data points **n**
2. Input polynomial degree **m**
   - Condition:  
     1 ≤ m < n ≤ MAX_POINTS
3. Input data points (xᵢ, yᵢ)
4. Check for duplicate x-values (warning if found)

---

### Step 2: Summation Calculation
Initialize:
- sum_x[k] = Σ xᵏ  for k = 0 to 2m  
- sum_xy[k] = Σ xᵏ y for k = 0 to m  

For each data point:
- Compute successive powers of x
- Accumulate required summations

---

### Step 3: Construct Normal Equation Matrix
Create augmented matrix **A** of size (m + 1) × (m + 2):

A[i][j] = Σ x⁽ⁱ⁺ʲ⁾  
A[i][m+1] = Σ xⁱ y  

This represents the linear system:

A · X = B

---

### Step 4: Solve Linear System
Solve the system using **Gaussian Elimination with Partial Pivoting**:
- Forward elimination
- Row swapping for numerical stability
- Back substitution

This yields the coefficient vector:

X = [ a₀, a₁, … , aₘ ]

---

### Step 5: Goodness of Fit Evaluation
1. Mean of observed values:
   ȳ = (1 / n) Σ yᵢ
2. Total sum of squares:
   SS_total = Σ (yᵢ − ȳ)²
3. Residual sum of squares:
   SS_residual = Σ (yᵢ − ŷᵢ)²
4. Coefficient of determination:
   R² = 1 − (SS_residual / SS_total)
5. Mean Absolute Error (MAE)

---

### Step 6: Output Results
- Display fitted polynomial equation
- Display coefficients a₀ to aₘ
- Display R² and error statistics
- Display table of actual vs predicted values

---

## 🔁 Gaussian Elimination Algorithm

### Forward Elimination (with Partial Pivoting)
1. Select pivot row with maximum absolute value
2. Swap rows if required
3. Eliminate variables below the pivot

### Back Substitution
1. Solve the last equation
2. Substitute upward to find remaining unknowns

---

## ⏱ Time Complexity

| Step | Complexity |
|-----|------------|
| Input | O(n) |
| Summation | O(n·m) |
| Matrix construction | O(m²) |
| Gaussian elimination | O(m³) |
| Prediction & error | O(n·m) |
| **Total** | **O(n·m + m³)** |

---

## 💾 Memory Requirements

| Component | Space |
|----------|-------|
| Data points | O(n) |
| Sum arrays | O(m) |
| Matrix | O(m²) |
| Coefficients | O(m) |

---

## 📌 Applications
- Scientific data fitting
- Engineering curve approximation
- Trend analysis and forecasting
- Polynomial regression (Machine Learning)
- Signal smoothing

---

## ⚠️ Limitations
- Sensitive to outliers
- High-degree polynomials may overfit
- Numerical instability for large degree
- Equal weighting of all data points

---

## 🛠 Compilation & Execution
```bash
gcc least_squares.c -o least_squares -lm
./least_squares
✅ Key Features
Polynomial fitting up to degree 10

Gaussian elimination with partial pivoting

R² goodness-of-fit calculation

Mean absolute error computation

Clear, educational output

📚 Educational Value
This program demonstrates:

Least Squares theory

Normal equation formulation

Matrix-based solution

Gaussian elimination

Numerical stability techniques

Author: Md Alamin
Course: Numerical Methods Lab
Purpose: Academic and learning use
