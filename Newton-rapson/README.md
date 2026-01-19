# Newton–Raphson Method – Numerical Methods Lab

## 📌 Overview
The **Newton–Raphson Method** is an efficient numerical technique used to find the **real root of a nonlinear equation** of the form:

f(x) = 0

This method uses the **first derivative of the function** to iteratively improve the approximation of the root.

---

## 📐 Principle
Starting from an initial guess x₀, the method draws a **tangent line** at the point (x₀, f(x₀)).  
The point where this tangent intersects the x-axis gives a better approximation of the root.

---

## 🧮 Mathematical Formula
The iterative formula used in the Newton–Raphson Method is:

xₙ₊₁ = xₙ − f(xₙ) / f′(xₙ)

---

## 🪜 Algorithm (As Per Lab Procedure)

1. Find the derivative **f′(xₙ)** of the given function.
2. Find two real numbers **a** and **b** such that:  
   f(a) · f(b) < 0
3. Assume the initial approximation:  
   x₀ = a
4. Compute the next approximation using:  
   xₙ₊₁ = xₙ − f(xₙ) / f′(xₙ)
5. Find successive values:  
   x₁, x₂, x₃, … , xₙ  
   until **any two successive values are equal** (or nearly equal within tolerance).

---

## 💻 Program Implementation (C Language)

- Language: **C**
- Header files used:
  - `stdio.h`
  - `math.h`

The program prints:
- Iteration number
- Current approximation xₙ
- Function value f(xₙ)
- Derivative value f′(xₙ)
- Next approximation xₙ₊₁

---

## 🧪 Sample Function
Example function used in this program:

f(x) = 3x − cos(x) − 1  

Derivative:

f′(x) = 3 + sin(x)

You can modify both **f(x)** and **f′(x)** in the code as required.

---

## ✅ Advantages
- Very fast convergence
- Requires fewer iterations compared to Bisection and False Position methods
- Highly accurate when initial guess is close to the root

---

## ❌ Limitations
- Requires derivative f′(x)
- May fail if f′(x) = 0
- Convergence is not guaranteed for poor initial guesses

---

## 📚 Course Information
- **Course:** Numerical Methods Lab
- **Topic:** Root Finding Techniques
- **Method:** Newton–Raphson Method

---

## 👨‍💻 Author
**Md Alamin**

---

## 📎 Note
This repository is created for **academic and learning purposes**.  
The implementation strictly follows the **lab manual procedure** and is suitable for **lab exams and assignments**.
