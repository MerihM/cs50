from scourgify import check_args
import pytest


def main(): ...


args = ["scourgify.py", "before.csv", "after.csv", "invalid_csv.csv"]


# Checks for too few CL arguments
def test_too_few_args():
    with pytest.raises(SystemExit) as sample:
        check_args(args[0:2])
    assert sample.type == SystemExit
    assert sample.value.code == "Too few command-line arguments"


# Checks for too many CL arguments
def test_too_many_args():
    with pytest.raises(SystemExit) as sample:
        check_args(args)
    assert sample.type == SystemExit
    assert sample.value.code == "Too many command-line arguments"


# Check if CSV file
def test_not_python():
    with pytest.raises(SystemExit) as sample:
        check_args([args[0], args[1], 'invalid.cpp'])
    assert sample.type == SystemExit
    assert sample.value.code == "Arguments should be CSV files"


# Check if file doesn't exist
def test_file_doesnt_exist():
    with pytest.raises(SystemExit) as sample:
        check_args([args[0], args[2], args[3]])
    assert sample.type == SystemExit
    assert sample.value.code == f"Could not read {args[2]}"


# Test correct input
def test_correct():
    assert check_args(args[0:3]) == True


if __name__ == "__main__":
    main()
