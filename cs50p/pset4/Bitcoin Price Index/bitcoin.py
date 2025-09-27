import sys
import requests

api_key = "YOUR_API_KEY_GOES_HERE"
url = f"https://rest.coincap.io/v3/assets/bitcoin?apiKey={api_key}"


def main():
    try:
        if len(sys.argv) != 2:
            sys.exit("Missing command-line argument")
        num = float(sys.argv[1])
        r = requests.get(url).json()
    except requests.RequestException:
        print("Error")
        return
    except ValueError:
        sys.exit("Command-line argument is not a number")
    bitcoin_price = float(r["data"]["priceUsd"])
    print(f"${bitcoin_price * num:,.4f}")


if __name__ == "__main__":
    main()
