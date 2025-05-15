import numpy as np  

def polynomial_regression():  
    n = int(input("Enter the number of points: "))  
    m = int(input("Enter degree of polynomial to be fitted: "))  

    if m >= n:  
        print("Error: Degree of polynomial must be less than the number of points!")  
        return  

    x = []  
    y = []  

    print("Enter the values of x and y:")  
    for i in range(n):  
        xi, yi = map(float, input(f"(X{i+1} , Y{i+1}) : ").split())   
        x.append(xi)  
        y.append(yi)  

    X = np.vander(x, m + 1, increasing=True)  
    A = np.dot(X.T, X)  
    b = np.dot(X.T, y)  

    coefficients = np.dot(np.linalg.pinv(A), b)

    print("\nThe polynomial equation is:")  
    terms = [f"{coefficients[i]:.3f} x^{i}" if i > 0 else f"{coefficients[i]:.3f}"  
             for i in range(len(coefficients)) if abs(coefficients[i]) > 1e-6]  
    equation = "y = " + " + ".join(terms)  

    print(equation)  

polynomial_regression()
