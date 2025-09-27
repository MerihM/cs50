def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if not (2 < len(s) <= 6):
        return False
    if not s.isalnum():
        return False
    if not (s[0].isalpha() and s[1].isalpha()):
        return False

    is_prev_num = False

    for l in s:
        if l.isdigit():
            if l == '0' and not is_prev_num:
                return False
            else:
                is_prev_num = True
        elif is_prev_num:
            return False
    return True


if __name__ == '__main__':
    main()
