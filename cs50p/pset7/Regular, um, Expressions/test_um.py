from um import count


def main(): ...


def test_input():
    assert count("Um, hello, um, world") == 2
    assert count("um") == 1
    assert count("Um, pls finish this album...") == 1
    assert count("yummy") == 0
    assert count("Um!") == 1


if __name__ == "__main__":
    main()
