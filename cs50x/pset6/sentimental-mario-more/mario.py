from cs50 import get_int


def main():
    # get height between 1 and 8, inclusive
    while True:
        height = get_int("Height: ")
        if (0 < height < 9):
            break
    # print spaces, than # symbols, followed by two spaces and # symbols
    for i in range(height):
        print(" "*(height-(i + 1)), end="")
        print("#"*(i+1), end="  ")
        print("#"*(i+1))
    return


main()
