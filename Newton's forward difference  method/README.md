# Newton’s Forward Difference Interpolation – Numerical Methods Lab

## 📌 Overview
Newton’s Forward Difference Interpolation is a numerical technique used to **estimate the value of a function at an intermediate point**, when the data points are **equally spaced** and the interpolation point lies **near the beginning of the data table**.

This program implements **Newton’s Forward Interpolation Formula** using the C programming language.

---

## 📐 Mathematical Theory

Let the given data points be equally spaced.

- Interval size:  
  h = x₁ − x₀  

- Parameter:  
  u = (x − x₀) / h  

### Newton’s Forward Formula

f(x) = y₀  
   + uΔy₀  
   + u(u−1)/2! · Δ²y₀  
   + u(u−1)(u−2)/3! · Δ³y₀  
   + …

Where:  
- y₀ = f(x₀)  
- Δy₀ = y₁ − y₀  
- Δ²y₀ = Δy₁ − Δy₀  
- Δ³y₀ = Δ²y₁ − Δ²y₀  

---

## 🪜 Algorithm

1. Input the number of data points `n`.
2. Input `x` and `y` values in **ascending order of x**.
3. Construct the **forward difference table**.
4. Compute interval size `h` and parameter `u`.
5. Apply Newton’s Forward Interpolation formula.
6. Continue adding terms until all required forward differences are used.
7. Display the interpolated value.

---

## 💻 Program Implementation (C Language)

- Language: **C**
- Header files used:
  - `stdio.h`
  - `math.h`
- Maximum data points controlled using:
  ```c
  #define MAX_POINTS 20
The program includes:

Recursive factorial calculation

Forward difference table generation

Interpolation computation using Newton’s formula

🧪 Sample Input
Number of data points: 5

x   y
0   1
1   2
2   4
3   8
4   16
Interpolation point:

x = 2.5
📊 Sample Output
Interpolated value at x = 2.50 is y = 5.656250
The program also prints the complete forward difference table for clarity and verification.

✅ Advantages
Accurate for interpolation near the beginning of the table

Simple and systematic approach

Easy to implement and understand

Suitable for lab exams and viva

❌ Limitations
Requires equal interval data

Accuracy decreases for interpolation far from x₀

Not suitable for unevenly spaced data

📚 Applications
Numerical analysis

Scientific and engineering computations

Estimation of missing data

Interpolation in experimental datasets

⚙️ Compile and Run
gcc newton_forward.c -o newton_forward
./newton_forward
📚 Course Information
Course: Numerical Methods Lab

Experiment: Newton’s Forward Difference Interpolation

Category: Interpolation Techniques

👨‍💻 Author
Md Alamin

📎 Note
This program is developed strictly for academic and learning purposes.
It follows the standard Numerical Methods Lab syllabus and is suitable for class tests, lab exams, and assignments.
