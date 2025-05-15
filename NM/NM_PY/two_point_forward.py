import math

# Define the function f(x)
def f(x):
    return math.sin(x) + 1

def main():
    angle = float(input("Enter Angle in Degrees: "))
    h = float(input("Enter Increment (h): "))

    # Convert degrees to radians
    x = math.pi / 180 * angle

    # Compute derivative using forward difference formula
    d = (f(x + h) - f(x)) / h

    print(f"Value of Derivative = {d:.6f}")

if __name__ == "__main__":
    main()
