def pd(month, day, year):
    print(year, f'{month:02}', f'{day:02}', sep='-')


def main():
    month_list = [
        'January',
        'February',
        'March',
        'April',
        'May',
        'June',
        'July',
        'August',
        'September',
        'October',
        'November',
        'December'
    ]
    while True:
        try:
            date = input('Date: ').strip()
        except (EOFError, KeyboardInterrupt):
            print()
            return
        else:
            # Check if string contains /
            # If yes, split by /
            if '/' in date and date[0].isdigit():
                month, day, year = date.split('/')
                day = int(day)
                month = int(month)
                year = int(year)
                # Check if day and month are legal
                if 1 <= day <= 31 and 1 <= month <= 12:
                    pd(month, day, year)
                    return
                # Reprompt if not
                else:
                    continue

            # Else split by spaces
            elif not date[0].isdigit() and not '/' in date:
                month, day, year = date.split(' ')
                # If day doesn't end with comma, reprompt
                if day[-1] != ',':
                    continue
                # Remove comma from day
                else:
                    day = day.replace(',', '')
                day = int(day)
                year = int(year)
                month = month.capitalize()
                # Check if day and month are legal
                if month in month_list and 1 <= day <= 31:
                    month = (month_list.index(month)) + 1
                # Reprompt user
                else:
                    continue
                # Print yyyy-mm-dd
                pd(month, day, year)
                return
            else:
                continue


if __name__ == '__main__':
    main()
