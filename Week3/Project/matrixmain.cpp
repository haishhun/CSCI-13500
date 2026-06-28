#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3],
                  const int matrix_local_rows_total) {
  // Function_Start message to terminal
  std::cout << "Function Called: \n Print2DArray \n\n";

  // Validating matrix dimensions. Only 2x2 and 3x3 matrices are supported.
  if (matrix_local_rows_total != 2 && matrix_local_rows_total != 3) {
    std::cout << "Error: Invalid matrix dimensions\n";
    std::cout << "\nEnd of function: \n Print2DArray \n\n";
    return;
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Printing the matrix row by row with "|" separators between values.
  for (int row = 0; row < matrix_local_rows_total; row++) {
    std::cout << "[";
    for (int column = 0; column < matrix_local_rows_total;
         column++)  // Since our matrix are squares, we can use rows as columns
    {
      std::cout << matrix_local[row][column];
      if (column < matrix_local_rows_total - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]\n";
  }

  // Function_End message to terminal
  std::cout << "\nEnd of Function: \n Print2DArray \n\n";
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3],
                    const int matrix_two_rows_total) {
  // Function_Start message to terminal
  std::cout << "Function Called: \n MatrixAddition \n\n";

  // Validating dimensions of both matrices before adding them.
  if ((matrix_one_rows_total != 2 && matrix_one_rows_total != 3) ||
      (matrix_two_rows_total != 2 && matrix_two_rows_total != 3)) {
    std::cout << "Error: Invalid matrix dimensions\n";
    std::cout << "\nEnd of function: \n MatrixAddition \n\n";
    return;
  }

  // Declaring the result matrix and initializing all cells to zero.
  int new_matrix[3][3] = {};

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Adding the two matrices cell by cell into the result matrix.
  for (int row = 0; row < matrix_one_rows_total; row++) {
    for (int column = 0; column < matrix_one_rows_total; column++) {
      new_matrix[row][column] =
          matrix_one[row][column] + matrix_two[row][column];
    }
  }

  // Reusing Print2DArray to display the result matrix.
  Print2DArray(new_matrix, matrix_one_rows_total);

  // Function_End message to terminal
  std::cout << "\nEnd of function: \n MatrixAddition \n\n";
}

void TransposeMatrix(const int matrix_local[][3],
                     const int matrix_local_rows_total) {
  // Function_Start message to terminal
  std::cout << "Function Called: \n TransposeMatrix \n\n";

  // Declaring the result matrix and initializing all cells to zero.
  int new_matrix[3][3] = {};

  // Columns fixed at 3. Ideally passed as an argument to support non-3-column
  // matrices.
  int columns = 3;

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Filling the result matrix by swapping the row and column indexes.
  for (int row = 0; row < matrix_local_rows_total; row++) {
    for (int column = 0; column < columns; column++) {
      new_matrix[column][row] = matrix_local[row][column];
    }
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Printing the transposed matrix row by row.
  for (int row = 0; row < columns; row++) {
    std::cout << "[";
    for (int column = 0; column < matrix_local_rows_total; column++) {
      std::cout << new_matrix[row][column];
      if (column < matrix_local_rows_total - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]\n";
  }

  // Function_End message to terminal
  std::cout << "\nEnd of function: \n TransposeMatrix \n\n";
}

void Determinant(const int matrix_local[][3], const int size) {
  // Function_Start message to terminal
  std::cout << "Function Called: \n Determinant \n\n";

  // Validating size of the matrix. Only 2x2 and 3x3 are supported.
  if (size != 2 && size != 3) {
    std::cout << "Error: Invalid size of the matrix";
    std::cout << "\nEnd of function: \n Determinant \n\n";
    return;
  }

  // Declaring the determinant variable.
  int determinant = 0;

  // Computing the determinant for a 2x2 matrix.
  if (size == 2) {
    determinant = matrix_local[0][0] * matrix_local[1][1] -
                  matrix_local[0][1] * matrix_local[1][0];
  }
  // Computing the determinant for a 3x3 matrix.
  else {
    determinant =
        matrix_local[0][0] * (matrix_local[1][1] * matrix_local[2][2] -
                              matrix_local[1][2] * matrix_local[2][1]) -
        matrix_local[0][1] * (matrix_local[1][0] * matrix_local[2][2] -
                              matrix_local[1][2] * matrix_local[2][0]) +
        matrix_local[0][2] * (matrix_local[1][0] * matrix_local[2][1] -
                              matrix_local[1][1] * matrix_local[2][0]);
  }

  // Printing the determinant value to the terminal.
  std::cout << "Determinant: " << determinant << std::endl;

  // Function_End message to terminal
  std::cout << "\nEnd of function: \n Determinant \n\n";
}

void SearchValue(const int matrix_local[][3], const int rows,
                 const int target) {
  // Function_Start message to terminal
  std::cout << "Function Called: \n SearchValue \n\n";

  // Validating matrix dimensions. Only 2x2 and 3x3 are supported.
  if (rows != 2 && rows != 3) {
    std::cout << "Error: Invalid matrix dimensions\n";
    std::cout << "\nEnd of function: \n SearchValue \n\n";
    return;
  }

  // Declaring the flag that tracks whether the target was found.
  bool target_found = false;

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Searching every cell for the target and printing its position when matched.
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < rows;
         column++)  // we can use column < rows because its square matrix.
    {
      if (matrix_local[row][column] == target) {
        std::cout << "Found " << target << " at [" << row << "]" << "["
                  << column << "]" << std::endl;
        target_found = true;
      }
    }
  }

  // Printing a message if the target was never found in the matrix.
  if (!target_found) {
    std::cout << target << " wasn't found in the matrix" << std::endl;
  }
  // Function_End message to terminal
  std::cout << "\nEnd of function: \n SearchValue \n\n";
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3],
                          const int rows_a, const int cols_a, const int rows_b,
                          const int cols_b) {
  // Function_Start message to terminal
  std::cout << "Function Called: \n MatrixMultiplication \n\n";

  // Validating that both matrices are square and of equal size.
  if (rows_a != cols_a || rows_b != cols_b || rows_a != rows_b ||
      cols_a != cols_b) {
    std::cout << "Error: Invalid size of the matrix";
    std::cout << "\nEnd of function: \n MatrixMultiplication \n\n";
    return;
  }

  // Declaring the result matrix and initializing all cells to zero.
  int new_matrix[3][3] = {};

  // The time complexity for this loop is O(n^3) because of the three nested
  // loops. Using rows_a for all bounds is safe because the validation above
  // guarantees both matrices are equal squares.
  for (int i = 0; i < rows_a; i++) {
    for (int j = 0; j < rows_a; j++) {
      for (int k = 0; k < rows_a; k++) {
        new_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
      }
    }
  }

  // Reusing Print2DArray to display the result matrix.
  Print2DArray(new_matrix, rows_a);

  // Function_End message to terminal
  std::cout << "\nEnd of function: \n MatrixMultiplication \n\n";
}

