from cs50 import get_float


def main():

    while True:
        cash = get_float("Change: ")
        if cash <= 0:
            continue
        break
    change = 0
    while (cash > 0):
        if (cash >= 0.25):
            cash -= 0.25
        elif (cash >= 0.1):
            cash -= 0.1
        elif (cash >= 0.05):
            cash -= 0.05
        else:
            cash -= 0.01
        cash = round(cash, 2)
        change += 1
    print(f"{change}")


main()
