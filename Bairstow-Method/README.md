# Determination of Roots of a Polynomial – Numerical Methods Lab

## 📌 Overview
This program is designed to **determine the real roots of a polynomial equation** using numerical evaluation.
In this implementation, the focus is on solving a **quartic (4th degree) polynomial equation** of the form:

ax⁴ + bx³ + cx² + dx + e = 0

The program evaluates the polynomial for selected values of x and detects roots based on function values approaching zero.

---

## 📐 Principle
A number x is considered a root of the polynomial if:

f(x) ≈ 0

The program:
- Evaluates the polynomial using **Horner’s Method**
- Tests possible **rational roots**
- Verifies roots numerically within a small tolerance

---

## 🧮 Polynomial Evaluation (Horner’s Method)
The polynomial is evaluated efficiently using Horner’s scheme:

f(x) = (((a₄x + a₃)x + a₂)x + a₁)x + a₀

This reduces computation time and improves numerical stability.

---

## 🪜 Algorithm

1. Input coefficients a, b, c, d, e of the quartic equation.
2. Store coefficients in an array in increasing order of power.
3. Display the polynomial in readable mathematical form.
4. Evaluate the polynomial for a predefined set of rational values.
5. If |f(x)| < ε, then x is considered a root.
6. Store only **unique roots** to avoid duplication.
7. Display all detected roots and verify by evaluating f(x).

---

## 💻 Program Implementation (C Language)

- Language: **C**
- Header files used:
  - `stdio.h`
  - `math.h`
- Constants:
  - `MAX_DEG` → Maximum polynomial degree
  - `EPSILON` → Error tolerance for root verification

---

## 🧪 Sample Input
Example polynomial:

x⁴ − 5x³ + 6x² + 4x − 8 = 0

Enter coefficients accordingly when prompted.

---

## 📊 Output
The program displays:
- Detected rational roots
- Root values
- Verification of each root using f(x)

Example output format:
Root 1: x = 2.000000
Verification: f(2.000000) = 0.000000e+00


---

## ✅ Advantages
- Simple and efficient root detection
- Uses Horner’s method for fast evaluation
- Automatically avoids duplicate roots
- Suitable for lab exams and assignments

---

## ❌ Limitations
- Detects only rational roots from the tested set
- Does not compute irrational or complex roots
- Fixed to quartic equations in current implementation

---

## 📚 Course Information
- **Course:** Numerical Methods Lab
- **Experiment:** Determination of roots of a polynomial
- **Technique:** Polynomial evaluation & numerical verification

---

## 👨‍💻 Author
**Md Alamin**

---

## 📎 Note
This program is developed for **academic and learning purposes**.
It follows standard numerical methods lab practices and is suitable for **viva and practical exams**.
You may extend it to handle higher-degree or non-rational roots if needed.
