import sys

def main():
    """
    Takes string arguments, merges them, reverses the result,
    swaps the case, and prints it.
    """
    if len(sys.argv) < 2:
        print("Usage: python exec.py <string> [string ...]")
        return
    merged_string = " ".join(sys.argv[1:])
    reversed_string = merged_string[::-1]
    swapped_case = reversed_string.swapcase()
    print(swapped_case)

#   print(" ".join(sys.argv[1:])[::-1].swapcase())