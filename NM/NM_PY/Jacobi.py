import math

def jacobi_method():
    n = int(input("Enter Dimension of System of Equations: "))

    print("Enter Coefficients (Row-wise): ")
    a = []
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)

    print("Enter RHS Vector:")
    b = list(map(float, input().split()))

    error = float(input("Enter Accuracy Limit: "))

    # Initialize x values to 0
    old_x = [0.0] * n
    new_x = [0.0] * n

    while True:
        converged = True  # Assume convergence

        for i in range(n):
            sum_ = b[i]

            for j in range(n):
                if i != j:
                    sum_ -= a[i][j] * old_x[j]

            new_x[i] = sum_ / a[i][i]  # Jacobi update

            # Compute relative error
            relative_error = abs(new_x[i] - old_x[i]) / abs(new_x[i])

            # If any error is above the threshold, we have not yet converged
            if relative_error > error:
                converged = False

        # Copy new_x to old_x for next iteration
        old_x = new_x[:]

        # If converged, exit the loop
        if converged:
            break

    # Display the solution
    print("Solution:")
    for i in range(n):
        print(f"x{i + 1} = {new_x[i]:6.4f}")

if __name__ == "__main__":
    jacobi_method()
