#include "MenuItem.h"

#include <iostream>

MenuItem::MenuItem() {}
MenuItem::~MenuItem() {}

std::string MenuItem::GetName() { return name; }
void MenuItem::SetName(std::string new_name) { name = new_name; }

std::string MenuItem::GetCategory() { return category; }
void MenuItem::SetCategory(std::string new_category) {
  category = new_category;
}

double MenuItem::GetPrice() { return price; }
void MenuItem::SetPrice(double new_price) { price = new_price; }

int MenuItem::GetStock() { return stock; }
void MenuItem::SetStock(int new_stock) { stock = new_stock; }

void MenuItem::PrintItem() {
  std::cout << "Name:\t\t" << name << std::endl;
  std::cout << "Category:\t\t" << category << std::endl;
  std::cout << "Price:\t\t" << price << std::endl;
  std::cout << "Stock:\t\t" << stock << std::endl;
}
