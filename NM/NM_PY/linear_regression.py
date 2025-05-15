# Write a python program for Linear Regression

def linear_regression():
    n = int(input("Enter the number of points: "))  
    x = []  
    y = []  

    print("Enter the values of x and y:")  
    for i in range(n):  
        xi = float(input(f"X[{i+1}]= "))  
        yi = float(input(f"Y[{i+1}]= "))  

        x.append(xi)  
        y.append(yi)  

    sumX = sum(x)  
    sumY = sum(y)  
    sumX2 = sum(xi ** 2 for xi in x)  
    sumXY = sum(x[i] * y[i] for i in range(n))  

    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX ** 2)  
    a = (sumY - b * sumX) / n  

    print(f"\nValues are : a = {a:.3f} and b = {b:.3f}")  
    print(f"Equation of best fit is: y = {a:.3f} + {b:.3f} x")  

linear_regression()
