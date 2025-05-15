import numpy as np

def solve_heat_equation(n, tL, tR, tT, tB, error_limit):
    a = np.zeros((n*n, n*n))  # Coefficient matrix
    b = np.zeros(n*n)  # Right-hand side vector
    new_x = np.zeros(n*n)  # Solution vector
    old_x = np.zeros(n*n)  # Previous iteration vector

    # Initialize coefficient matrix
    for i in range(n):
        for j in range(n):
            row_index = i * n + j
            a[row_index, row_index] = -4  # Main diagonal
            if i > 0:
                a[row_index, (i - 1) * n + j] = 1  # Top neighbor
            if i < n - 1:
                a[row_index, (i + 1) * n + j] = 1  # Bottom neighbor
            if j > 0:
                a[row_index, i * n + (j - 1)] = 1  # Left neighbor
            if j < n - 1:
                a[row_index, i * n + (j + 1)] = 1  # Right neighbor

    # Apply boundary conditions to vector b
    for i in range(n):
        for j in range(n):
            row_index = i * n + j
            if i == 0:
                b[row_index] -= tT  # Top boundary
            if i == n - 1:
                b[row_index] -= tB  # Bottom boundary
            if j == 0:
                b[row_index] -= tL  # Left boundary
            if j == n - 1:
                b[row_index] -= tR  # Right boundary

    # Iterative solution using Gauss-Seidel method
    while True:
        E = np.zeros(n*n)
        for i in range(n*n):
            if a[i, i] == 0:
                continue  # Avoid division by zero
            sum_value = b[i] - np.dot(a[i], old_x) + (a[i, i] * old_x[i])
            new_x[i] = sum_value / a[i, i]
            E[i] = abs(new_x[i] - old_x[i]) / (abs(new_x[i]) + 1e-10)  # Avoid division by zero
        
        if np.all(E < error_limit):
            break
        
        old_x[:] = new_x  # Update old_x with new values

    return new_x.reshape((n, n))  # Return solution in 2D format

# User input
n = int(input("Enter the dimension of plate (n,n): "))
tL, tR, tT, tB = map(float, input("Enter temperatures at left, right, top, and bottom: ").split())
error_limit = float(input("Enter accuracy limit: "))

solution = solve_heat_equation(n, tL, tR, tT, tB, error_limit)

print("Solution:")
print(solution)
