-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get passenger list of the particular flights
SELECT name FROM people
    JOIN passengers ON passengers.passport_number = people.passport_number
        WHERE passengers.flight_id = (SELECT id FROM flights
                                            WHERE origin_airport_id = 8 AND day = 29 AND month = 7 AND year = 2021
            ORDER BY hour,minute
                LIMIT 1);

-- Get people names by using phone number
SELECT name FROM people
    WHERE phone_number IN (SELECT caller FROM phone_calls
                                WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60);

-- Get people names by using account_number
SELECT name FROM people
    WHERE id IN (SELECT person_id FROM bank_accounts
                    WHERE account_number IN (SELECT account_number FROM atm_transactions
                                                WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"));

-- Get people names by using license plate
SELECT name FROM people
    WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
                                WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute <= 25 AND minute >= 15 AND activity = "exit");


-- Getting common names from the found four lists of suspects
-- We get THIEF is BRUCE.

-- Now we find the destination Bruce went to
SELECT city FROM airports
    WHERE id = (SELECT destination_airport_id FROM flights
                    WHERE id = (SELECT flight_id FROM passengers
                                    WHERE passport_number = (SELECT passport_number FROM people
                                                                WHERE name = "Bruce")));

-- Now the accomplice will be the person he called
SELECT name FROM people
    WHERE phone_number = (SELECT receiver FROM phone_calls
                            WHERE caller = (SELECT phone_number FROM people WHERE name = "Bruce") AND day = 28 AND month = 7 AND year = 2021 AND duration < 60);

