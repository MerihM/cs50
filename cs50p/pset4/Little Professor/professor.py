import random


def main():
    # generate_integer(2)
    level = get_level()
    # Generate ten pairs and their sum
    # Store them in list
    num_list = get_nums_list(level)
    # Pass list to guess_game
    guess_game(num_list)


def guess_game(num_list):
    # Set score
    score = 0
    # Iterate over every list element
    for n in num_list:
        # Set guess ctr to 0
        ctr = 0
        # Prompt user max three times
        for _ in range(3):
            # Get user input
            try:
                guess = int(input(f"{n[0]} = "))
                # If wrong number raise Exception
                if guess != n[1]:
                    raise Exception
                # If correct guess increment score and break out of loop
                else:
                    score += 1
                    break
            # Print out EEE if Exception or ValueError, then reprompt user
            except (ValueError, Exception):
                ctr += 1
                print("EEE")
                pass
            # If guessed incorrectly three times, print out answer
            if ctr == 3:
                print(f"{n[0]} = {n[1]}")
    # Print out score
    print(f"Score: {score}")


def get_nums_list(level):
    nums_list = []
    for _ in range(10):
        # Generate two random ints
        first = generate_integer(level)
        second = generate_integer(level)
        # Set first element of the list to string X + Y
        num_key = f"{first} + {second}"
        # Set second element of the list to sum of X and Y
        num_sum = first + second
        # Append list to nums_list
        nums_list.append([num_key, num_sum])
    # Return nums_list
    return nums_list


# Prompt user for input
# Input has to be 1, 2, or 3


def get_level():
    # Reprompt until 1, 2, or 3 is selected
    while True:
        try:
            lvl = int(input("Level: "))
            # Reprompt if not one 1, 2, or 3
            if not lvl in range(1, 4):
                continue
            else:
                break
        # Reprompt if not int
        except ValueError:
            pass
    return lvl


def generate_integer(level):
    # Raise a ValueError if level is not 1, 2, or 3
    try:
        if not level in range(1, 4):
            raise ValueError
    except ValueError:
        return

    # Find start and end of the range
    range_start = 10 ** (level - 1)
    range_end = 10**level - 1
    if level == 1:
        range_start -= 1
    # print(range_start, range_end)
    # Return randomly generated non-negative int with level digits
    return random.randint(range_start, range_end)


if __name__ == "__main__":
    main()
