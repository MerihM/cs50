from numb3rs import validate


def main(): ...


ip_list = [
    "1.2.3.4",
    "22.22.22.22",
    "192.168.100.100",
    "1.2.3.1000",
    "1234.2.3.100",
    "0.0.0.0",
    "255.255.255.255",
    "295.255.255.0",
    "512.512.512.512",
    "222",
    "222.2",
    "222.2.3",
    "11.22.33.44",
    "1.22.333.444.5",
    "127.0.0.1",
    "255.255.255.0",
    "cat",
    "cat.dog.cow.rat",
    " . . . ",
    "...",
    "252.22.22.22",
    "256.1.1.1",
    "255.256.1.1",
    "255.1.256.1",
    "255.1.1.256",
]


# Check that each octet has at most three digits
def test_number_of_digits():
    assert validate(ip_list[0]) == True
    assert validate(ip_list[1]) == True
    assert validate(ip_list[2]) == True


# Check if any octet has more than three digits
def test_wrong_number_of_digits():
    assert validate(ip_list[3]) == False
    assert validate(ip_list[4]) == False


# Check if octets are in correct range
def test_digit_range():
    assert validate(ip_list[5]) == True
    assert validate(ip_list[6]) == True
    assert validate(ip_list[7]) == False
    assert validate(ip_list[8]) == False


# Check if there are exactly 4 octets
def test_octets():
    assert validate(ip_list[9]) == False
    assert validate(ip_list[10]) == False
    assert validate(ip_list[11]) == False
    assert validate(ip_list[12]) == True
    assert validate(ip_list[13]) == False


# Check if valid ip returns true
def test_correct():
    assert validate(ip_list[14]) == True
    assert validate(ip_list[15]) == True


# Check if ip is only digits
def test_non_digits():
    assert validate(ip_list[16]) == False
    assert validate(ip_list[17]) == False


# Check if octets are empty
def test_empty_octet():
    assert validate(ip_list[18]) == False
    assert validate(ip_list[19]) == False


# Check if first octet is in range
def test_first_in_range():
    assert validate(ip_list[20]) == True
    assert validate(ip_list[21]) == False
    assert validate(ip_list[22]) == False
    assert validate(ip_list[23]) == False
    assert validate(ip_list[24]) == False


if __name__ == "__main__":
    main()
