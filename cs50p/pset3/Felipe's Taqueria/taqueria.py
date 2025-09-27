def main():
    menu = {
        'Baja Taco': 4.25,
        'Burrito': 7.50,
        'Bowl': 8.50,
        'Nachos': 11.00,
        'Quesadilla': 8.50,
        'Super Burrito': 8.50,
        'Super Quesadilla': 9.50,
        'Taco': 3.00,
        'Tortilla Salad': 8.00
    }
    total = 0.00
    while True:
        # Check if input is in dictionary and check if ctrl+d pressed
        try:
            item = input("Item: ").title()
            total += round(menu[item], 2)
        # If ctrl+d pressed, end execution
        except EOFError:
            print('Item: ')
            break
        # If item not in dictionary, reprompt
        except KeyError:
            pass
        # Print total after each valid input
        else:
            print(f'Total: ${total:.2f}')


if __name__ == '__main__':
    main()
