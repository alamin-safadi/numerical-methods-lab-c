# Lagrange Interpolation Method – Numerical Methods Lab

## 📌 Overview
The **Lagrange Interpolation Method** is a numerical technique used to estimate the value of a function at a specific point when only a set of discrete data points is available and the explicit functional form is unknown.

This program implements the Lagrange interpolation formula using **dynamic memory allocation**, making it flexible for any number of data points.

---

## 📐 Mathematical Theory

Given `n` data points:

(x₀, y₀), (x₁, y₁), (x₂, y₂), ..., (xₙ₋₁, yₙ₋₁)

The Lagrange interpolation polynomial is defined as:

\[
P(x) = \sum_{i=0}^{n-1} y_i \cdot L_i(x)
\]

where,

\[
L_i(x) = \prod_{\substack{j=0 \\ j \neq i}}^{n-1}
\frac{(x - x_j)}{(x_i - x_j)}
\]

This polynomial passes **exactly through all given data points**.

---

## 🪜 Algorithm

1. Input the number of data points `n`.
2. Dynamically allocate memory for arrays `x[]` and `y[]`.
3. Input the known data points `(x[i], y[i])`.
4. Input the value `xp` at which interpolation is required.
5. Initialize `result = 0`.
6. For each data point:
   - Compute the Lagrange basis polynomial.
   - Multiply it with the corresponding `y[i]`.
   - Add the term to `result`.
7. Display the interpolated value.
8. Free dynamically allocated memory.

---

## 💻 Program Implementation

- **Language:** C  
- **Header Files Used:**
  - `stdio.h`
  - `stdlib.h`

### Key Features:
- Uses **dynamic memory allocation (`malloc`)**
- Supports any number of data points
- Works for **unequally spaced data**
- Clean and modular implementation

---

## 🧪 Sample Input

Enter number of data points: 4

Enter data points (x y):
1 1
2 4
3 9
4 16

Enter the point to interpolate (x): 2.5


---

## 📊 Sample Output

Interpolated value at x = 2.50
y(2.50) = 6.25


---

## ✅ Advantages

- Simple and direct interpolation method
- No need for equal spacing between data points
- Suitable for small and medium-sized datasets
- Easy to understand and implement

---

## ❌ Limitations

- Computationally expensive for large datasets
- Polynomial degree increases with number of points
- Not suitable for extrapolation far outside the data range
- Entire polynomial must be recomputed if a new data point is added

---

## 📚 Applications

- Estimation of missing experimental data
- Engineering and scientific computations
- Weather and environmental data analysis
- Computer graphics and animation
- Economics and statistical modeling

---

## ⚙️ Compile and Run

```bash
gcc lagrange.c -o lagrange
./lagrange
📚 Course Information
Course: Numerical Methods Lab

Experiment: Lagrange Interpolation Method

Topic: Interpolation Techniques

👨‍💻 Author
Md Alamin
