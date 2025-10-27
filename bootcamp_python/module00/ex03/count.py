import sys
import string


def text_analyzer(text=None):
    """
    This function counts the number of upper characters, lower characters,
    punctuation and spaces in a given text.
    """
    if text is None:
        text = input("What is the text to analyze?\n>> ")
    
    assert isinstance(text, str), "argument is not a string"
    
    upper_count = sum(1 for c in text if c.isupper())
    lower_count = sum(1 for c in text if c.islower())
    punctuation_count = sum(1 for c in text if c in string.punctuation)
    space_count = sum(1 for c in text if c.isspace())
    total_count = len(text)
    
    print(f"The text contains {total_count} character(s):")
    print(f"- {upper_count} upper letter(s)")
    print(f"- {lower_count} lower letter(s)")
    print(f"- {punctuation_count} punctuation mark(s)")
    print(f"- {space_count} space(s)")

#   .format()
#   print("The text contains {} character(s):".format(total_count))
#   print("- {} upper letter(s)".format(upper_count))

#   %
#   print("The text contains %d character(s):" % total_count)
#   print("- %d upper letter(s)" % upper_count)

if __name__ == "__main__":
    if len(sys.argv) > 2:
        print("ERROR: Too many arguments")
    elif len(sys.argv) == 2:
        text_analyzer(sys.argv[1])
    else:
        text_analyzer()