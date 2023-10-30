#pragma once

#include "ui/menu.hpp"
#include <string>

namespace mediapp::ui {
class LoginMenu : public Menu {
public:
  /// @brief Constrói um menu de login.
  LoginMenu();

  /// @brief Constrói próximo menu (criação de conta ou login)
  /// @return O próximo menu, a partir da seleção do usuário.
  Menu *next(unsigned option) override;
};
}
