import numpy as np

def cubic_spline_interpolation(x, f, P):
    n = len(x)
    h = np.zeros(n - 1)
    F = np.zeros(n - 1)
    s = np.zeros(n)
    m = np.zeros((n, n))
    
    # Compute h and divided differences F
    for i in range(n - 1):
        h[i] = x[i + 1] - x[i]
        F[i] = (f[i + 1] - f[i]) / h[i]
    
    # Construct matrix system for second derivatives s[i]
    for i in range(1, n - 1):
        m[i, i] = 2 * (h[i - 1] + h[i])
        if i != 1:
            m[i, i - 1] = h[i - 1]
            m[i - 1, i] = h[i - 1]
        m[i, n - 1] = 6 * (F[i] - F[i - 1])
    
    # Solve for s using back-substitution
    for i in range(n - 2, 0, -1):
        sum_ = sum(m[i, j] * s[j] for j in range(i, n - 1))
        s[i] = (m[i, n - 1] - sum_) / m[i, i]
    
    # Find sub-interval containing P and compute interpolated value
    for i in range(n - 1):
        if x[i] <= P <= x[i + 1]:
            a = (s[i + 1] - s[i]) / (6 * h[i])
            b = s[i] / 2
            c = (f[i + 1] - f[i]) / h[i] - (2 * h[i] * s[i] + s[i + 1] * h[i]) / 6
            d = f[i]
            
            interpolated_value = (a * (P - x[i])**3 +
                                  b * (P - x[i])**2 +
                                  c * (P - x[i]) +
                                  d)
            return interpolated_value, (a, b, c, d)
    return None, None

def main():
    n = int(input("Enter number of points: "))
    x, f = [], []
    
    print("\nEnter all sample points (x, f(x)):")
    for _ in range(n):
        xi, fi = map(float, input().split())
        x.append(xi)
        f.append(fi)
    
    P = float(input("\nEnter Interpolation point: "))
    
    interpolated_value, coeffs = cubic_spline_interpolation(x, f, P)
    
    if interpolated_value is not None:
        print("\nCoefficients of sub-intervals:")
        for coeff in coeffs:
            print(f"{coeff:.6f}")
        print(f"\nInterpolated value = {interpolated_value:.6f}")
    else:
        print("\nInterpolation point out of range!")

if __name__ == "__main__":
    main()
