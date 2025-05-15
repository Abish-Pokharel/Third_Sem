import math  

# Function definition
def f(x):
    return 2 * math.exp(x)

def main():
    # User input for x and h
    x = float(input("Enter the value at which derivative is required: "))
    h = float(input("Enter increment (h): "))

    # Backward Difference Formula
    d = (f(x) - f(x - h)) / h

    # Display result
    print(f"Value of Derivative = {d:.6f}")

if __name__ == "__main__":
    main()
