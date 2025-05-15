import math

# Define the function to be integrated
def f(x):
    return math.sin(x)  # f(x) = sin(x)

# Function to implement Simpson's 3/8 Rule
def simpsons_3_8_rule(x0, x1, n):
    if n % 3 != 0:
        print("Number of intervals must be a multiple of 3.")
        return None

    h = (x1 - x0) / n  # Step size

    # Compute function values
    term = f(x0) + f(x1)

    for i in range(1, n):
        x = x0 + i * h
        if i % 3 == 0:
            term += 2 * f(x)  # Multiples of 3
        else:
            term += 3 * f(x)  # Others

    v = (3 * h / 8) * term  # Applying Simpson's 3/8 Rule formula
    return v

def main():
    # Take user input
    x0 = float(input("Enter Lower Limit (in radians): "))
    x1 = float(input("Enter Upper Limit (in radians): "))
    n = int(input("Enter number of intervals (multiple of 3): "))

    result = simpsons_3_8_rule(x0, x1, n)
    
    if result is not None:
        print(f"Value of Integration: {result:.6f}")

if __name__ == "__main__":
    main()
