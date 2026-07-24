#include "Restaurant_Analytics.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "MenuItem.h"
namespace restaurant_analytics {

/* Converts a string to an integer.*/
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

  // Return the result.
  return result;
}

/* Populates the vector from the file.*/
void PopulateAVector(const std::string& file_name,
                     std::vector<MenuItem>& menu) {
  // Open the file
  std::ifstream file_object(file_name);

  // Check if it is actually opened
  if (!file_object.is_open()) {
    throw std::runtime_error("File cannot be opened.");
  }

  // Declare a variable for a line.
  std::string line = {};

  // Iterate through each line and create a new object MenuItem with data from
  // the line.
  while (getline(file_object, line)) {
    if (line.empty()) {
      continue;
    }
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

    // Add the new item into a vector.
    menu.push_back(new_item);
  }
}

/* Prints all items from the vector.*/
void DisplayInventory(const std::vector<MenuItem>& menu) {
  // Iterate through vector and print all items.
  for (const MenuItem& item : menu) {
    item.PrintItem();
  }
}
/* Prints all items from specific category from the vector.*/
void DisplayItemsFilteredByCategory(const std::vector<MenuItem>& menu,
                                    const std::string& filter_category) {
  // Iterate through the vector and print items that are in filter_category.
  for (const MenuItem& item : menu) {
    if (item.GetCategory() == filter_category) {
      item.PrintItem();
    }
  }
}

/* Prints all items that fit price range from the vector.*/
void DisplayItemsFilteredByPrice(const std::vector<MenuItem>& menu,
                                 double min_price, double max_price) {
  // Iterate through the vector and print items that are in target price range.
  for (const MenuItem& item : menu) {
    if (item.GetPrice() >= min_price && item.GetPrice() <= max_price) {
      item.PrintItem();
    }
  }
}

/* Returns the address of the item.*/
MenuItem* ItemAddressByName(std::vector<MenuItem>& menu,
                            const std::string& item_name) {
  // Iterate through the vector and return the address of the item that has the
  // target name.
  for (MenuItem& item : menu) {
    if (item.GetName() == item_name) {
      return &item;
    }
  }

  // If item not found - return nullptr.
  return nullptr;
}

/* Sets discount price for all items from a specific category.*/
void SalePriceModification(std::vector<MenuItem>& menu,
                           const std::string& filter_category,
                           double discount) {
  // Iterate through the vector and reduce the price of items that are in target
  // category by discount percent.
  for (MenuItem& item : menu) {
    if (item.GetCategory() == filter_category) {
      double new_price = item.GetPrice() * (1 - discount);
      item.SetPrice(new_price);
    }
  }
}

/* Returns a vector of k items with low units in stock.*/
std::vector<MenuItem> LowestStockQuantities(std::vector<MenuItem> menu, int k) {
  int menu_size = menu.size();

  // Early check for edge cases.
  if (k > menu_size) {
    k = menu_size;
  }
  if (k < 0) {
    k = 0;
  }

  // Selection sort in ascending order.
  for (int i = 0; i < k; i++) {
    int min_index = i;
    for (int j = i + 1; j < menu_size; j++) {
      if (menu[j].GetStock() < menu[min_index].GetStock()) {
        min_index = j;
      }
    }
    // Swap objects.
    MenuItem temp = menu[i];
    menu[i] = menu[min_index];
    menu[min_index] = temp;
  }

  // Resize the vector for the k values.
  menu.resize(k);

  // Return result
  return menu;
}

/* Returns a vector of k items with highest prices. */
std::vector<MenuItem> HighestPriceItems(std::vector<MenuItem> menu, int k) {
  int menu_size = menu.size();

  // Early check for edge cases.
  if (k > menu_size) {
    k = menu_size;
  }
  if (k < 0) {
    k = 0;
  }
  // Selection sort in descending order.
  for (int i = 0; i < k; i++) {
    int max_index = i;
    for (int j = i + 1; j < menu_size; j++) {
      if (menu[j].GetPrice() > menu[max_index].GetPrice()) {
        max_index = j;
      }
    }

    // Swap objects.
    MenuItem temp = menu[i];
    menu[i] = menu[max_index];
    menu[max_index] = temp;
  }

  // Resize the vector for the k values.
  menu.resize(k);

  // Return result
  return menu;
}

/* Writes a new CSV file. */
void CreateCSV(const std::vector<MenuItem>& menu) {
  // Create an output file object.
  std::ofstream file_object("output.txt");

  // Validate if the object was created.
  if (!file_object.is_open()) {
    throw std::runtime_error("File cannot be opened.");
  }

  // Iterate through the input vector and write each item in output file.
  for (const MenuItem& item : menu) {
    file_object << item.GetName() << ',' << item.GetCategory() << ','
                << item.GetPrice() << ',' << item.GetStock() << std::endl;
  }

  // Close the file.
  file_object.close();
}

/* Writes a new CSV file with all items that has lower units than
 * stock_threshold. */
void CreateLowStockCSV(const std::vector<MenuItem>& menu,
                       const std::string& output_file_name,
                       int stock_threshold) {
  // Create an output file object.
  std::ofstream file_object(output_file_name);

  // Validate if the object was created.
  if (!file_object.is_open()) {
    throw std::runtime_error("File cannot be opened.");
  }

  // Iterate through the input vector and write each item that have lower units
  // than stock_treshhold in output file.
  for (const MenuItem& item : menu) {
    if (item.GetStock() < stock_threshold) {
      file_object << item.GetName() << ',' << item.GetCategory() << ','
                  << item.GetPrice() << ',' << item.GetStock() << std::endl;
    }
  }
  // Close the file.
  file_object.close();
}
}  // namespace restaurant_analytics