#include "ui/medico_menu.hpp"

#include "model/medico.hpp"

#include <iostream>
#include <string>

namespace mediapp::ui {
MedicoMenu::MedicoMenu(model::Medico const &medico) : _medico(medico) {
  _title = medico.to_string();
  _options.push_back("1 - Visualizar Consultas");
  _options.push_back("2 - Pesquisar Paciente");
}

Menu *MedicoMenu::next(unsigned option) {
  switch (option) {
  case 1: {
    std::cout << "Visualizando consultas" << std::endl;
    break;
  }
  case 2: {
    std::string email;
    std::cout << "> Email: ";
    std::cin >> email;
    std::cout << "Pesquisando consultas de " << email << std::endl;
    break;
  }
  }

  // TODO: próximo menu
  return nullptr;
}
}
