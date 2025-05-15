import numpy as np

def main():
    n = int(input("Enter Dimension of System of equations: "))
    print("Enter coefficients Matrix:")
    a = []
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)
    
    a = np.array(a, dtype=float)
    identity_matrix = np.eye(n)
    augmented_matrix = np.hstack((a, identity_matrix))
    
    for k in range(n):
        pivot = augmented_matrix[k, k]
        augmented_matrix[k, :] = augmented_matrix[k, :] / pivot
        for i in range(n):
            if i != k:
                term = augmented_matrix[i, k]
                augmented_matrix[i, :] = augmented_matrix[i, :] - augmented_matrix[k, :] * term
    
    inverse_matrix = augmented_matrix[:, n:]
    print("Matrix Inverse is:")
    for row in inverse_matrix:
        print("\t".join(map(str, row)))

if __name__ == "__main__":
    main()
