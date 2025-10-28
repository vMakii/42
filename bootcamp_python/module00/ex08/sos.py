import sys

def check_string(S):
    """
    This function checks if the string S contains only space and
    alphanumeric characters.
    """
    return all(char == ' ' or char.isalnum() for char in S)

def encode_morse(S):
    """
    This function takes a word S as an argument and returns
    its Morse code equivalent.
    """
    morse_dict = {
        'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.',
        'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..',
        'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
        'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
        'Y': '-.--', 'Z': '--..',
        '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-',
        '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.'
    }
    return ' '.join(morse_dict[char.upper()] for char in S if char.upper() in morse_dict)

def main():
    if len(sys.argv) < 2:
        print("Usage: python sos.py <string>")
        return
    S = " ".join(sys.argv[1:])
    if not check_string(S):
        print("ERROR: Invalid characters in input string")
        return
    print(encode_morse(S))

if __name__ == "__main__":
    main()