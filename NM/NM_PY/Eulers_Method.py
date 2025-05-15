import numpy as np

def eulers_method(f, x0, y0, x, h):
    y = y0
    while x0 < x:
        y += h * f(x0, y)
        x0 += h
    return y

def function(x, y):
    return x + y  # Example function, modify as needed

def main():
    x0 = float(input("Enter initial x0: "))
    y0 = float(input("Enter initial y0: "))
    x = float(input("Enter the value of x for approximation: "))
    h = float(input("Enter step size h: "))
    
    approximated_value = eulers_method(function, x0, y0, x, h)
    print(f"\nApproximated value at x = {x:.6f} is {approximated_value:.6f}")

if __name__ == "__main__":
    main()
