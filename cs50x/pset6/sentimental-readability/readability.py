from cs50 import get_string

# function that returns grade level based on cli


def get_grade_level(cli):
    if cli in range(17):
        return ("Grade " + str(cli))
    elif cli > 16:
        return ("Grade 16+")
    else:
        return ("Before Grade 1")


def main():
    text = get_string("Text: ")
    # split text into list of words
    word_list = text.split()
    sentences_num = 0
    letter_num = 0

    # check each word
    for word in word_list:
        # if last char in word is ., !, or ? increment number of sentences
        if word[-1] in ['.', '!', '?']:
            sentences_num += 1
        # if last char is ' or ", and second to last is ., !, ? increment number of sentences
        if word[-1] in ['\'', '"']:
            if word[-2] in ['.', '!', '?']:
                sentences_num += 1
        # for each letter in word check if it's alphanumerical and increment number of letters
        for letter in word:
            if (letter.isalnum()):
                letter_num += 1
    # calculate average number of letters per 100 words in the text
    cli_l = (letter_num / len(word_list)) * 100.00
    # calculate average number of sentences per 100 words in the text
    cli_s = (sentences_num / len(word_list)) * 100.00
    # calculate coleman-liau index
    cli = round((0.0588 * cli_l - 0.296 * cli_s - 15.8))
    # print grade level
    print(get_grade_level(cli))


main()
