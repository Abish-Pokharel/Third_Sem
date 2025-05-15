import numpy as np

def gauss_seidel(a, b, tol=1e-6, max_iter=100):
    n = len(b)
    x = np.zeros(n)  # Initial guess
    for _ in range(max_iter):
        x_new = np.copy(x)
        for i in range(n):
            sum_ = b[i] - np.dot(a[i, :i], x_new[:i]) - np.dot(a[i, i+1:], x[i+1:])
            x_new[i] = sum_ / a[i, i]
        
        # Convergence check
        if np.all(np.abs((x_new - x) / x_new) < tol):
            return x_new
        x = x_new
    return x

def main():
    n = int(input("Enter the dimension of plate (n,n): "))
    tL, tR, tT, tB = map(float, input("Enter temperatures at left, right, top, and bottom: ").split())
    
    # Initialize coefficient matrix
    a = np.zeros((n, n))
    np.fill_diagonal(a, -4)
    for i in range(n - 1):
        a[i, i + 1] = 1
        a[i + 1, i] = 1
    
    # Initialize right-hand side vector
    b = np.zeros(n)
    k = 0
    for i in range(1, n - 1):
        for j in range(1, n - 1):
            if i - 1 == 0:
                b[k] -= tL
            if i + 1 == n - 1:
                b[k] -= tR
            if j - 1 == 0:
                b[k] -= tB
            if j + 1 == n - 1:
                b[k] -= tT
            k += 1
    
    error = float(input("Enter accuracy limit: "))
    solution = gauss_seidel(a, b, tol=error)
    
    print("Solution:")
    for i, val in enumerate(solution):
        print(f"x[{i}] = {val:.6f}")

if __name__ == "__main__":
    main()
