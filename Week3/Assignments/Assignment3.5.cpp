#include <iostream>
#include <vector>
int main() {
  // Declaring two arrays of sizes 3x3 and 6x6 for Tasks 1 and 2.
  int new_array_three[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int new_array_six[6][6] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

  // Declaring array sizes and row sizes for each array for Tasks 1 and 2.
  int array_three_rows = sizeof(new_array_three) / sizeof(new_array_three[0]);
  int array_three_columns =
      sizeof(new_array_three[0]) / sizeof(new_array_three[0][0]);
  int array_six_rows = sizeof(new_array_six) / sizeof(new_array_six[0]);
  int array_six_columns =
      sizeof(new_array_six[0]) / sizeof(new_array_six[0][0]);

  // Declaring vector, rows amount, columns amount and the output vector for
  // Task 3.
  std::vector<std::vector<int>> new_vector = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int new_vector_rows = new_vector.size();
  int new_vector_columns = new_vector[0].size();
  std::vector<std::vector<int>> output_vector(2);

  // Declaring variables for diagonal 1, diagonal 2, center number, and sum for
  // Task 4.
  int d1 = 0;
  int d2 = 0;
  int c = 0;
  int S = 0;

  // Display message.
  std::cout << "------------------------------" << std::endl;
  std::cout << "            Task 1            " << std::endl;
  std::cout << "------------------------------" << std::endl;

  std::cout << "----------3x3 matrix----------\n" << std::endl;

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Filling left half of the matrix into ones.
  for (int i = 0; i < array_three_rows; i++) {
    for (int j = 0; j < array_three_columns; j++) {
      if (j < array_three_columns - i) {
        new_array_three[i][j] = 1;
      }
    }
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Printing the result matrix.
  for (int i = 0; i < array_three_rows; i++) {
    std::cout << "[";
    for (int j = 0; j < array_three_columns; j++) {
      std::cout << new_array_three[i][j];
      if (j < array_three_columns - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]\n";
  }
  std::cout << "\n----------6x6 matrix----------\n" << std::endl;

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Filling left half of the matrix into ones.
  for (int i = 0; i < array_six_rows; i++) {
    for (int j = 0; j < array_six_columns; j++) {
      if (j < array_six_columns - i) {
        new_array_six[i][j] = 1;
      }
    }
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Printing the result matrix.
  for (int i = 0; i < array_six_rows; i++) {
    std::cout << "[";
    for (int j = 0; j < array_six_columns; j++) {
      std::cout << new_array_six[i][j];
      if (j < array_six_columns - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]\n";
  }

  // Display message.
  std::cout << "\n------------------------------" << std::endl;
  std::cout << "            Task 2            " << std::endl;
  std::cout << "------------------------------" << std::endl;

  std::cout << "----------3x3 matrix----------\n" << std::endl;

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Resetting the matrix to zeros to reuse it in this task.
  for (int i = 0; i < array_three_rows; i++) {
    for (int j = 0; j < array_three_columns; j++) {
      new_array_three[i][j] = 0;
    }
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Filling diagonals into ones.
  for (int i = 0; i < array_three_rows; i++) {
    for (int j = 0; j < array_three_columns; j++) {
      if (i == j || j == array_three_columns - 1 - i) {
        new_array_three[i][j] = 1;
      }
    }
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Printing the result matrix.
  for (int i = 0; i < array_three_rows; i++) {
    std::cout << "[";
    for (int j = 0; j < array_three_columns; j++) {
      std::cout << new_array_three[i][j];
      if (j < array_three_columns - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]\n";
  }
  std::cout << "\n----------6x6 matrix----------\n" << std::endl;

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Resetting the matrix to zeros to reuse it in this task.
  for (int i = 0; i < array_six_rows; i++) {
    for (int j = 0; j < array_six_columns; j++) {
      new_array_six[i][j] = 0;
    }
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Filling diagonals into ones.
  for (int i = 0; i < array_six_rows; i++) {
    for (int j = 0; j < array_six_columns; j++) {
      if (i == j || j == array_six_columns - 1 - i) {
        new_array_six[i][j] = 1;
      }
    }
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Printing the result matrix.
  for (int i = 0; i < array_six_rows; i++) {
    std::cout << "[";
    for (int j = 0; j < array_six_columns; j++) {
      std::cout << new_array_six[i][j];
      if (j < array_six_columns - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]\n";
  }

  // Display message.
  std::cout << "\n------------------------------" << std::endl;
  std::cout << "            Task 3            " << std::endl;
  std::cout << "------------------------------" << std::endl;

  std::cout << "----------3x3 matrix----------\n" << std::endl;

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Filling computing sum of each row and adding it into first row of
  // output_vector, then reset the total variable.
  for (int row = 0; row < new_vector_rows; row++) {
    int total = 0;
    for (int column = 0; column < new_vector_columns; column++)
      total += new_vector[row][column];
    output_vector[0].push_back(total);
  }

  // The time complexity for this loop is O(n^2) because of the nested loop.
  // Filling computing sum of each column and adding it into second row of
  // output_vector, then reset the total variable.
  for (int column = 0; column < new_vector_columns; column++) {
    int total = 0;
    for (int row = 0; row < new_vector_rows; row++)
      total += new_vector[row][column];
    output_vector[1].push_back(total);
  }

  // The time complexity for this loop is O(n) because vector row amount is 2 so
  // O(2*n)=O(n)
  // Printing the result matrix.
  for (int i = 0; i < 2; i++) {
    std::cout << "[";
    int output_vector_size = output_vector[i].size();
    for (int j = 0; j < output_vector_size; j++) {
      std::cout << output_vector[i][j];
      if (j < output_vector_size - 1) {
        std::cout << "|";
      }
    }
    std::cout << "]\n";
  }

  // Display message
  std::cout << "\n------------------------------" << std::endl;
  std::cout << "            Task 4            " << std::endl;
  std::cout << "------------------------------" << std::endl;

  std::cout << "----------3x3 matrix----------" << std::endl;

  // The time complexity for this loop is O(n).
  // Computing sums of diagonals
  for (int i = 0; i < new_vector_rows; i++) {
    d1 += new_vector[i][i];
    d2 += new_vector[i][new_vector_rows - 1 - i];
  }

  // Validating if matrix is not even, then subtracting central number because
  // it was added twice.
  if (new_vector_rows % 2 == 1)  // odd size -> center on both diagonals
  {
    c = new_vector[new_vector_rows / 2][new_vector_rows / 2];
    S = d1 + d2 - c;
  } else {
    S = d1 + d2;
  }
  std::cout << "\nTotal sum of diagonals is: " << S << std::endl;
  std::cout << "\n------------------------------" << std::endl;
}