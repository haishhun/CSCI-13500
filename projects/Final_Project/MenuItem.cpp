#include "MenuItem.h"

#include <iostream>

MenuItem::MenuItem() {}
MenuItem::~MenuItem() {}

std::string MenuItem::GetName() const { return name; }
void MenuItem::SetName(std::string new_name) { name = new_name; }

std::string MenuItem::GetCategory() const { return category; }
void MenuItem::SetCategory(std::string new_category) {
  category = new_category;
}

double MenuItem::GetPrice() const { return price; }
void MenuItem::SetPrice(double new_price) { price = new_price; }

int MenuItem::GetStock() const { return stock; }
void MenuItem::SetStock(int new_stock) { stock = new_stock; }

void MenuItem::PrintItem() const {
  std::cout << "Name:\t\t" << name << std::endl;
  std::cout << "Category:\t" << category << std::endl;
  std::cout << "Price:\t\t" << price << std::endl;
  std::cout << "Stock:\t\t" << stock << std::endl << std::endl;
}
