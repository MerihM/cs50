from bank import value


def main(): ...


# Check if value returns correct int


def test_correct_input():
    assert value("hello") == 0
    assert value("hey") == 20
    assert value("sup") == 100


# Check different cases return correct int


def test_case_sensitivity():
    assert value("Hello") == 0
    assert value("Hey") == 20
    assert value("Sup") == 100


# Check if phrases return correct int


def check_phrases():
    assert value("Hello there") == 0
    assert value("Hey there") == 20
    assert value("What's up") == 100


if __name__ == "__main__":
    main()
