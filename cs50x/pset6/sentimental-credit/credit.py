from cs50 import get_string
import re

valid_length = [13, 15, 16]


def luhn(card_number):
    digits_num = len(card_number)
    sum = 0
    is_second = False

    # checks from last digit
    for i in range(digits_num - 1, -1, -1):
        new = int(card_number[i])
        if (is_second == True):
            new = new * 2
        # add two digits to handle case that makes two digits after doubling
        sum += new // 10
        sum += new % 10

        is_second = not is_second
    # returns true only if luhn number
    if (sum % 10 == 0):
        return True
    return False

# function to check if input is digits


def check_input(num):
    # find all non digits in input
    non_digits = re.findall(r"\D", num)
    # returns true if all digits, and is valid credit card number length
    return (not len(non_digits) and (len(num) in valid_length))

# function to check credit card company


def card_company(num):
    num_len = len(num)
    # if length is 15, credit card company is amex
    if (num_len == 15):
        # if first digit is not three, it's invalid
        if (int(num[0]) == 3):
            # if second digit isn't 4 or 7, it's invalid
            if (int(num[1]) in [4, 7]):
                print("AMEX")
                return
    # if length is 13 or 16, credit card company is visa or mastercard
    elif (num_len in [13, 16]):
        # if first digit is 4, it's visa
        if (int(num[0]) == 4):
            print("VISA")
            return
        # if first digit is 5, and second is between 1 and 5, inclusive, company is mastercard
        elif (int(num[0]) == 5):
            if (int(num[1]) in range(1, 6)):
                print("MASTERCARD")
                return
    # print invalid if all checks fail
    print("INVALID")


def main():

    card_num = get_string("Number: ")
    if (check_input(card_num) and luhn(card_num)):
        card_company(card_num)
    else:
        print("INVALID")
    return


main()
