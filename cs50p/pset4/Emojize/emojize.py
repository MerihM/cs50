import emoji


def main():
    in_emoji = input("Input: ").strip()
    print("Output: ", emoji.emojize(in_emoji, language="alias"))


if __name__ == "__main__":
    main()
