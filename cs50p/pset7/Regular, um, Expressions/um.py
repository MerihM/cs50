import re
import sys


def main():
    print(count(input("Text: ")))


def count(s):
    pattern = r"(^|\W)um($|\W)"
    if val := re.findall(pattern, s, re.IGNORECASE):
        return len(val)
    else:
        return 0


if __name__ == "__main__":
    main()
