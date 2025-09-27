from jar import Jar
import pytest


def main(): ...


def test_init():
    cookie = Jar()
    assert cookie.size == 0
    assert cookie.capacity == 12


def test_str():
    cookie = Jar()
    cookie.deposit(1)
    assert str(cookie) == "🍪"
    cookie.deposit(3)
    assert str(cookie) == "🍪🍪🍪🍪"


def test_deposit():
    cookie = Jar()
    cookie.deposit(1)
    assert cookie.size == 1
    cookie.deposit(1)
    assert cookie.size == 2


def test_deposit_fail():
    cookie = Jar()
    with pytest.raises(ValueError):
        cookie.deposit(20)


def test_withdraw():
    cookie = Jar()
    cookie.deposit(10)
    cookie.withdraw(1)
    assert cookie.size == 9
    cookie.withdraw(5)
    assert cookie.size == 4


def test_withdraw_fail():
    cookie = Jar()
    with pytest.raises(ValueError):
        cookie.withdraw(20)


if __name__ == "__main__":
    main()
