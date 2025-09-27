import inflect
import sys


def main():
    names = []
    # Prompt user for names until ctrl+d
    while True:
        try:
            names.append(input("Name: ").strip())
        except EOFError:
            break
        except KeyboardInterrupt:
            print()
            sys.exit("Bye :(")
    # Initialize inflect
    p = inflect.engine()
    # Print out message with oxford comma
    print(f"Adieu, adieu, to {p.join(names, conj='and')}")


if __name__ == "__main__":
    main()
