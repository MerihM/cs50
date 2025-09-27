import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    pattern = r".+ src=\"([^\"]+)(.+)"
    get_src = re.search(pattern, s)
    url = "None"
    if get_src:
        return get_url(get_src.group(1))
    return url


def get_url(s):
    pattern = r"(?:https?:\/\/)?(?:www\.)?youtube\.com\/embed\/(.{11})(?:.+)*"
    url = re.search(pattern, s)
    sh_url = "None"
    if url:
        sh_url = f"https://youtu.be/{url.group(1)}"
        return sh_url
    return sh_url


if __name__ == "__main__":
    main()
