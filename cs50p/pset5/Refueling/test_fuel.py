from fuel import convert, gauge
import pytest

# Check labeling 99% as F in gauge


# Check incorrect ints in convert
def test_integer():
    assert convert("1/2") == 50
    assert convert("1/3") == 33
    assert convert("10/100") == 10


# Check raising ValueError in convert
def test_value_error():
    # Cat/dog
    with pytest.raises(ValueError):
        convert("cat/dog")
    # i/2
    with pytest.raises(ValueError):
        convert("i/2")
    # 2/i
    with pytest.raises(ValueError):
        convert("2/i")


# Check raising ZeroDivisionError in convert
def test_zero_division_error():
    with pytest.raises(ZeroDivisionError):
        convert("1/0")
    with pytest.raises(ZeroDivisionError):
        convert("2/0")
    with pytest.raises(ZeroDivisionError):
        convert("1000/0")


# Check labeling 1% as E in gauge
def test_empty_gauge():
    assert gauge(1) == "E"
    assert gauge(0) == "E"


def test_full_gauge():
    assert gauge(99) == "F"
    assert gauge(100) == "F"


def test_percentage_gauge():
    assert gauge(37) == "37%"
    assert gauge(50) == "50%"


def main(): ...


if __name__ == "__main__":
    main()
