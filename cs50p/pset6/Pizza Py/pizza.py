import sys
import os
import csv
from tabulate import tabulate


def main():
    if is_correct_file(sys.argv):
        data = get_csv_data(sys.argv[1])
    print(tabulate(data, headers="firstrow", tablefmt="grid"))


def is_correct_file(args):
    # Check if there are args
    if len(args) <= 1:
        sys.exit("Too few command-line arguments")
    # Check if there is only one arg
    elif len(args) > 2:
        sys.exit("Too many command-line arguments")
    # Check that it's CSV file
    elif not args[1].endswith(".csv"):
        sys.exit("Not a CSV file")
    # Check that file exists
    elif not os.path.isfile(f"./{args[1]}"):
        sys.exit("File does not exist")
    # Return True
    return True


def get_csv_data(path):
    data = []
    # Read data from path parameter
    with open(path) as file:
        # Parse file as CSV
        reader = csv.reader(file)
        # Append each row to data list
        for row in reader:
            data.append(row)
    # Return list
    return data


if __name__ == "__main__":
    main()
