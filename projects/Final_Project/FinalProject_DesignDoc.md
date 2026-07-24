# Program Design Document

## Program Name

Final Project: Restaurant Inventory Manager

## Purpose

This program is a restaurant inventory API. It reads a list of menu items from a CSV file, stores them as objects in a vector, and then displays, filters, and analyzes that inventory. It also writes new CSV files that report which items are running low, which items has the highest price and what the menu looks like after a sale.

---

## Inputs

* new_name
* new_category
* new_price
* new_stock
* string_to_convert
* file_name
* std::vector<MenuItem>& menu
* filter_category
* min_price
* max_price
* item_name
* filter_category
* discount
* int k
* stock_threshold

---

## Outputs

* List of all items.
* List of items filtered by category.
* List of items filtered by price range.
* Address of an item.
* Items with updated prices.
* List of `k` items with the lowest stock.
* List of `k` items with the highest price.
* `output.txt` file with the whole menu.
* `low_stock_.csv files with low stock items.

---
 
## Variables
 
| Variable         | Type                     | Purpose                                          |
| ---------------- | ------------------------ | ------------------------------------------------ |
| name             | std::string              | Name of an item                                  |
| category         | std::string              | Category of an item                              |
| price            | double                   | Price of an item                                 |
| stock            | int                      | Number of units in stock                         |
| menu             | std::vector<MenuItem>    | Stores the whole inventory                       |
| file_object      | std::ifstream/ofstream   | Stream used to read or write a file              |
| line             | std::string              | One line read from the file                      |
| iss              | std::istringstream       | Splits one line by the comma delimiter           |
| result           | int                      | Number in StringToInteger                        |
| is_negative      | bool                     | Records if the string starts with "-"            |
| starting_index   | int                      | Index where the digits begin                     |
| min_index        | int                      | Index of the smallest stock found in a pass      |
| max_index        | int                      | Index of the highest price found in a pass       |
| menu_size        | int                      | Number of items in the copy being sorted         |
| stock_threshold  | int                      | Items below this value are written to a file     |
 
---

## Key Design Choices

Explain any important decisions you made when designing the program.

Examples:

* I used a selection sort for sorting items in ascending and descending orders in `LowestStockQuantities` and `LowestStockQuantities`.
* I added additional method `CreateCSV` to be able to write a full new CSV file with all modifications of a vector.
* I used `\t` in `PrintItem` for output to look more readable.
* I used ASCII method to convert string to integer.

---

## Program Steps (Algorithm)

### StringToInteger

1. Declare `result`, `is_negative`, and `starting_index`.
2. Skip spaces in the beginning and move `starting_index`.
3. Check if the string starts with "-" or "+", set `is_negative` and move `starting_index`.
4. Throw `std::invalid_argument` if there are no digits after the sign.
5. Iterate through the string and build the number as `result = result * 10 + digit`.
6. Throw `std::invalid_argument` if a character is not a digit.
7. Make the number negative if the string started with "-".
8. Return `result`.

### PopulateAVector

1. Create an input file object with the input file name.
2. Throw `std::runtime_error` if the file cannot be opened.
3. Declare a variable `line`.
4. Iterate through each line of the file.
5. Skip the line if it is empty.
6. Create an `std::istringstream` from the line and split it into four strings by the comma.
7. Create a `MenuItem` and set its name, category, price, and stock.
8. Add the new item into the vector.


### DisplayInventory

1. Iterate through the vector.
2. Call `PrintItem()` on each item.


### DisplayItemsFilteredByCategory

1. Iterate through the vector.
2. Print the item if its category matches `filter_category`.


### DisplayItemsFilteredByPrice

1. Iterate through the vector.
2. Print the item if its price is between `min_price` and `max_price`.


### ItemAddressByName

1. Iterate through the vector.
2. Return the address of the item if its name matches `item_name`.
3. Return `nullptr` if the item is not found.


### SalePriceModification

1. Iterate through the vector.
2. Calculate `new_price` for items in `filter_category`.
3. Set the new price.


### LowestStockQuantities

1. Store the size of the copy in `menu_size`.
2. Set `k` to `menu_size` if `k` is bigger, and to 0 if `k` is negative.
3. Run `k` passes of a selection sort.
4. Find `min_index` of the smallest stock in the unsorted part on each pass.
5. Swap the item at `i` with the item at `min_index`.
6. Resize the vector to `k`.
7. Return the result.

### HighestPriceItems

1. Store the size of the copy in `menu_size`.
2. Set `k` to `menu_size` if `k` is bigger, and to 0 if `k` is negative.
3. Run `k` passes of a selection sort.
4. Find `max_index` of the highest price in the unsorted part on each pass.
5. Swap the item at `i` with the item at `max_index`.
6. Resize the vector to `k`.
7. Return the result.


### CreateCSV

1. Create an output file object with the name `output.txt`.
2. Throw `std::runtime_error` if the file cannot be opened.
3. Iterate through the vector and write each item as `Name,Category,Price,Stock`.
4. Close the file.


### CreateLowStockCSV

1. Create an output file object with the input file name.
2. Throw `std::runtime_error` if the file cannot be opened.
3. Iterate through the vector.
4. Write the item as `Name,Category,Price,Stock` if its stock is lower than `stock_threshold`.
5. Close the file.

---
 
## Functions
 
### Function: MenuItem()
Purpose: Default constructor.
 
### Function: MenuItem(new_name, new_category, new_price, new_stock)
Purpose: Parameterized constructor.
 
### Function: ~MenuItem()
Purpose: Destructor.
 
### Function: GetName()
Purpose: Returns the name of the item.
 
### Function: SetName(new_name)
Purpose: Sets the name of the item.
 
### Function: GetCategory()
Purpose: Returns the category of the item.
 
### Function: SetCategory(new_category)
Purpose: Sets the category of the item.
 
### Function: GetPrice()
Purpose: Returns the current price of the item.
 
### Function: SetPrice(new_price)
Purpose: Sets the price of the item.
 
### Function: GetStock()
Purpose: Returns how many units of the item are in stock.
 
### Function: SetStock(new_stock)
Purpose: Sets how many units of the item are in stock.
 
### Function: PrintItem()
Purpose: Prints the name, category, price, and stock of the item.
 
### Function: StringToInteger(string_to_convert)
Purpose: Converts a string to an integer.
 
### Function: PopulateAVector(file_name, menu)
Purpose: Populates the vector from the file.
 
### Function: DisplayInventory(menu)
Purpose: Prints all items from the vector.
 
### Function: DisplayItemsFilteredByCategory(menu, filter_category)
Purpose: Prints all items from specific category from the vector.
 
### Function: DisplayItemsFilteredByPrice(menu, min_price, max_price)
Purpose: Prints all items that fit price range from the vector.
 
### Function: ItemAddressByName(menu, item_name)
Purpose: Returns the address of the item.
 
### Function: SalePriceModification(menu, filter_category, discount)
Purpose: Sets discount price for all items from a specific category.
 
### Function: LowestStockQuantities(menu, k)
Purpose: Returns a vector of k items with low units in stock.
 
### Function: HighestPriceItems(menu, k)
Purpose: Returns a vector of k items with highest prices.
 
### Function: CreateCSV(menu)
Purpose: Writes a new CSV file.
 
### Function: CreateLowStockCSV(menu, output_file_name, stock_threshold)
Purpose: Writes a new CSV file with all items that have lower units than stock_threshold.
 
---
 
## Sample Input/Output
```
Input:
PopulateAVector("inventory.csv", menu);
DisplayItemsFilteredByCategory(menu, "Appetizer");
 
