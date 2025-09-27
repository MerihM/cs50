from twttr import shorten

# Test uppercase and lowercase letters


def test_letter_case():
    assert shorten("twitter") == "twttr"
    assert shorten("TwitteR") == "TwttR"
    assert shorten("TWITTER") == "TWTTR"


# Test numbers


def test_numbers():
    assert shorten("1234") == "1234"
    assert shorten("12twitter34") == "12twttr34"


# Test punctuation


def test_punct():
    assert shorten("Hello.") == "Hll."
    assert shorten("Hello!") == "Hll!"
    assert shorten("Hello?") == "Hll?"
    assert shorten("Hello,") == "Hll,"
