#include "ui/login_menu.hpp"

#include <iostream>
#include <limits>

namespace ui = mediapp::ui;
int main() {
  long int const max_input =
    std::numeric_limits<std::streamsize>::max();
  
  ui::LoginMenu login;
  login.render();
  
  unsigned option;
  std::cin >> option;
  std::cin.ignore(max_input, '\n');

  ui::Menu *menu = login.next(option);
  return 0;
}
