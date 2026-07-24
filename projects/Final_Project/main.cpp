#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "MenuItem.h"
#include "Restaurant_Analytics.h"

int main() {
  std::vector<MenuItem> menu;

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "                MenuItem                " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Creating Test Item 1 ..." << std::endl;
  MenuItem test_item_1("Test Item 1", "Main", 12.50, 2);
  test_item_1.PrintItem();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Creating Test Item 2 ..." << std::endl;
  MenuItem test_item_2("Test Item 2", "Dessert", 25, 5);
  test_item_2.PrintItem();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Creating Test Item 3 ..." << std::endl;
  MenuItem test_item_3("Test Item 3", "Main", 50, 10);
  test_item_3.PrintItem();

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "             PopulateAVector            " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  try {
    restaurant_analytics::PopulateAVector("inventory.csv", menu);
    std::cout << "Populated a vector with items from inventory.csv"
              << std::endl;
  } catch (...) {
    std::cout << "Error loading file: " << std::endl;
    return 0;
  }

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "            DisplayInventory            " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Displaying all inventory ..." << std::endl;
  restaurant_analytics::DisplayInventory(menu);

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "     DisplayItemsFilteredByCategory     " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Displaying filtered inventory by category Appetizer ..."
            << std::endl;
  restaurant_analytics::DisplayItemsFilteredByCategory(menu, "Appetizer");
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Displaying filtered inventory by category Dessert ..."
            << std::endl;
  restaurant_analytics::DisplayItemsFilteredByCategory(menu, "Dessert");
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Displaying filtered inventory by category Beverage ..."
            << std::endl;
  restaurant_analytics::DisplayItemsFilteredByCategory(menu, "Beverage");

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "       DisplayItemsFilteredByPrice      " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Displaying filtered inventory by price in range 0.0 - 5.0 ..."
            << std::endl;
  restaurant_analytics::DisplayItemsFilteredByPrice(menu, 0.0, 5.0);
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Displaying filtered inventory by price in range 5.0 - 15.0 ..."
            << std::endl;
  restaurant_analytics::DisplayItemsFilteredByPrice(menu, 5.0, 15.0);
  std::cout << "----------------------------------------" << std::endl;

  std::cout
      << "Displaying filtered inventory by price in range 20.0 - 100.0 ..."
      << std::endl;
  restaurant_analytics::DisplayItemsFilteredByPrice(menu, 20.0, 100.0);

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "            ItemAddressByName           " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Returning address of the item with name Steak Dinner ..."
            << std::endl;
  MenuItem* first_item =
      restaurant_analytics::ItemAddressByName(menu, "Steak Dinner");
  if (first_item != nullptr) {
    std::cout << "Item " << first_item->GetName() << " has address "
              << first_item << std::endl;
  } else {
    std::cout << "Item not found." << std::endl;
  }
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Returning address of the item with name Plain Cheesecake ..."
            << std::endl;
  MenuItem* second_item =
      restaurant_analytics::ItemAddressByName(menu, "Plain Cheesecake");
  if (second_item != nullptr) {
    std::cout << "Item " << second_item->GetName() << " has address "
              << second_item << std::endl;
  } else {
    std::cout << "Item not found." << std::endl;
  }
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Returning address of the item with name Something that does "
               "not exist ..."
            << std::endl;
  MenuItem* third_item = restaurant_analytics::ItemAddressByName(
      menu, "Something that does not exist");
  if (third_item != nullptr) {
    std::cout << "Item " << third_item->GetName() << " has address "
              << third_item << std::endl;
  } else {
    std::cout << "Item not found." << std::endl;
  }

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "           SalePriceModification        " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Setting sale price for category Appetizer -20% ..."
            << std::endl;
  restaurant_analytics::SalePriceModification(menu, "Appetizer", 0.20);
  restaurant_analytics::DisplayItemsFilteredByCategory(menu, "Appetizer");
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Setting sale price for category Main -50% ..." << std::endl;
  restaurant_analytics::SalePriceModification(menu, "Main", 0.50);
  restaurant_analytics::DisplayItemsFilteredByCategory(menu, "Main");
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Setting sale price for category Beverage -99% ..." << std::endl;
  restaurant_analytics::SalePriceModification(menu, "Beverage", 0.99);
  restaurant_analytics::DisplayItemsFilteredByCategory(menu, "Beverage");

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "          LowestStockQuantities         " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Displaying 1 item with lowest stock ..." << std::endl;
  std::vector<MenuItem> low_1 =
      restaurant_analytics::LowestStockQuantities(menu, 1);
  restaurant_analytics::DisplayInventory(low_1);
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Displaying 3 items with lowest stock ..." << std::endl;
  std::vector<MenuItem> low_3 =
      restaurant_analytics::LowestStockQuantities(menu, 3);
  restaurant_analytics::DisplayInventory(low_3);
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Displaying 5 items with lowest stock ..." << std::endl;
  std::vector<MenuItem> low_5 =
      restaurant_analytics::LowestStockQuantities(menu, 5);
  restaurant_analytics::DisplayInventory(low_5);

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "            HighestPriceItems          " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Displaying 1 item with highest price ..." << std::endl;
  std::vector<MenuItem> high_1 =
      restaurant_analytics::HighestPriceItems(menu, 1);
  restaurant_analytics::DisplayInventory(high_1);
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Displaying 3 items with highest price ..." << std::endl;
  std::vector<MenuItem> high_3 =
      restaurant_analytics::HighestPriceItems(menu, 3);
  restaurant_analytics::DisplayInventory(high_3);
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Displaying 5 items with highest price ..." << std::endl;
  std::vector<MenuItem> high_5 =
      restaurant_analytics::HighestPriceItems(menu, 5);
  restaurant_analytics::DisplayInventory(high_5);

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "            CreateLowStockCSV          " << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Creating a CSV file with items less than 5 in stock ..."
            << std::endl;
  try {
    restaurant_analytics::CreateLowStockCSV(menu, "low_stock_5.csv", 5);
    std::cout << "low_stock_5.csv created." << std::endl;
  } catch (...) {
    std::cout << "Error writing file: " << std::endl;
  }
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Creating a CSV file with items less than 15 in stock ..."
            << std::endl;
  try {
    restaurant_analytics::CreateLowStockCSV(menu, "low_stock_15.csv", 15);
    std::cout << "low_stock_15.csv created." << std::endl;
  } catch (...) {
    std::cout << "Error writing file: " << std::endl;
  }
  std::cout << "\n----------------------------------------" << std::endl;

  std::cout << "Creating a CSV file with items less than 30 in stock ..."
            << std::endl;
  try {
    restaurant_analytics::CreateLowStockCSV(menu, "low_stock_30.csv", 30);
    std::cout << "low_stock_30.csv created." << std::endl;
  } catch (...) {
    std::cout << "Error writing file: " << std::endl;
  }

  std::cout << "\n----------------------------------------" << std::endl;
  std::cout << "                CreateCSV               " << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Creating an updated file with all modifications ..."
            << std::endl;
  try {
    restaurant_analytics::CreateCSV(menu);
    std::cout << "Update menu saved to output.txt" << std::endl;
  } catch (...) {
    std::cout << "Error writing file: " << std::endl;
  }
  std::cout << "\n----------------------------------------" << std::endl;
}
