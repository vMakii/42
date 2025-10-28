import sys
import random

def guess():
    """
    This is an interactive guessing game where the user has to guess
    a randomly generated number between 1 and 99.
    """
    attempts = 0
    number_to_guess = random.randint(1, 99)
    # number_to_guess = 42
    print("This is an interactive guessing game!")
    print("You have to enter a number between 1 and 99 to find the secret number.")
    print("Type 'exit' to end the game.")
    print("Good luck!")

    while True:
        user_input = input("What's your guess between 1 and 99?\n>> ")

        if user_input.lower() == "exit":
            print("Thanks for playing!")
            break
        try:
            guess = int(user_input)
        except ValueError:
            print("That's not a valid number.")
            continue

        attempts += 1
        if guess < 1 or guess > 99:
            print("Out of bounds! Please try again.")
        elif guess == number_to_guess:
            if number_to_guess == 42:
                print("The answer to the ultimate question of life, the universe and everything is 42.")
            if attempts == 1:
                print("Congratulations! You got it on your first try!")
            else:
                print(f"Congratulations! You got it in {attempts} attempts.")
            break
        elif guess < number_to_guess:
            print("Too low!")
        else:
            print("Too high!")

if __name__ == "__main__":
    guess()
