def main():
    answer = input('What is the Answer to the Great Question of Life, the Universe, and Everything? ')
    legal_answers = ['42', 'forty-two', 'forty two']
    if answer.strip().lower() in legal_answers:
        print('Yes')
    else:
        print('No')


main()