int main() {
  // Use these two matrices for basic testing.

  int testing_matrix_one[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  int testing_matrix_two[3][3] = {{12, 65, 82}, {83, 2, 8}, {10, 96, 67}};

  // Not used in this class, but it is nice to know other ways to find the size
  // of primitive array. This method below is similar to how you will find the
  // size of vectors (future material) DO NOT USE IN THIS PROJECT FUNCTION, but
  // you could test it yourselves. int size_row_one =
  // std::size(testing_matrix_one); int size_col_one =
  // std::size(testing_matrix_one[0]);

  // This is a way to find the dimensions of an array without hardcoding values.
  // It dynamically reflects the array's actual declared size, so if you change
  // the array dimensions, the calculation updates automatically.
  //
  // How it works:
  //
  // To find the number of ROWS:
  //   sizeof(testing_matrix_one)      = total bytes of the whole array = 3*9*4
  //   = 108 bytes sizeof(testing_matrix_one[0])   = total bytes of one row =
  //   1*9*4 =  36 bytes 108 / 36 = 3 rows

  int size_row_one = sizeof(testing_matrix_one) / sizeof(testing_matrix_one[0]);
  int size_row_two = sizeof(testing_matrix_two) / sizeof(testing_matrix_two[0]);
  // To find the number of COLUMNS:
  //   sizeof(testing_matrix_one[0])      = total bytes of one row          =
  //   1*9*4 = 36 bytes sizeof(testing_matrix_one[0][0])   = total bytes of one
  //   element(int) = 1*4   =  4 bytes 36 / 4 = 9 cols

  int size_col_one =
      sizeof(testing_matrix_one[0]) / sizeof(testing_matrix_one[0][0]);

  std::cout << "row: " << size_row_one << " col: " << size_col_one << std::endl
            << std::endl;

  std::cout << "---------------------------------------------------"
            << std::endl;
  std::cout << "                       TESTS                       "
            << std::endl;
  std::cout << "---------------------------------------------------"
            << std::endl
            << std::endl;

  std::cout << "\n-------------------Print2DArray--------------------\n"
            << std::endl;
  Print2DArray(testing_matrix_one, size_row_one);
  std::cout << "\n------------------MatrixAddition-------------------\n"
            << std::endl;
  MatrixAddition(testing_matrix_one, size_row_one, testing_matrix_two,
                 size_row_two);
  std::cout << "\n------------------TransposeMatrix------------------\n"
            << std::endl;
  TransposeMatrix(testing_matrix_one, size_row_one);
  std::cout << "\n--------------------Determinant--------------------\n"
            << std::endl;
  Determinant(testing_matrix_one, size_row_one);
  std::cout << "\n--------------------SearchValue--------------------\n"
            << std::endl;
  SearchValue(testing_matrix_one, size_row_one, 7);
  std::cout << "\n---------------MatrixMultiplication----------------\n"
            << std::endl;
  MatrixMultiplication(testing_matrix_one, testing_matrix_two, 3, 3, 3, 3);
  std::cout << "\n---------------------------------------------------\n"
            << std::endl;

  return 0;
}