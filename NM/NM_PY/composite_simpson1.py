import math

# Define the function
def f(x):
    return math.sin(x)  # f(x) = sin(x)

def simpsons_rule(x0, x1, n):
    if n % 2 != 0:
        raise ValueError("Number of intervals must be even.")

    # Compute step size (h)
    h = (x1 - x0) / n

    # Compute function values
    term = f(x0) + f(x1)

    for i in range(1, n):
        x = x0 + i * h
        if i % 2 == 0:
            term += 2 * f(x)  # Even index
        else:
            term += 4 * f(x)  # Odd index

    # Apply Simpson’s 1/3 Rule formula
    v = (h / 3) * term
    return v

def main():
    # Take input from user
    x0 = float(input("Enter Lower Limit (in radians): "))
    x1 = float(input("Enter Upper Limit (in radians): "))
    n = int(input("Enter number of intervals (even number): "))

    try:
        result = simpsons_rule(x0, x1, n)
        print(f"Value of Integration: {result:.6f}")
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
