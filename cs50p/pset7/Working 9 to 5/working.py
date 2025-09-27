import re
import sys


def main():
    print(convert(input("Hours: ")))


def check_correct_time(h, m=0):
    return (h < 0 or h > 12) or (m < 0 or m > 59)


def get_formatted_string(curr_time, addition=0):
    if len((curr_time)) == 1:
        if curr_time[0] == "12":
            return f"{(0 + addition):02}:00"
        else:
            return f"{(int(curr_time[0]) + addition):02}:00"
    else:
        if curr_time[0] == "12":
            return f"{(0 + addition):02}:{curr_time[1]:02}"
        else:
            return f"{(int(curr_time[0]) + addition):02}:{curr_time[1]:02}"


def get_iso_8601(c_time, c_ampm):
    if c_ampm.lower() == "am":
        return get_formatted_string(c_time)
    else:
        return get_formatted_string(c_time, 12)


def get_hours(s):
    hours = []
    if len(s) > 2:
        hours = s.split(":")
        if check_correct_time(int(hours[0]), int(hours[1])):
            raise ValueError
    else:
        hours.append(s)
        if check_correct_time(int(s)):
            raise ValueError
    return hours


def convert(s):
    pattern = r"^(\d\d?:?(?:\d\d)?) (AM|PM) to (\d\d?:?(?:\d\d)?) (AM|PM)$"
    val = re.search(pattern, s, re.IGNORECASE)
    if not val:
        raise ValueError
    hours = val.groups()
    from_hours = get_hours(hours[0])
    to_hours = get_hours(hours[2])
    # print(from_hours)
    # print(to_hours)
    new_time = (
        f"{get_iso_8601(from_hours, hours[1])} to {get_iso_8601(to_hours, hours[3])}"
    )
    return new_time


if __name__ == "__main__":
    main()
