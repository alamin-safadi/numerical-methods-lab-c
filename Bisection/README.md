# Bisection Method – Numerical Methods Lab

## 📌 Overview
The **Bisection Method** is a numerical technique used to find the **real root of a nonlinear equation**  
of the form:

f(x) = 0

This method works by repeatedly dividing an interval into two halves and selecting the subinterval in which the root lies.

---

## 📐 Principle
If a continuous function **f(x)** satisfies:

f(a) · f(b) < 0  

then there exists **at least one real root** between **a** and **b**.

---

## 🧮 Algorithm
1. Choose two initial guesses **a** and **b** such that  
   f(a) · f(b) < 0
2. Compute the midpoint  
   c = (a + b) / 2
3. Evaluate f(c)
4. If f(a) · f(c) < 0 → set b = c  
   else → set a = c
5. Repeat steps 2–4 until:
   - |f(c)| < ε  (tolerance)  
   or  
   - Maximum number of iterations reached

---

## 💻 Program Implementation (C Language)
- Language: **C**
- Header files used:
  - `stdio.h`
  - `math.h`

The program prints iteration-wise values of **a, b, c, and f(c)** in tabular form.

---

## 🧪 Sample Function
Example function used in this program:

f(x) = 3x − cos(x) − 1

You can modify the function inside the code as needed.

---

## ✅ Advantages
- Simple and easy to understand
- Guaranteed convergence
- Suitable for beginner-level numerical analysis

---

## ❌ Limitations
- Slow convergence compared to other methods
- Requires function to be continuous
- Needs initial interval where sign change occurs

---

## 📚 Course Information
- **Course:** Numerical Methods Lab
- **Topic:** Root Finding Methods
- **Method:** Bisection Method

---

## 👨‍💻 Author
**Md Alamin**

---

## 📎 Note
This repository is created for **academic and learning purposes**.  
Feel free to use and modify the code.

