-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Get all of the descriptions from crime scene at Humphrey Street, on 2024-07-28, day of theft
SELECT description FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2024
AND street = "Humphrey Street"
;

-- Get all the transcripts from day of theft, which mention bakery
SELECT name, transcript FROM interviews
WHERE year = 2024
AND month = 7
AND day >= 28
AND transcript LIKE "%bakery%";

-- Get all licence plates from bakery parking lot within 10 minutes of theft
SELECT * FROM bakery_security_logs
WHERE year = 2024
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <= 25;

-- Get all bank account numbers of people that withdrew money on Leggett Street atm, morning of the theft
SELECT * FROM atm_transactions
WHERE year = 2024
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

-- Get phone numbers of people that made call on the day of the theft, that lasted less than minute
SELECT * FROM phone_calls
WHERE year = 2024
AND month = 7
AND day = 28
AND duration < 60;

-- Get flights from Fiftyville morning after theft
SELECT * FROM flights
WHERE origin_airport_id IN (
    SELECT id FROM airports
    WHERE city = "Fiftyville"
    AND year = 2024
    AND month = 7
    AND day = 29
    AND hour < 12
)
ORDER BY hour
LIMIT 1;

-- Get list of passangers on flight from Fiftyville morning after theft
SELECT * FROM passengers
WHERE flight_id IN (
    SELECT id FROM flights
    WHERE origin_airport_id IN (
        SELECT id FROM airports
        WHERE city = "Fiftyville"
        AND year = 2024
        AND month = 7
        AND day = 29
        AND hour < 12
    )
);

-- Get name of the thief based on previous data
SELECT * FROM people
WHERE phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
)
AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
)
AND id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE year = 2024
        AND month = 7
        AND day = 28
        AND atm_location = "Leggett Street"
        AND transaction_type = "withdraw"
    )
)
AND passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id IN (
        SELECT id FROM flights
        WHERE origin_airport_id IN (
            SELECT id FROM airports
            WHERE city = "Fiftyville"
        )
        AND year = 2024
        AND month = 7
        AND day = 29
        AND hour < 12
    )
);

-- Get location flight is headed
SELECT * FROM airports
WHERE id IN (
    SELECT destination_airport_id FROM flights
    WHERE origin_airport_id IN (
        SELECT id FROM airports
        WHERE city = "Fiftyville"
        AND year = 2024
        AND month = 7
        AND day = 29
        AND hour < 12
    )
    ORDER BY hour
    LIMIT 1
);

-- Get name of accomplice
SELECT * FROM people
WHERE phone_number IN (
    SELECT receiver FROM phone_calls
    WHERE caller IN (
        SELECT phone_number FROM people
        WHERE phone_number IN (
            SELECT caller FROM phone_calls
            WHERE year = 2024
            AND month = 7
            AND day = 28
            AND duration < 60
        )
        AND license_plate IN (
            SELECT license_plate FROM bakery_security_logs
            WHERE year = 2024
            AND month = 7
            AND day = 28
            AND hour = 10
            AND minute >= 15
            AND minute <= 25
        )
        AND id IN (
            SELECT person_id FROM bank_accounts
            WHERE account_number IN (
                SELECT account_number FROM atm_transactions
                WHERE year = 2024
                AND month = 7
                AND day = 28
                AND atm_location = "Leggett Street"
                AND transaction_type = "withdraw"
            )
        )
        AND passport_number IN (
            SELECT passport_number FROM passengers
            WHERE flight_id IN (
                SELECT id FROM flights
                WHERE origin_airport_id IN (
                    SELECT id FROM airports
                    WHERE city = "Fiftyville"
                )
                AND year = 2024
                AND month = 7
                AND day = 29
                AND hour < 12
            )
        )
    )
    AND year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
)

