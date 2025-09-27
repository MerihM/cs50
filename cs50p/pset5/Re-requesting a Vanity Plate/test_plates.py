from plates import is_valid


def main(): ...


# Check if beginnig is alphabetical
# Check starting with number
def test_beginning():
    assert is_valid("CS50") == True
    assert is_valid("C500") == False
    assert is_valid("50CS") == False


# Check if correct length
def test_length():
    assert is_valid("HELLO") == True
    assert is_valid("A") == False
    assert is_valid("SOMELONGSTRING") == False


# Check placement of numbers
def test_numbers():
    assert is_valid("C50S") == False
    assert is_valid("5CS0") == False
    assert is_valid("CS50") == True
    assert is_valid("CS504") == True
    assert is_valid("HEL999") == True
    assert is_valid("HE9999") == True
    assert is_valid("HE99O") == False


# Check placement of zero
def test_zero():
    assert is_valid("CS05") == False
    assert is_valid("HEL04") == False
    assert is_valid("HEL40") == True
    assert is_valid("CS50") == True


# Check all alphanumeric
def test_alphanum():
    assert is_valid("CS!50") == False
    assert is_valid("CS50") == True


if __name__ == "__main__":
    main()
