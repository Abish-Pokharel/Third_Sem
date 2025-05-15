import math

# Define the function f(x)
def f(x):
    return x**3 + 1  # Given function

# Function to perform 2-point Gaussian Quadrature
def gaussian_quadrature(a, b):
    # Gaussian points
    z1, z2 = -0.57735, 0.57735  

    # Transform integration limits
    x1 = ((b - a) / 2) * z1 + (b + a) / 2
    x2 = ((b - a) / 2) * z2 + (b + a) / 2

    # Gaussian Quadrature Formula
    result = ((b - a) / 2) * (f(x1) + f(x2))

    return result

def main():
    # User input
    a = float(input("Enter Lower Limit: "))
    b = float(input("Enter Upper Limit: "))

    result = gaussian_quadrature(a, b)
    
    print(f"\nValue of Integration = {result:.6f}")

if __name__ == "__main__":
    main()
