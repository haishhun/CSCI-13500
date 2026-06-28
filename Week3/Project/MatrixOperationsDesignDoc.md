# Program Design Document

## Program Name

Project 2

## Purpose

THe program implements matrix operations as different functions. It performs
six operations: printing a matrix, adding two matrices, transposing a matrix,
computing a determinant, searching for a value, and multiplying two matrices.

---
 
## Inputs
 
The program does not read from the user at runtime. Inputs are defined directly
in `main()` as test data and passed into each function as arguments.
 
* Two integer matrices (`testing_matrix_one` and `testing_matrix_two`)
* A target value to search for in `SearchValue`
* Row and Column amounts

---

## Outputs
 
* The computed row and column count of the first matrix
* A message of the function name around each operation
* The original matrix for `Print2DArray` and resulting matrices for other functions.
* The determinant value for `Determinant`
* The location for the target value for `SearchValue`
* An error message when a function receives an invalid dimension

---
 
## Variables
 
| Variable        | Type        | Purpose                                                        |
| --------------- | ----------- | -------------------------------------------------------------- |
| matrix_local    | array       | Input matrix.                                                  |
| new_matrix      | array       | Result matrix                                                  |
| determinant     | int         | Stores the computed determinant value                          |
| target          | int         | The target value `SearchValue` looks for                       |
| target_found    | bool        | Flag tracking whether the search target was located            |
| size_row_one    | int         | Row count of the first matrix                                  |
| size_col_one    | int         | Column count of the first matrix                               |
 
---
 
## Key Design Choices
 
* In `Print2DArray` and `SearchValue` I use the row count for both loops. The matrix is square, so the number of rows and columns is the same and one value is enough.

* In `TransposeMatrix` I added a `columns` value. To handle non-square matrices I would need to pass it as an argument, but even then I cannot write `new_matrix[row_amount]
[column_amount]`, because a raw array needs a number that is known at compile time.

* For the determinant I used the 2x2 and 3x3 formulas from the site in the specification. It was easier to write the two formulas directly than to make a full algorithm, because we only work with these two sizes.

* In `SearchValue` I used a boolean flag to remember if the target was found. If the flag is still false at the end, I print that the value was not found.

* `MatrixMultiplication` uses three nested loops. The two outer loops choose the result cell, and the inner loop goes through the pairs of numbers to make the dot product. This is why the complexity is O(n^3).

* In `main()` I added comment lines with the function names. This separates the functions and makes the output easier to read.

---
 
## Program Steps (Algorithm)
 
1. Declare two test matrices in `main()`.
2. Compute each matrix's row and column counts using `sizeof`.
3. Print the computed dimensions and a test banner.
4. Call each operation in turn, passing the test matrices and their sizes: `Print2DArray`, `MatrixAddition`, `TransposeMatrix`, `Determinant`, `SearchValue`, `MatrixMultiplication`.
5. Inside each function: print a start banner, validate dimensions, perform the
   operation, print the result, and print an end banner.


---
 
## Functions
 
### Function: Print2DArray(matrix, rows)
 
Purpose: Prints a square matrix row by row, with `|` between values and each row
wrapped in brackets.

### Function: MatrixAddition(matrix_one, rows_one, matrix_two, rows_two)
 
Purpose: Adds two matrices cell by cell into a result matrix and prints it.
Time complexity O(n^2).

### Function: TransposeMatrix(matrix, rows)
 
Purpose: Builds the transpose by swapping row and column indexes, then prints
the result. Column count is fixed at 3 in the current implementation.

### Function: Determinant(matrix, size)
 
Purpose: Computes the determinant of a 2x2 matrix directly, or a 3x3 matrix
using cofactor expansion along the first row, and prints the value.

### Function: SearchValue(matrix, rows, target)
 
Purpose: Scans every cell for the target value, printing the position of each
match. Prints a "not found" message if no match exists. Time complexity O(n^2).

### Function: MatrixMultiplication(matrix_a, matrix_b, rows_a, cols_a, rows_b, cols_b)
 
Purpose: Multiplies two equal-size square matrices by computing each result cell
as the dot product of a row and a column. Time complexity O(n^3).
 
---

## Sample Input/Output

Input(test values in main()):
```
    int testing_matrix_one[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int testing_matrix_two[3][3] = {
        {12, 65, 82},
        {83, 2, 8},
        {10, 96, 67}};
    
    target_value = 7
```

Output:

```row: 3 col: 3

---------------------------------------------------
                       TESTS                       
---------------------------------------------------


-------------------Print2DArray--------------------

Function Called: 
 Print2DArray 

[1|2|3]
[4|5|6]
[7|8|9]

End of Function: 
 Print2DArray 


------------------MatrixAddition-------------------

Function Called: 
 MatrixAddition 

Function Called: 
 Print2DArray 

[13|67|85]
[87|7|14]
[17|104|76]

End of Function: 
 Print2DArray 


End of function: 
 MatrixAddition 


------------------TransposeMatrix------------------

Function Called: 
 TransposeMatrix 

[1|4|7]
[2|5|8]
[3|6|9]

End of function: 
 TransposeMatrix 


--------------------Determinant--------------------

Function Called: 
 Determinant 

Determinant: 0

End of function: 
 Determinant 


--------------------SearchValue--------------------

Function Called: 
 SearchValue 

Found 7 at [2][0]

End of function: 
 SearchValue 


---------------MatrixMultiplication----------------

Function Called: 
 MatrixMultiplication 

Function Called: 
 Print2DArray 

[208|357|299]
[523|846|770]
[838|1335|1241]

End of Function: 
 Print2DArray 


End of function: 
 MatrixMultiplication 


--------------------------------------------------
```

---
 
## Testing
 
### Test Case 1
 
Input: Two valid 3x3 matrices.
 
Expected Result: Each function runs, prints its start and end banners, and
produces the correct matrix, determinant, or search result. The determinant of
`testing_matrix_one` is 0, and the search for 7 reports `[2][0]`.
 
### Test Case 2
 
Input: A function called with an unsupported dimension (for example, a row count
that is not 2 or 3).
 
Expected Result: The function prints "Error: Invalid matrix dimensions" and returns early without attempting the operation.
 
### Test Case 3
 
Input: A `SearchValue` call for a value that does not appear in the matrix.
 
Expected Result: `target`  wasn't found in the matrix
 
---