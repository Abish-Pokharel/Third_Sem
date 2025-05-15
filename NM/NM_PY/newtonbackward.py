def backward_difference_table(n, ax, fx):
    table = [[0] * n for _ in range(n)]
    for i in range(n):
        table[i][0] = fx[i]
    for j in range(1, n):
        for i in range(n - 1, j - 1, -1):
            table[i][j] = table[i][j - 1] - table[i - 1][j - 1]
    return table

def newton_backward_interpolation(n, x, ax, fx):
    table = backward_difference_table(n, ax, fx)
    h = ax[1] - ax[0]
    p = (x - ax[-1]) / h
    interpolated_value = table[n - 1][0]
    term = 1.0
    for i in range(1, n):
        term *= (p + (i - 1)) / i
        interpolated_value += table[n - 1][i] * term
    return interpolated_value

def main():
    n = int(input("Enter the number of data points: "))
    x = float(input("Enter the interpolation point (Xp): "))
    ax = []
    fx = []
    for i in range(n):
        x_val = float(input(f"X[{i}] = "))
        fx_val = float(input(f"Y[{i}] = "))
        ax.append(x_val)
        fx.append(fx_val)
    interpolated_value = newton_backward_interpolation(n, x, ax, fx)
    print(f"\nInterpolated Value at {x} is y = {interpolated_value:.4f}")

if __name__ == "__main__":
    main()
