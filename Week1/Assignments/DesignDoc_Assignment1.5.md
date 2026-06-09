# Program Design Document

## Program Name

Basic Calculator

## Purpose

The program helps users perform basic arithmetic operations such as Addition (+), Subtraction (-), Multiplication (*, x), Division (/) and Modulo (%) operations.

---

## Inputs

The program accepts following user inputs:
* first_number - the first number used in calculation.
* second_number - the second number used in calculation.
* operation - operation to perform (+, -, *, x, /, %).
* exit_choice - user's choice to continue or exit the program.


---

## Outputs

* Calculation result
* Continuation request

---

## Variables

| Variable      | Type   | Purpose                    |
| ------------- | ------ | -------------------------- |
| first_number  | double | Stores first number        |
| second_number | double | Stores second number       |
| operation     | char   | Stores operation type      |
| result        | double | Stores calculation result  |
| exit_choice   | char   | Stores continuation choice |

---

## Key Design Choices

I used the double data type for first_number, second_number, and result to support decimal numbers and accurate division results. But, I had to rewrite the modulo calculation manually because the modulo operator does not work with decimal numbers.

I used a while loop to keep the program running until the user chooses to exit.

I chose a switch statement instead of if-else because it is easier to extend the program in the future.

---

## Program Steps (Algorithm)

1. Ask the user to enter the first number.
2. Validate the first number input.
3. Ask the user to enter the second number.
4. Validate the second number input.
5. Ask the user to choose an operation.
6. Perform the selected operation.
7. Display the result.
8. Ask the user whether he wants to continue.
9. If the user enters Y, repeat the process.
10. If the user enters anything else, end the program.

---

## Functions

No separate functions were used in the program.

## Sample Input/Output

Input:
Enter first number: 10
Enter second number: 7
Choose operation (+, -, *, /, %): %
Would you like to continue? (Y/N): Y

Output:
Result: 3
Would you like to continue? (Y/N)

---

## Testing

### Test Case 1

Input: 5, 5, +

Expected Result: 10

### Test Case 2

Input: 5, 5, -

Expected Result: 0

### Test Case 3

Input: 5, 7, *

Expected Result: 35

### Test Case 4

Input: 5, 7, x

Expected Result: 35

### Test Case 5

Input: 5, 7, X

Expected Result: 35

### Test Case 6

Input: 20, 4, /

Expected Result: 5

### Test Case 7

Input: 10, 7, %

Expected Result: 3

### Test Case 8

Input: 5, 0, /

Expected Result: Error: Cannot divide by zero.

### Test Case 9

Input: 5, 0, %

Expected Result: Error: Cannot divide by zero.

### Test Case 10

Input: abc 

Expected Result: Error: Invalid data. Please enter a number.

### Test Case 11

Input: 10, abc 

Expected Result: Error: Invalid data. Please enter a number.

### Test Case 12

Input: 10, 5, abc

Expected Result: Error: Invalid data. Please enter again.
