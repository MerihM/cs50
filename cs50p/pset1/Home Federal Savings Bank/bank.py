def main():
    greeting = input('Greeting: ').strip().lower()
    if (greeting[0] == 'h'):
        if ('hello' in greeting):
            print('$0')
        else:
            print('$20')
    else:
        print('$100')


main()
