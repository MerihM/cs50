def main():
    x, y, z = input('Expression: ').split(' ')
    match y:
        case '+':
            print(round(float(x) + int(z), 1))
        case '-':
            print(round(float(x) - int(z), 1))
        case '*':
            print(round(float(x) * int(z), 1))
        case '/':
            print(round(float(x) / int(z), 1))


main()
