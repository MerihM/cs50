def main():
    while True:
        fraction = input('Fraction: ').split('/')
        # Check input
        try:
            # Set x and y to first and second number
            # Raise ValueError exception if either is not int
            x = int(fraction[0])
            y = int(fraction[1])
            # Check if x is less than y, if not raise Exception
            if y < x:
                raise Exception()
            # Round division to first two decimal digits
            frac = round(float(x / y), 2)
        except ValueError:
            # Print out error and prompt user for new input
            print('Values should be of type integer')
        except ZeroDivisionError:
            # Pass and prompt user for new input
            pass
        except Exception:
            # Pass and prompt user for new input
            pass
        else:
            # Find percentage, and print how much fuel is left
            percentage = int(100 * frac)
            if (percentage <= 1):
                print('E')
            elif (percentage >= 99):
                print('F')
            else:
                print(f"{percentage}%")
            break


if __name__ == '__main__':
    main()
