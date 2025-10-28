import sys
import string

def filterwords(S, N):
    """
    This function takes a string S and an integer N as arguments
    and returns a list of words from S that contains more than N
    non-punctuation characters.
    """
    return [word for word in S.split() if sum(1 for char in word if char not in string.punctuation) > N]

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("ERROR")
    else:
        S = sys.argv[1]
        try:
            N = int(sys.argv[2])
            result = filterwords(S, N)
            print(result)
        except ValueError:
            print("ERROR")