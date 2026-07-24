#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
 public:
  /* Default constructor.*/
  MenuItem();

  /* Parameterized constructor.*/
  MenuItem(std::string new_name, std::string new_category, double new_price,
           int new_stock);

  /* Destructor.*/
  ~MenuItem();

  /* Returns the name of the item. */
  std::string GetName() const;

  /* Sets the name of the item. */
  void SetName(std::string new_name);

  /* Returns the category of the item.*/
  std::string GetCategory() const;

  /* Sets the category of the item. */
  void SetCategory(std::string new_category);

  /* Returns the current price of the item. */
  double GetPrice() const;

  /* Sets the price of the item. */
  void SetPrice(double new_price);

  /* Returns how many units of the item are in stock. */
  int GetStock() const;

  /* Sets how many units of the item are in stock. */
  void SetStock(int new_stock);

  /* Prints the name, category, price, and stock of the item.*/
  void PrintItem() const;

 private:
  std::string name = "";
  std::string category = "";
  double price = 0.0;
  int stock = 0;
};

#endif