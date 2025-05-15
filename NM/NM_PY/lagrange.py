def lagrange_interpolation(n, x, ax, fx):
    L = [0] * n
    v = 0.0  

    for i in range(n):
        l = 1.0
        for j in range(n):
            if j != i:
                l *= (x - ax[j]) / (ax[i] - ax[j])
        L[i] = l

    for i in range(n):
        v += fx[i] * L[i]

    return v


def main():
    n = int(input("Enter the number of positions: "))
    x = float(input("Enter the value of x: "))

    ax = []
    fx = []

    for i in range(n):
        x_val = float(input(f"Enter the value of x at i = {i}: "))
        fx_val = float(input(f"Enter the value of f(x) at i = {i}: "))
        ax.append(x_val)
        fx.append(fx_val)

    interpolated_value = lagrange_interpolation(n, x, ax, fx)
    print(f"\nInterpolated Value = {interpolated_value:.6f}")


if __name__ == "__main__":
    main()
