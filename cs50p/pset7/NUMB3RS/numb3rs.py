import re
import sys


def main():
    print(validate(input("IPv4 Address: ")))


def validate(ip):
    # Octate pattern, if there are two digits, digits can be any number from 0 to 9
    # If there are three digits first digit can be between 0 and 2
    # If first digit of three digit octet is 2, then second and third digits are between 0-5
    # If first digit of three digit octet is 0-1, then second and third are between 0-9
    # Group has to appear only once
    octet_pattern = r"((\d?\d){1}|(([2](([0-4]\d)|(5[0-5])))|([0-1]\d\d)){1})"
    # Pattern for IPv4, first three octets end with dot, while last one doesn't have dot at the end
    pattern = "^(" + octet_pattern + r"\.){3}" + octet_pattern + "{1}$"
    if re.search(pattern, ip):
        return True
    return False


if __name__ == "__main__":
    main()