Output:
Name:           Caesar Salad
Category:       Appetizer
Price:          7
Stock:          15
```
---

## Testing
 
### Test Case 1
 
Input:
restaurant_analytics::StringToInteger("  42")
restaurant_analytics::StringToInteger("12ab")
 
Output:
42
String contains invalid characters.
 
### Test Case 2
 
Input:
restaurant_analytics::ItemAddressByName(menu, "Something that does not exist")
 
Output:
Item not found.
 
### Test Case 3
 
Input:
restaurant_analytics::SalePriceModification(menu, "Main", 0.50)
restaurant_analytics::DisplayItemsFilteredByCategory(menu, "Main")
 
Output:
Name:           Pastrami Sandwich
Category:       Main
Price:          7.5
Stock:          8
 
Name:           Steak Dinner
Category:       Main
Price:          12.5
Stock:          5
 
### Test Case 4
 
Input:
restaurant_analytics::LowestStockQuantities(menu, 3)
restaurant_analytics::DisplayInventory(low_3)
 
Output:
Name:           French Fries
Category:       Side
Price:          5
Stock:          0
 
Name:           Onion Rings
Category:       Side
Price:          6
Stock:          2
 
Name:           Strawberry Cheesecake
Category:       Dessert
Price:          9.5
Stock:          4
 
### Test Case 5
 
Input:
restaurant_analytics::CreateLowStockCSV(menu, "low_stock_5.csv", 5)
 
Output:
Strawberry Cheesecake,Dessert,9.5,4
French Fries,Side,5,0
Onion Rings,Side,6,2