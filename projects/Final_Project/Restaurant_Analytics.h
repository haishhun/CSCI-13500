#ifndef RESTAURANT_ANALYTICS_H
#define RESTAURANT_ANALYTICS_H

#include <string>
#include <vector>

#include "MenuItem.h"

namespace restaurant_analytics {

/*Converts a string to an integer.*/
int StringToInteger(const std::string& string_to_convert);

/*Populates the vector from the file.*/
void PopulateAVector(const std::string& file_name, std::vector<MenuItem>& menu);

/* Prints all items from the vector.*/
void DisplayInventory(const std::vector<MenuItem>& menu);

/* Prints all items from specific category from the vector.*/
void DisplayItemsFilteredByCategory(const std::vector<MenuItem>& menu,
                                    const std::string& filter_category);

/* Prints all items that fit price range from the vector.*/
void DisplayItemsFilteredByPrice(const std::vector<MenuItem>& menu,
                                 double min_price, double max_price);

/* Returns the address of the item.*/
MenuItem* ItemAddressByName(std::vector<MenuItem>& menu,
                            const std::string& item_name);

/* Sets discount price for all items from a specific category.*/
void SalePriceModification(std::vector<MenuItem>& menu,
                           const std::string& filter_category, double discount);

/* Returns a vector of k items with low units in stock.*/
std::vector<MenuItem> LowestStockQuantities(std::vector<MenuItem> menu, int k);

/* Returns a vector of k items with highest prices. */
std::vector<MenuItem> HighestPriceItems(std::vector<MenuItem> menu, int k);

/* Writes a new CSV file. */
void CreateCSV(const std::vector<MenuItem>& menu);

/* Writes a new CSV file with all items that have lower units
 * stock_threshold. */
void CreateLowStockCSV(const std::vector<MenuItem>& menu,
                       const std::string& output_file_name,
                       int stock_threshold);
}  // namespace restaurant_analytics

#endif