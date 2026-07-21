#include <string>

class MenuItem {
 public:
  MenuItem();
  ~MenuItem();

  std::string GetName() const;
  void SetName(std::string new_name);

  std::string GetCategory() const;
  void SetCategory(std::string new_category);

  double GetPrice() const;
  void SetPrice(double new_price);

  int GetStock() const;
  void SetStock(int new_stock);

  void PrintItem() const;

 private:
  std::string name = "";
  std::string category = "";
  double price = 0.0;
  int stock = 0;
};