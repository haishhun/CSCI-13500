#include <iostream>
#include <stdexcept>
#include <string>

int StringToInteger(const std::string& string_to_convert) {
  int result = 0;
  bool is_negative = false;
  int starting_index = 0;
  const int string_length = string_to_convert.length();

  // Skip spaces in the beginning and move starting index.
  while (starting_index < string_length &&
         string_to_convert[starting_index] == ' ') {
    starting_index++;
  }

  // Check if the string starts with "-" or "+", if yes - set is_negative to
  // true, move starting index.
  if (starting_index < string_length &&
      string_to_convert[starting_index] == '-') {
    is_negative = true;
    starting_index++;
  } else if (starting_index < string_length &&
             string_to_convert[starting_index] == '+') {
    starting_index++;
  }

  // Validate the string before converting
  if (starting_index >= string_length ||
      string_to_convert[starting_index] < '0' ||
      string_to_convert[starting_index] > '9') {
    throw std::invalid_argument("No digits found.");
  }

  // Convert the string.
  for (int index = starting_index; index < string_length; index++) {
    if (string_to_convert[index] >= '0' && string_to_convert[index] <= '9') {
      int digit = string_to_convert[index] - '0';
      result = result * 10 + digit;
    } else {
      throw std::invalid_argument("String contains invalid characters.");
    }
  }

  // Make the number negative if the string starts with "-".
  if (is_negative) {
    result = -result;
  }
  return result;
}