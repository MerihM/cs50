def convert(text):
    words = text.split()
    emojis = [':(', ':)']
    for index, word in enumerate(words):
        if (word in emojis):
            words.remove(word)
            if (word == ":("):
                words.insert(index, '\N{slightly frowning face}')
            else:
                words.insert(index, '\N{slightly smiling face}')
    return ' '.join(words)


def main():
    some_text = input('')
    print(convert(some_text))


main()
