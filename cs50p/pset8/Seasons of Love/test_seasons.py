import seasons
import pytest


def main(): ...


def test_days_between():
    s = seasons.Seasons("2025-6-2")
    assert s.between == 1


def test_no_days_between():
    s = seasons.Seasons("2025-6-3")
    assert s.between == 0


def test_one_day():
    s = seasons.Seasons("2025-6-2")
    assert s.get_minutes() == "one thousand, four hundred forty"


def test_one_year():
    s = seasons.Seasons("2024-6-3")
    assert s.get_minutes() == "five hundred twenty-five thousand, six hundred"


if __name__ == "__main__":
    main()
