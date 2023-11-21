# Credit Card Validator
This program is a simple credit card number validator that determines whether a given credit card number is valid and, if so, identifies the type of card (American Express, Visa, or MasterCard). The validation is done using [Luhn's Algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm).

It is made for [Harvard University’s CS50 course](https://cs50.harvard.edu/x/2023/) [week 1 Problem Set 1](https://cs50.harvard.edu/x/2023/psets/1/credit/) in 2023.

## Features
* Validates credit card numbers based on their length and Luhn's Algorithm.
* Identifies the type of credit card (American Express, Visa, or MasterCard).

## Credit Card Types
* American Express: 15-digit numbers starting with 34 or 37.
* Visa: 13- or 16-digit numbers starting with 4.
* MasterCard: 16-digit numbers starting with 51 through 55.

## Usage
```bash
make
./credit
Number: [Enter the credit card number]
```

## Examples
```bash
Number: 378282246310005
AMEX

Number: 4111111111111111
VISA

Number: 5555555555554444
MASTERCARD

Number: 1234567890123
INVALID
```
