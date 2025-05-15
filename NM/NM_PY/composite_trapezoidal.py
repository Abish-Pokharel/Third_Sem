# Define the function
def f(x):
    return 3 * (x ** 2) + 2 * x - 5  # f(x) = 3x^2 + 2x - 5

def main():
    # Input lower and upper limits
    x0 = float(input("Enter Lower Limit: "))
    xn = float(input("Enter Upper Limit: "))

    # Input number of segments
    k = int(input("Enter Number of Segments: "))

    # Compute step size (h)
    h = (xn - x0) / k

    # Compute function values at limits
    fx0 = f(x0)
    fxn = f(xn)
    
    # Compute sum of intermediate values
    term = fx0 + fxn
    for i in range(1, k):
        a = x0 + i * h
        term += 2 * f(a)

    # Apply Trapezoidal Rule formula
    v = (h / 2) * term

    # Display result
    print(f"Value of Integration: {v:.6f}")

if __name__ == "__main__":
    main()
