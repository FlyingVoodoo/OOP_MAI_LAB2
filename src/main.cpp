#include "decimal.h"
#include <iostream>
#include <string>

// не вайб код :)

int main() {
  std::string a_str;
  std::string b_str;
  std::cin >> a_str;
  std::cin >> b_str;

  Decimal a(a_str);
  Decimal b(b_str);
  
  Decimal res_plus = plus(a, b);
  std::cout << "Сумма: ";
  res_plus.print();
  std::cout << std::endl;
  
  Decimal res_sub = sub(a, b);
  std::cout << "Разность: ";
  res_sub.print();
  std::cout << std::endl;
  
  return 0;
}
