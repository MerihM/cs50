def main():
    coke = 50
    while True:
        coin = int(input('Insert Coin: '))
        if coin in [25, 10, 5]:
            coke -= coin
            if coke > 0:
                print(f'Amount Due: {coke}')
            else:
                print(f'Change Owed: {abs(coke)}')
                break
        else:
            print(f'Amount Due: {coke}')


if __name__ == '__main__':
    main()
