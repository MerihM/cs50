def main():
    camel_case = list(input('camelCase: '))
    for index, letter in enumerate(camel_case):
        if letter.isupper():
            camel_case.remove(letter)
            camel_case.insert(index, "_" + letter.lower())
    print(f"snake_case: {''.join(camel_case)}")


if __name__ == '__main__':
    main()
