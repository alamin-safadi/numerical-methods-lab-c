# False Position (Regula-Falsi) Method – Numerical Methods Lab

## 📌 Overview
The **False Position Method**, also known as the **Regula-Falsi Method**, is a numerical technique used to find the **real root of a nonlinear equation**:

f(x) = 0

It is an improvement over the Bisection Method that uses a **linear interpolation** approach instead of a simple midpoint.

---

## 📐 Principle
If a continuous function **f(x)** satisfies:

f(a) · f(b) < 0  

then there exists **at least one real root** in the interval **[a, b]**.

The method estimates the root by drawing a straight line between the points  
(a, f(a)) and (b, f(b)) and finding where it intersects the x-axis.

---

## 🧮 Formula
The root approximation **c** is calculated using:

c = (a·f(b) − b·f(a)) / (f(b) − f(a))

---

## 🪜 Algorithm
1. Choose two initial values **a** and **b** such that  
   f(a) · f(b) < 0
2. Compute the new approximation using:  
   c = (a·f(b) − b·f(a)) / (f(b) − f(a))
3. Evaluate f(c)
4. If f(a) · f(c) < 0 → set b = c  
   else → set a = c
5. Repeat steps 2–4 until:
   - |f(c)| < ε (tolerance)  
   or  
   - Successive values of c become equal

---

## 💻 Program Implementation (C Language)
- Language: **C**
- Header files used:
  - `stdio.h`
  - `math.h`

The program displays:
- Iteration number
- Values of **a, b, c**
- Function value **f(c)**

---

## 🧪 Sample Function
Example function used in this program:

f(x) = 3x − cos(x) − 1

You can modify the function definition in the code as required.

---

## ✅ Advantages
- Faster convergence than Bisection Method
- Guaranteed root within the interval
- Simple logic and easy implementation

---

## ❌ Limitations
- Convergence can be slow if one endpoint remains fixed
- Not always efficient for all types of functions
- Requires continuous function

---

## 📚 Course Information
- **Course:** Numerical Methods Lab
- **Topic:** Root Finding Techniques
- **Method:** False Position (Regula-Falsi) Method

---

## 👨‍💻 Author
**Md Alamin**

---

## 📎 Note
This repository is created for **academic and learning purposes** only.  
The code is suitable for **lab exams and assignments**.

