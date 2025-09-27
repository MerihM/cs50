def main():

    grocery_list = dict()
    while True:
        try:
            item = input().upper()
        # Check for ctrl+d press, and print out list
        except EOFError:
            for i in sorted(grocery_list.keys()):
                print(f'{grocery_list[i]} {i}')
            return
        # If not ctrl+d, add item to list
        else:
            grocery_list[item] = grocery_list.get(item, 0) + 1


if __name__ == '__main__':
    main()
