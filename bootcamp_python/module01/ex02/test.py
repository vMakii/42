from vector import Vector

try:
    # Column vector of shape n * 1
    v1 = Vector([[0.0], [1.0], [2.0], [3.0]])
    v2 = v1 * 5
    print(v2)
    # Expected output:
    # Vector([[0.0], [5.0], [10.0], [15.0]])
except Exception as e:
    print(e)
try:
    # Row vector of shape 1 * n
    v1 = Vector([[0.0, 1.0, 2.0, 3.0]])
    v2 = v1 * 5
    print(v2)
    # Expected output
    # Vector([[0.0, 5.0, 10.0, 15.0]])
except Exception as e:
    print(e)
try:
    v2 = v1 / 2.0
    print(v2)
    # Expected output
    # Vector([[0.0, 0.5, 1.0, 1.5]])
    v1 / 0.0
    # Expected output
    # ZeroDivisionError: division by zero.
except Exception as e:
    print(e)
try:
    2.0 / v1
    # Expected output:
    # NotImplementedError: Division of a scalar by a Vector is not defined here.
except Exception as e:
    print(e)

try:
    # Column vector of shape (n, 1)
    print(Vector([[0.0], [1.0], [2.0], [3.0]]).shape)
    # Expected output
    # (4,1)
    print(Vector([[0.0], [1.0], [2.0], [3.0]]).values)
    # Expected output
    # [[0.0], [1.0], [2.0], [3.0]]
except Exception as e:
    print(e)

try:
    # Row vector of shape (1, n)
    print(Vector([[0.0, 1.0, 2.0, 3.0]]).shape)
    # Expected output
    # (1,4)
    print(Vector([[0.0, 1.0, 2.0, 3.0]]).values)
    # Expected output
    # [[0.0, 1.0, 2.0, 3.0]]
except Exception as e:
    print(e)

try:
    # Example 1:
    v1 = Vector([[0.0], [1.0], [2.0], [3.0]])
    print(v1.shape)
    # Expected output:
    (4,1)
    print(v1.T())
    # Expected output:
    # Vector([[0.0, 1.0, 2.0, 3.0]])
    print(v1.T().shape)
    # Expected output:
    # (1,4)
except Exception as e:
    print(e)

try:
    # Example 2:
    v2 = Vector([[0.0, 1.0, 2.0, 3.0]])
    print(v2.shape)
    # Expected output:
    # (1,4)
    print(v2.T())
    # Expected output:
    # Vector([[0.0], [1.0], [2.0], [3.0]])
    print(v2.T().shape)
    # Expected output:
    # (4,1)
except Exception as e:
    print(e)

try:
    # Example 1:
    v1 = Vector([[0.0], [1.0], [2.0], [3.0]])
    v2 = Vector([[2.0], [1.5], [2.25], [4.0]])
    print(v1.dot(v2))
    # Expected output:
    # 18.0
    v3 = Vector([[1.0, 3.0]])
    v4 = Vector([[2.0, 4.0]])
    print(v3.dot(v4))
    # Expected output:
    # 14.0
except Exception as e:
    print(e)

try:
    v1 = Vector([[0.0], [1.0], [2.0], [3.0]])
    v1
    # Expected output: to see what __repr__() should do
    # [[0.0, 1.0, 2.0, 3.0]]
    print(v1)
    # Expected output: to see what __str__() should do
    # Vector([[0.0], [1.0], [2.0], [3.0]])
except Exception as e:
    print(e)

# final expected output:
# Vector([[0.0], [5.0], [10.0], [15.0]])
# Vector([[0.0, 5.0, 10.0, 15.0]])
# Vector([[0.0, 0.5, 1.0, 1.5]])
# division by zero.
# Division of a scalar by a Vector is not defined here.
# (4, 1)
# [[0.0], [1.0], [2.0], [3.0]]
# (1, 4)
# [[0.0, 1.0, 2.0, 3.0]]
# (4, 1)
# Vector([[0.0, 1.0, 2.0, 3.0]])
# (1, 4)
# (1, 4)
# Vector([[0.0], [1.0], [2.0], [3.0]])
# (4, 1)
# 18.0
# 14.0
# [[0.0], [1.0], [2.0], [3.0]]
# Vector([[0.0], [1.0], [2.0], [3.0]])