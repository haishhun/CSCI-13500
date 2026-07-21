#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "MenuItem.h"

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
void PopulateAVector(const std::string& file_name,
                     std::vector<MenuItem>& menu) {
  std::ifstream FileObject(file_name);
  // Check if it actually opened
  if (!FileObject.is_open()) {
    throw std::runtime_error("File cannot be opened.");
  }

  std::string line = {};
  while (getline(FileObject, line)) {
    std::istringstream iss(line);
    std::string new_name, new_category, new_price, new_stock;

    getline(iss, new_name, ',');
    getline(iss, new_category, ',');
    getline(iss, new_price, ',');
    getline(iss, new_stock, ',');

    MenuItem new_item;
    new_item.SetName(new_name);
    new_item.SetCategory(new_category);
    new_item.SetPrice(std::stod(new_price));
    new_item.SetStock(StringToInteger(new_stock));

    menu.push_back(new_item);
  }
}

void DisplayInventory(const std::vector<MenuItem>& menu) {
  for (const MenuItem& item : menu) {
    item.PrintItem();
  }
}

void DisplayItemsFilteredByCategory(const std::vector<MenuItem>& menu,
                                    const std::string& filter_category) {
  for (const MenuItem& item : menu) {
    if (item.GetCategory() == filter_category) {
      item.PrintItem();
    }
  }
}

void DisplayItemsFilteredByPrice(const std::vector<MenuItem>& menu,
                                 double min_price, double max_price) {
  for (const MenuItem& item : menu) {
    if (item.GetPrice() >= min_price && item.GetPrice() <= max_price) {
      item.PrintItem();
    }
  }
}