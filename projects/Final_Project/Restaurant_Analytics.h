#ifndef RESTAURANT_ANALYTICS_H
#define RESTAURANT_ANALYTICS_H

#include <string>
#include <vector>

#include "MenuItem.h"

namespace restaurant_analytics {
int StringToInteger(const std::string& string_to_convert);
void PopulateAVector(const std::string& file_name, std::vector<MenuItem>& menu);
void DisplayInventory(const std::vector<MenuItem>& menu);
void DisplayItemsFilteredByCategory(const std::vector<MenuItem>& menu,
                                    const std::string& filter_category);
void DisplayItemsFilteredByPrice(const std::vector<MenuItem>& menu,
                                 double min_price, double max_price);
MenuItem* ItemAddressByName(std::vector<MenuItem>& menu,
                            const std::string& item_name);
void SalePriceModification(std::vector<MenuItem>& menu,
                           const std::string& filter_category, double discount);
std::vector<MenuItem> LowestStockQuantities(std::vector<MenuItem> menu, int k);
std::vector<MenuItem> HighestPriceItems(std::vector<MenuItem> menu, int k);
void CreateLowStockCSV(const std::vector<MenuItem>& menu,
                       const std::string& output_file_name,
                       int stock_threshold);
}  // namespace restaurant_analytics

#endif