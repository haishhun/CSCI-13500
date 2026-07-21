#include <string>

class MenuItem {
 public:
  MenuItem();
  ~MenuItem();

  std::string GetName();
  void SetName(std::string new_name);

  std::string GetCategory();
  void SetCategory(std::string new_category);

  double GetPrice();
  void SetPrice(double new_price);

  int GetStock();
  void SetStock(int new_stock);

  void PrintItem();

 private:
  std::string name = "";
  std::string category = "";
  double price = 0.0;
  int stock = 0;
};