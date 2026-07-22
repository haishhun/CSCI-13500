#include "Restaurant_Analytics.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "MenuItem.h"
namespace restaurant_analytics {
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
  // Open the file
  std::ifstream FileObject(file_name);

  // Check if it is actually opened
  if (!FileObject.is_open()) {
    throw std::runtime_error("File cannot be opened.");
  }

  // Declare a variable for a line.
  std::string line = {};

  // Iterate through each line and create a new object MenuItem with data from
  // the line.
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

    // Add the new item into a vector.
    menu.push_back(new_item);
  }
}

void DisplayInventory(const std::vector<MenuItem>& menu) {
  // Iterate through vector and print all items.
  for (const MenuItem& item : menu) {
    item.PrintItem();
  }
}

void DisplayItemsFilteredByCategory(const std::vector<MenuItem>& menu,
                                    const std::string& filter_category) {
  // Iterate through the vector and print items that are in filter_category.
  for (const MenuItem& item : menu) {
    if (item.GetCategory() == filter_category) {
      item.PrintItem();
    }
  }
}

void DisplayItemsFilteredByPrice(const std::vector<MenuItem>& menu,
                                 double min_price, double max_price) {
  // Iterate through the vector and print items that are in target price range.
  for (const MenuItem& item : menu) {
    if (item.GetPrice() >= min_price && item.GetPrice() <= max_price) {
      item.PrintItem();
    }
  }
}

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

std::vector<MenuItem> LowestStockQuantities(std::vector<MenuItem> menu, int k) {
  int menu_size = menu.size();

  // Early check for edge cases.
  if (k > menu_size) {
    k = menu_size;
  }
  if (k < 0) {
    k = 0;
  }

  // Bubble sort in descending order.
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

std::vector<MenuItem> HighestPriceItems(std::vector<MenuItem> menu, int k) {
  int menu_size = menu.size();

  // Early check for edge cases.
  if (k > menu_size) {
    k = menu_size;
  }
  if (k < 0) {
    k = 0;
  }
  // Bubble sort in ascending order.
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

void CreateLowStockCSV(const std::vector<MenuItem>& menu,
                       const std::string& output_file_name,
                       int stock_threshold) {
  std::ofstream FileObject(output_file_name);
  if (!FileObject.is_open()) {
    throw std::runtime_error("File cannot be opened.");
  }
  for (const MenuItem& item : menu) {
    if (item.GetStock() < stock_threshold) {
      FileObject << item.GetName() << ',' << item.GetCategory() << ','
                 << item.GetPrice() << ',' << item.GetStock() << std::endl;
    }
  }
  FileObject.close();
}
}  // namespace restaurant_analytics