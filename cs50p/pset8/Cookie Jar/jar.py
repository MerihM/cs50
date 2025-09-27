class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        total = self.size + n
        if total > self.capacity:
            raise ValueError
        else:
            self.size = total

    def withdraw(self, n):
        total = self.size - n
        if total < 0:
            raise ValueError
        else:
            self.size = total

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        self._capacity = capacity

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, size):
        self._size = size


def main():
    cookies = Jar()
    cookies.deposit(5)
    print(cookies)
    cookies.withdraw(3)
    print(cookies)


if __name__ == "__main__":
    main()
