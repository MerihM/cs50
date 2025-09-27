import sys
import os
from PIL import Image, ImageOps


def main():
    if check_args(sys.argv):
        image = Image.open(sys.argv[1])
        shirt = Image.open("shirt.png")
        size_shirt = shirt.size
        image = ImageOps.fit(image, size_shirt)
        image.paste(shirt, box=(0, 0), mask=shirt)
        image.save(sys.argv[2], mask=None)


def check_args(args):
    if len(args) < 3:
        sys.exit("Too few command-line arguments")
    elif len(args) > 3:
        sys.exit("Too many command-line arguments")
    ext_first = get_extension(args[1])
    ext_second = get_extension(args[2])
    valid_extensions = [".jpeg", ".png", ".jpg"]
    if not (ext_first in valid_extensions):
        sys.exit("Invalid input")
    elif not (ext_second in valid_extensions):
        sys.exit("Invalid output")
    elif ext_first != ext_second:
        sys.exit("Input and output have different extensions")
    elif not os.path.isfile(f"./{args[1]}"):
        sys.exit("Input does not exist")
    return True


def get_extension(path):
    filename, file_extension = os.path.splitext(path)
    return file_extension.lower()


if __name__ == "__main__":
    main()
