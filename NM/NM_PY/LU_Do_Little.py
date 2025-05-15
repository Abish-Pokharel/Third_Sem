import numpy as np

def main():

    n = int(input("Enter Dimension of Matrix: "))

    print("Enter Elements of Matrix:")
    a = []
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)
    a = np.array(a)

    # Initialize L and U matrices
    l = np.eye(n)  # Identity matrix for L
    u = np.zeros((n, n))  # Initialize U as zero

    # Compute Elements of L and U matrix
    for j in range(n):
        # Compute U matrix
        for i in range(j + 1):
            sum_u = sum(l[i][k] * u[k][j] for k in range(i))
            u[i][j] = a[i][j] - sum_u

        # Compute L matrix
        for i in range(j + 1, n):
            sum_l = sum(l[i][k] * u[k][j] for k in range(j))
            l[i][j] = (a[i][j] - sum_l) / u[j][j]

    # Print L matrix
    print("\n********** L Matrix **********")
    for row in l:
        print("\t".join(f"{elem:.2f}" for elem in row))

    # Print U matrix
    print("\n********** U Matrix **********")
    for row in u:
        print("\t".join(f"{elem:.2f}" for elem in row))


if __name__ == "__main__":
    main()
