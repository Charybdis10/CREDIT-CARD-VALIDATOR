# Credit Card Validator

This simple C program is designed to validate credit card numbers based on the Luhn's algorithm and identify the card type (AMEX, VISA, MASTERCARD, or INVALID). The program takes a credit card number as input and performs checks to verify its validity and type.

## Usage

To use the credit card validator, compile the code and run the executable. The program will prompt you to enter a credit card number. Follow the on-screen instructions, and the program will output whether the card is valid and its type.

```bash
gcc credit_card_validator.c -o credit_card_validator
./credit_card_validator
```

## Input

The program expects a valid credit card number as input. The user will be prompted to enter the card number when running the program.

## Output

The program outputs the result of the credit card validation process, indicating whether the card is valid and its type (AMEX, VISA, MASTERCARD, or INVALID).

## Functions

### `altsecondlastdigit`

This function calculates the sum of the digits obtained by doubling every other digit, starting from the second-to-last digit, and adds the remaining digits unchanged. It is a helper function used in the validation process.

### `AMEX`, `VISA`, `MASTERCARD`

These functions check whether the given credit card number matches the criteria for being an American Express (AMEX), VISA, or MASTERCARD, respectively. They return `1` if the criteria are met and `0` otherwise.

## Notes

- The program uses the Luhn's algorithm for credit card validation.
- It provides support for AMEX, VISA, and MASTERCARD card types.
- If the input card number is valid, the program will output the card type; otherwise, it will output "INVALID."

Feel free to use and modify the code as needed for your projects. If you encounter any issues or have suggestions for improvement, please let us know.
