import sys

def calculator(a, b):
    """
    This function takes two integers A and B as arguments
    and prints the results of the following operations:
    Sum, Difference, Product, Quotient and Remainder.
    """
    print(f"Sum: {a + b}")
    print(f"Difference: {a - b}")
    print(f"Product: {a * b}")
    # print("Sum:", a + b)
    # print("Difference:", a - b)
    # print("Product:", a * b)

    if b == 0:
        print("Quotient: ERROR (division by zero)")
        print("Remainder: ERROR (modulo by zero)")
    else:
        print(f"Quotient: {a / b}")
        print(f"Remainder: {a % b}")

if __name__ == "__main__":
    if len(sys.argv) <= 2:
        print("Usage: python operations.py <number1> <number2>")
        print("Example:")
        print("python operations.py 10 3")
    elif len(sys.argv) != 3:
        raise AssertionError("too many arguments")
    else:
        try:
            arg1 = int(sys.argv[1])
            arg2 = int(sys.argv[2])
            calculator(arg1, arg2)
        except ValueError:
            raise AssertionError("only integers")