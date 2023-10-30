#pragma once

#include <string>
#include <vector>

namespace mediapp::ui {
class Menu {
public:
  /// @brief Destrutor virtual, para correta destruição de filhos.
  virtual ~Menu() {}

  /// @return O próximo menu, a partir da seleção do usuário.
  virtual Menu *next(unsigned option) = 0;

  /// @brief Renderiza as opções do menu.
  virtual void render() const;
  
protected:
  std::string _title = "Menu de Opções";
  std::vector<std::string> _options = {"0 - Sair"};
};
}
