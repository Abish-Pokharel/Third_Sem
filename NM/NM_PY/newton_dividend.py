def divided_difference_table(n, ax, fx):
    """Computes the divided difference table."""
    table = [[0] * n for _ in range(n)]
    
    # First column is f(x) values
    for i in range(n):
        table[i][0] = fx[i]

    # Compute divided differences
    for j in range(1, n):
        for i in range(n - j):
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (ax[i + j] - ax[i])

    return table


def newton_interpolation(n, x, ax, fx):
    """Computes the interpolated value using Newton's Divided Difference method."""
    table = divided_difference_table(n, ax, fx)
    interpolated_value = table[0][0]  # f(x0)
    term = 1.0

    # Apply Newton's interpolation formula
    for i in range(1, n):
        term *= (x - ax[i - 1])  # (x - x0)(x - x1)...
        interpolated_value += table[0][i] * term

    return interpolated_value


def main():
    n = int(input("Enter the number of data points: "))
    x = float(input("Enter the interpolation point (Xp): "))

    ax = []
    fx = []

    for i in range(n):
        x_val = float(input(f"X[{i}] ="))
        fx_val = float(input(f"Y[{i}] ="))
        ax.append(x_val)
        fx.append(fx_val)

    interpolated_value = newton_interpolation(n, x, ax, fx)
    print(f"\nInterpolated Value at {x} is y = {interpolated_value:.6f}")


if __name__ == "__main__":
    main()
