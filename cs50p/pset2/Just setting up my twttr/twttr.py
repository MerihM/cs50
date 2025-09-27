def main():
    str = input('Input: ')
    vowels = ['a', 'e', 'i', 'o', 'u']
    for l in str:
        tl = l.lower()
        print(tl)
        if tl in vowels:
            print(l)
            str = str.replace(l, "")
    print(f'Output: {str}')


if __name__ == '__main__':
    main()
