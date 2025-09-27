import os
import sys
import csv


def main():
    if check_args(sys.argv):
        with open(f"{sys.argv[1]}", "r") as read, open(f"{sys.argv[2]}", "w") as write:
            reader = csv.DictReader(read)
            writer = csv.DictWriter(write, fieldnames=["first", "last", "house"])
            writer.writeheader()
            for row in reader:
                last, first = row["name"].split(",")
                cleaned = {
                    "first": (first.strip()),
                    "last": last,
                    "house": row["house"],
                }
                writer.writerow(cleaned)


def check_args(args):
    if len(args) < 3:
        sys.exit("Too few command-line arguments")
    elif len(args) > 3:
        sys.exit("Too many command-line arguments")
    elif not (args[1].endswith(".csv") and args[2].endswith(".csv")):
        sys.exit("Arguments should be CSV files")
    elif not os.path.isfile(f"./{args[1]}"):
        sys.exit(f"Could not read {args[1]}")
    return True


if __name__ == "__main__":
    main()
