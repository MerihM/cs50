from pyfiglet import Figlet
import sys
import random


def check_input(argv, fonts):
    valid_flags = ["-f", "--font"]
    # Check if there are 0 or 2 arguments
    # Exit with message 'Invalid usag' if not
    if not (len(argv) == 1 or len(argv) == 3):
        sys.exit("Invalid usage")
    # Check if there are 2 arguments
    if len(argv) == 3:
        # If first argument is not -f or --font
        # or second isn't valid font
        # exit with message 'Invalid usage'
        if not (argv[1] in valid_flags and argv[2] in fonts):
            sys.exit("Invalid usage")
        # Return name of the font
        else:
            return argv[2]
    # If there are 0 arguments, return random font
    else:
        return random.choice(fonts)


def main():
    figlet = Figlet()
    # Check if args are valid, and return font
    f = check_input(sys.argv, figlet.getFonts())
    # Set font
    figlet.setFont(font=f)
    # Prompt user for input
    text = input("Input: ")
    # Print inputed text
    print(figlet.renderText(text))


if __name__ == "__main__":
    main()
