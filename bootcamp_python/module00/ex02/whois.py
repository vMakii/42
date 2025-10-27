import sys

def main():
    """
    takes a number as argument, checks wether it is odd,
    even or zero, and prints the result.
    """
    assert len(sys.argv) == 2, "more than one argument is provided"
    
    try:
        number = int(sys.argv[1])
    except ValueError:
        raise AssertionError("argument is not an integer")
    
    if number == 0:
        print("I'm Zero.")
    elif number % 2 == 0:
        print("I'm Even.")
    else:
        print("I'm Odd.")

if __name__ == "__main__":
    main()