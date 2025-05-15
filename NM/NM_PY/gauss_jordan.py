import numpy as np

def gauss_jordan():
    n = int(input("Enter Dimension of System of equations: "))

    print("Enter coefficients row-wise:")
    a = []
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)
    a = np.array(a)

    print("Enter RHS vector:")
    b = list(map(float, input().split()))
    b = np.array(b)

    # Augmented matrix
    aug = np.hstack((a, b.reshape(-1, 1)))

    # Gauss-Jordan Elimination
    for i in range(n):
        # Make the diagonal element 1
        pivot = aug[i][i]
        if abs(pivot) < 1e-6:
            print("Method failed: Singular matrix detected.")
            return
        aug[i] = aug[i] / pivot

        # Make all other elements in the current column 0
        for j in range(n):
            if i != j:
                factor = aug[j][i]
                aug[j] -= factor * aug[i]

    # Extract solution
    x = aug[:, -1]

    # Display Solution
    print("Solution:")
    for i in range(n):
        print(f"x{i + 1} = {x[i]:.2f}")

if __name__ == "__main__":
    gauss_jordan()
