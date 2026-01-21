📈 Least Squares Polynomial Curve Fitting (C)
📌 Description

This program implements the Least Squares Method to fit a polynomial curve of a given degree to a set of observed data points.
It finds the polynomial that minimizes the sum of squared errors between the actual data points and the predicted values.

The system of equations generated from the least squares formulation is solved using Gaussian Elimination with Partial Pivoting, ensuring numerical stability.

🎯 Objective

To determine the best-fitting polynomial of degree m:

𝑦
=
𝑎
0
+
𝑎
1
𝑥
+
𝑎
2
𝑥
2
+
⋯
+
𝑎
𝑚
𝑥
𝑚
y=a
0
	​

+a
1
	​

x+a
2
	​

x
2
+⋯+a
m
	​

x
m

such that the sum of squared residuals is minimized:

𝑆
=
∑
𝑖
=
1
𝑛
[
𝑦
𝑖
−
(
𝑎
0
+
𝑎
1
𝑥
𝑖
+
𝑎
2
𝑥
𝑖
2
+
⋯
+
𝑎
𝑚
𝑥
𝑖
𝑚
)
]
2
S=
i=1
∑
n
	​

[y
i
	​

−(a
0
	​

+a
1
	​

x
i
	​

+a
2
	​

x
i
2
	​

+⋯+a
m
	​

x
i
m
	​

)]
2
🧠 Mathematical Foundation
🔹 Normal Equations

Minimizing the error function leads to (m+1) normal equations:

∑
𝑦
𝑖
=
𝑎
0
𝑛
+
𝑎
1
∑
𝑥
𝑖
+
𝑎
2
∑
𝑥
𝑖
2
+
⋯
+
𝑎
𝑚
∑
𝑥
𝑖
𝑚
∑y
i
	​

=a
0
	​

n+a
1
	​

∑x
i
	​

+a
2
	​

∑x
i
2
	​

+⋯+a
m
	​

∑x
i
m
	​

∑
𝑥
𝑖
𝑦
𝑖
=
𝑎
0
∑
𝑥
𝑖
+
𝑎
1
∑
𝑥
𝑖
2
+
⋯
+
𝑎
𝑚
∑
𝑥
𝑖
𝑚
+
1
∑x
i
	​

y
i
	​

=a
0
	​

∑x
i
	​

+a
1
	​

∑x
i
2
	​

+⋯+a
m
	​

∑x
i
m+1
	​

⋮
⋮
∑
𝑥
𝑖
𝑚
𝑦
𝑖
=
𝑎
0
∑
𝑥
𝑖
𝑚
+
𝑎
1
∑
𝑥
𝑖
𝑚
+
1
+
⋯
+
𝑎
𝑚
∑
𝑥
𝑖
2
𝑚
∑x
i
m
	​

y
i
	​

=a
0
	​

∑x
i
m
	​

+a
1
	​

∑x
i
m+1
	​

+⋯+a
m
	​

∑x
i
2m
	​


These equations are solved to obtain the coefficients 
𝑎
0
,
𝑎
1
,
…
,
𝑎
𝑚
a
0
	​

,a
1
	​

,…,a
m
	​

.

⚙️ Algorithm Overview
Step 1: Input Phase

Input number of data points n

Input polynomial degree m

Condition:

1
≤
𝑚
<
𝑛
≤
MAX_POINTS
1≤m<n≤MAX_POINTS

Input data points 
(
𝑥
𝑖
,
𝑦
𝑖
)
(x
i
	​

,y
i
	​

)

Check for duplicate 
𝑥
x-values (warning if found)

Step 2: Summation Calculation

Initialize:

sum_x[k] = Σ x^k for 
𝑘
=
0
k=0 to 
2
𝑚
2m

sum_xy[k] = Σ x^k y for 
𝑘
=
0
k=0 to 
𝑚
m

For each data point:

Compute successive powers of 
𝑥
x

Accumulate required sums

Step 3: Construct Normal Equation Matrix

Create augmented matrix A of size 
(
𝑚
+
1
)
×
(
𝑚
+
2
)
(m+1)×(m+2):

𝐴
[
𝑖
]
[
𝑗
]
=
∑
𝑥
𝑖
+
𝑗
A[i][j]=∑x
i+j
𝐴
[
𝑖
]
[
𝑚
+
1
]
=
∑
𝑥
𝑖
𝑦
A[i][m+1]=∑x
i
y

This represents the linear system:

𝐴
⋅
𝑋
=
𝐵
A⋅X=B
Step 4: Solve Linear System (Gaussian Elimination)

Use Gaussian Elimination with Partial Pivoting:

Forward elimination

Row swapping for numerical stability

Back substitution

This yields polynomial coefficients:

𝑋
=
[
𝑎
0
,
𝑎
1
,
…
,
𝑎
𝑚
]
X=[a
0
	​

,a
1
	​

,…,a
m
	​

]
Step 5: Goodness of Fit Evaluation

Compute mean of observed values:

𝑦
ˉ
=
1
𝑛
∑
𝑦
𝑖
y
ˉ
	​

=
n
1
	​

∑y
i
	​


Total sum of squares:

𝑆
𝑆
𝑡
𝑜
𝑡
𝑎
𝑙
=
∑
(
𝑦
𝑖
−
𝑦
ˉ
)
2
SS
total
	​

=∑(y
i
	​

−
y
ˉ
	​

)
2

Residual sum of squares:

𝑆
𝑆
𝑟
𝑒
𝑠
𝑖
𝑑
𝑢
𝑎
𝑙
=
∑
(
𝑦
𝑖
−
𝑦
^
𝑖
)
2
SS
residual
	​

=∑(y
i
	​

−
y
^
	​

i
	​

)
2

Coefficient of determination:

𝑅
2
=
1
−
𝑆
𝑆
𝑟
𝑒
𝑠
𝑖
𝑑
𝑢
𝑎
𝑙
𝑆
𝑆
𝑡
𝑜
𝑡
𝑎
𝑙
R
2
=1−
SS
total
	​

SS
residual
	​

	​


Mean Absolute Error (MAE)

Step 6: Output Results

Display fitted polynomial equation

Display coefficients

Display R² value and error statistics

Display table of actual vs predicted values

🔁 Gaussian Elimination Algorithm
Forward Elimination (with Partial Pivoting)

Select pivot row with maximum absolute value

Swap rows if necessary

Eliminate variables below pivot

Back Substitution

Solve last equation

Substitute upward to find remaining unknowns

⏱ Time Complexity
Step	Complexity
Input	O(n)
Summation	O(n·m)
Matrix Construction	O(m²)
Gaussian Elimination	O(m³)
Prediction & Error	O(n·m)
Total	O(n·m + m³)
💾 Memory Requirements
Component	Space
Data points	O(n)
Sum arrays	O(m)
Matrix	O(m²)
Coefficients	O(m)
📌 Applications

Scientific data fitting

Engineering curve approximation

Trend analysis & forecasting

Polynomial regression (Machine Learning)

Signal smoothing

⚠️ Limitations

Sensitive to outliers

High-degree polynomials may overfit

Numerical instability for large degree

Equal weighting of all data points

🛠 Compilation & Execution
gcc least_squares.c -o least_squares -lm
./least_squares

✅ Key Features

Polynomial fitting up to degree 10

Gaussian elimination with pivoting

R² goodness-of-fit calculation

Mean absolute error calculation

Detailed, educational output

📚 Educational Value

This program demonstrates:

Least Squares theory

Normal equations

Matrix formulation

Gaussian elimination

Numerical stability techniques
