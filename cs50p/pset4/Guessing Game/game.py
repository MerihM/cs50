import random


def get_lvl():
    # Prompt user for level input
    while True:
        try:
            lvl = int(input("Level: "))
            # If level is lower than 1, reprompt
            if lvl < 1:
                continue
            break
        # Reprompt user if ValueError
        except ValueError:
            pass
    # Return valid level
    return lvl


def main():
    # Get random number in range from 1 to inputed level
    num = random.randrange(1, get_lvl())
    while True:
        try:
            # Prompt user for guess
            guess = int(input("Guess: "))
            # Break if number guessed
            if num == guess:
                print("Just right!")
                break
            # If guess is greater than number, print 'Too large' and reprompt
            elif num < guess:
                print("Too large!")
            # If guess is lower, print 'Too small' and reprompt
            else:
                print("Too small!")
        # Reprompt if ValueError
        except ValueError:
            pass


if __name__ == "__main__":
    main()
