import sys
import os

args = ["lines.py", "hello.py", "goodbye.py", "not_python.cpp"]


def main():
    if check_args(sys.argv):
        print(f"{get_line_numbers(sys.argv[1])}")


def get_line_numbers(path):
    line_num = 0
    with open(path, "r") as file:
        lines = file.readlines()
        for line in lines:
            if not (line.lstrip().startswith("#") or line.strip() == ""):
                line_num += 1
    return line_num


def check_args(args):
    if len(args) <= 1:
        sys.exit("Too few command-line arguments")
    elif len(args) > 2:
        sys.exit("Too many command-line arguments")
    elif not args[1].endswith(".py"):
        sys.exit("Not a Python file")
    elif not os.path.isfile(f"./{args[1]}"):
        sys.exit("File does not exist")
    return True


if __name__ == "__main__":
    main()
