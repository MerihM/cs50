from datetime import date, datetime
import sys
import inflect


class Seasons:
    def __init__(self, d_o_b):
        self.d_o_b = d_o_b
        self.today = date.today()
        self.between = abs((self.today - self.d_o_b).days)

    def __str__(self):
        return f"{self.get_minutes().capitalize()} minutes"

    @property
    def d_o_b(self):
        return self._d_o_b

    @d_o_b.setter
    def d_o_b(self, d_o_b):
        try:
            d_o_b = datetime.strptime(d_o_b, "%Y-%m-%d").date()
        except ValueError:
            sys.exit("Invalid date")
        else:
            self._d_o_b = d_o_b

    def get_minutes(self):
        p = inflect.engine()
        minutes = self.between * 24 * 60
        return p.number_to_words(minutes, andword="")


def main():
    d1 = input("Date of Birth: ")
    s = Seasons(d1)
    print(s)


if __name__ == "__main__":
    main()
