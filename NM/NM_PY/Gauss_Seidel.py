# Write a Python program for Gauss-Seidel Method

import numpy as np

def gauss_seidel_method():
    n = int(input("Enter Dimension of System of Equations: "))
    
    a = np.zeros((n, n))
    b = np.zeros(n)
    new_x = np.zeros(n)
    error = float(input("Enter Accuracy Limit: "))

    print("Enter Coefficients Row-wise:")
    for i in range(n):
        for j in range(n):
            a[i][j] = float(input(f"a[{i+1}][{j+1}]: "))

    print("Enter RHS vector:")
    for i in range(n):
        b[i] = float(input(f"b[{i+1}]: "))

    while True:
        old_x = new_x.copy()
        for i in range(n):
            sum_ = b[i]
            for j in range(n):
                if i != j:
                    sum_ -= a[i][j] * new_x[j]
            new_x[i] = sum_ / a[i][i]

        errors = [abs(new_x[i] - old_x[i]) / abs(new_x[i]) for i in range(n)]

        if all(err <= error for err in errors):
            break

    print("\nSolution:")
    for i in range(n):
        print(f"x[{i+1}] = {new_x[i]:.6f}")

gauss_seidel_method()
