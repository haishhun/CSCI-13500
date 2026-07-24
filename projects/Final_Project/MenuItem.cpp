#include "MenuItem.h"

#include <iostream>

/* Default constructor.*/
MenuItem::MenuItem() {}

/* Parameterized constructor.*/
MenuItem::MenuItem(std::string new_name, std::string new_category,
                   double new_price, int new_stock)
    : name(new_name),
      category(new_category),
      price(new_price),
      stock(new_stock) {}

/* Destructor.*/
MenuItem::~MenuItem() {}

/* Returns the name of the item. */
std::string MenuItem::GetName() const { return name; }

/* Sets the name of the item. */
void MenuItem::SetName(std::string new_name) { name = new_name; }

/* Returns the category of the item.*/
std::string MenuItem::GetCategory() const { return category; }

/* Sets the category of the item. */
void MenuItem::SetCategory(std::string new_category) {
  category = new_category;
}

/* Returns the current price of the item. */
double MenuItem::GetPrice() const { return price; }

/* Sets the price of the item. */
void MenuItem::SetPrice(double new_price) { price = new_price; }

/* Returns how many units of the item are in stock. */
int MenuItem::GetStock() const { return stock; }

/* Sets how many units of the item are in stock. */
void MenuItem::SetStock(int new_stock) { stock = new_stock; }

/* Prints the name, category, price, and stock of the item.*/
void MenuItem::PrintItem() const {
  std::cout << "Name:\t\t" << name << std::endl;
  std::cout << "Category:\t" << category << std::endl;
  std::cout << "Price:\t\t" << price << std::endl;
  std::cout << "Stock:\t\t" << stock << std::endl << std::endl;
}
