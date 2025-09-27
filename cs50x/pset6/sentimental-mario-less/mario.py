from cs50 import get_int


def main():
    # check input to be between 1 and 8, inclusive
    while True:
        height = get_int("Height: ")
        if (1 <= height <= 8):
            break
    # print spaces, than # symbol
    for i in range(height):
        print(" "*(height-(i+1)), end="")
        print("#"*(i+1))


main()
