def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")


def dollars_to_float(d):
    d_n = d.replace("$", '')
    return round(float(d_n), 1)


def percent_to_float(p):
    p_n = p.replace("%", '')
    return (round(float(p_n)/100, 2))


main()
