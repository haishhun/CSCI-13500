# Program Design Document

## Program Name

GPA Calculator

## Purpose

The program helps users calculate their semester GPA by entering course credits and letter grades. It validates user input, converts letter grades into grade points, and calculates the final GPA.

---

## Inputs

The program accepts following user inputs:

* input_grade - course credits and letter grade entered in the format <credits><letter grade>.
* continue_option - user's choice to continue entering grades or calculate GPA.

---

## Outputs

The program displays following outputs:

* Number of classes entered.
* Final semester GPA.
* Error messages for invalid input.

---

## Variables

| Variable            | Type   | Purpose                          |
| ------------------- | ------ | -------------------------------- |
| input_grade         | string | Stores the user's grade input    |
| input_credits       | int    | Stores the credit value          |
| input_letter_grade  | string | Stores the letter grade          |
| total_classes       | int    | Stores number of classes entered |
| total_credits       | double | Stores total credits             |
| total_credit_points | double | Stores total credit points       |
| grade_points        | double | Stores grade point value         |
| gpa                 | double | Stores calculated GPA            |
| continue_option     | char   | Stores continuation choice       |

---

## Key Design Choices

* I used string type for input_grade because we are getting both credits and letter grades in a single input.
* I used ASCII value comparison to validate that the number of credits is between 1 and 9.
* I used a loop and ASCII value conversion to convert lowercase grades into uppercase.
* I chose if-else condition over switch-case because switch-case doesn't work with strings, it works with chars and our grades are strings.
* I used std::fixed and std::setprecision(2) to display the GPA with two digits after the decimal point.

---

## Program Steps (Algorithm)

1. Display instructions to the user.
2. Ask the user to enter a grade.
3. Validate the input length.
4. Validate the credit value.
5. Separate credits from the letter grade.
6. Convert the letter grade to uppercase.
7. Convert the letter grade into grade points.
8. Update total credits and total credit points.
9. Ask the user whether he wants to continue.
10. If the user enters Y, repeat the process.
11. If the user enters anything else, calculate the GPA.
12. Display the number of classes and final GPA.

---

## Functions

No separate functions were used in the program.

---

## Sample Input/Output

Input:
Please enter your grade: 3A
Enter Y to add another grade. Any other key to exit.: N

Output:
Classes taken: 1, Semester GPA: 4.00

---

## Testing

### Test Case 1

Input:
3A
N

Expected Result:
Classes taken: 1, Semester GPA: 4.00

### Test Case 2

Input:
4A-
N

Expected Result:
Classes taken: 1, Semester GPA: 3.70

### Test Case 3

Input:
3A
Y
4B+
N

Expected Result:
Classes taken: 2, Semester GPA: 3.60

### Test Case 4

Input:
3F
N

Expected Result:
Classes taken: 1, Semester GPA: 0.00

### Test Case 5

Input:
0A

Expected Result:
Error: Invalid grade input. Please enter again.

### Test Case 6

Input:
10A

Expected Result:
Error: Invalid grade input. Please enter again.

### Test Case 7

Input:
3Z

Expected Result:
Error: Invalid grade input. Please enter again.

### Test Case 8

Input:
abc

Expected Result:
Error: Invalid grade input. Please enter again.

### Test Case 9

Input:
3a
N

Expected Result:
Classes taken: 1, Semester GPA: 4.00

### Test Case 10

Input:
No valid grades entered

Expected Result:
Error: No valid grades entered.

### Test Case 11
    
Input:
1000A+

Expected Result:
Error: Invalid grade input. Please enter again.

### Test Case 12
Input:
1

Expected Result:
Error: Invalid grade input. Please enter again.

### Test Case 13

Input:
3fab
N

Expected Result:
Classes taken: 1, Semester GPA: 0.00

### Test Case 14

Input:
3wu
N

Expected Result:
Classes taken: 1, Semester GPA: 0.00