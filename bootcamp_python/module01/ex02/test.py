from vector import Vector

# Column vector of shape n * 1
v1 = Vector([[0.0], [1.0], [2.0], [3.0]], (4, 1))
# gburtin = Vector()
v2 = v1 * 5
print(v2)
# Expected output:
# Vector([[0.0], [5.0], [10.0], [15.0]])