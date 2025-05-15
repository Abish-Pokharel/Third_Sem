# Define the function
def f(x):
    return x * x + 3 * x + 1  # f(x) = x^2 + 3x + 1

def main():
    # Input lower and upper limits
    x0 = float(input("Enter Lower Limit: "))
    x1 = float(input("Enter Upper Limit: "))

    # Compute step size (h)
    h = x1 - x0

    # Compute function values at limits
    fx0 = f(x0)
    fx1 = f(x1)

    # Apply Trapezoidal Rule formula
    v = (h / 2) * (fx0 + fx1)

    # Display result
    print(f"Value of Integration: {v:.6f}")

if __name__ == "__main__":
    main()
