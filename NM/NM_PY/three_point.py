# Function definition
def f(x):
    return 2 * (x) * (x) + 1  # Equivalent to 2x^2 + 1

def main():
    # User input for x and h
    x = float(input("Enter the value at which derivative is required: "))
    h = float(input("Enter increment (h): "))

    # Central Difference Formula
    d = (f(x + h) - f(x - h)) / (2 * h)

    # Display result
    print(f"Value of Derivative = {d:.6f}")

if __name__ == "__main__":
    main()
