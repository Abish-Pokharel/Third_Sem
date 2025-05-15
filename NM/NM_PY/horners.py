def evaluate_polynomial(coefficients, x):
    n = len(coefficients) - 1
    b = [0] * (n + 1)

    b[n] = coefficients[n]
    for i in range(n - 1, -1, -1):
        b[i] = coefficients[i] + b[i + 1] * x

    return b[0]

def main():
    n = int(input("Enter degree of polynomial: "))
    
    coefficients = []
    print("Enter coefficients of dividend polynomial:")
    for i in range(n, -1, -1):
        coeff = float(input(f"Coefficient of x^{i}: "))
        coefficients.append(coeff)

    x = float(input("Enter the value at which polynomial is to be evaluated: "))
    
    result = evaluate_polynomial(coefficients, x)
    print(f"Value of polynomial p({x}) = {result:.6f}")

if __name__ == "__main__":
    main()
