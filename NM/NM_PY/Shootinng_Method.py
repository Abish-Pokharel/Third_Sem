import math

# Define functions f1 and f2
def f1(x, y, z):
    return z

def f2(x, y, z):
    return 6 * x

def shooting_method(xa, ya, xb, yb, xp, h, E):
    x = xa
    V1 = ya
    g1 = (yb - ya) / (xb - xa)  # Initial guess

    print(f"Initial g1 = {g1:.4f}")

    while x < xb:
        ny = V1 + f1(x, V1, g1) * h
        nz = g1 + f2(x, V1, g1) * h
        x += h
        V1 = ny
        g1 = nz

        if abs(x - xp) < 1e-6:  # Checking if x is close to xp
            sol = V1

    if V1 < yb:
        g2 = g1 * 2
    else:
        g2 = g1 / 2

    # Iterative shooting method loop
    while True:
        x = xa
        V2 = ya
        g2 = g1 - ((V2 - yb) / (V2 - V1)) * (g2 - g1)

        while x < xb:
            ny = V2 + f1(x, V2, g2) * h
            nz = g2 + f2(x, V2, g2) * h
            x += h
            V2 = ny
            g2 = nz

            if abs(x - xp) < 1e-6:
                sol = V2

        error = abs(V2 - yb) / yb
        V1 = V2
        g1 = g2

        if error < E:
            print(f"y({xp:.2f}) = {sol:.4f}")
            break

# Input values
xa = float(input("Enter Boundary Conditions (xa): "))
ya = float(input("Enter ya: "))
xb = float(input("Enter xb: "))
yb = float(input("Enter yb: "))
xp = float(input("Enter x at which value is required (xp): "))
h = float(input("Enter step size (h): "))
E = float(input("Enter accuracy limit (E): "))

# Run the Shooting Method
shooting_method(xa, ya, xb, yb, xp, h, E)
