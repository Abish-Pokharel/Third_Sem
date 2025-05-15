import math

# Define the function
def f(x):
    return math.sin(x)  # f(x) = sin(x)

def simpsons_3_8_rule(x0, x1, n):
    if n % 3 != 0:
        raise ValueError("Number of intervals must be a multiple of 3.")

    # Compute step size (h)
    h = (x1 - x0) / n

    # Compute function values
    term = f(x0) + f(x1)

    for i in range(1, n):
        x = x0 + i * h
        if i % 3 == 0:
            term += 2 * f(x)  # Multiple of 3
        else:
            term += 3 * f(x)  # Others

    # Apply Simpson’s 3/8 Rule formula
    v = (3 * h / 8) * term
    return v

def main():
    # Take input from user
    x0 = float(input("Enter Lower Limit (in radians): "))
    x1 = float(input("Enter Upper Limit (in radians): "))
    n = int(input("Enter number of intervals (multiple of 3): "))

    try:
        result = simpsons_3_8_rule(x0, x1, n)
        print(f"Value of Integration: {result:.6f}")
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
