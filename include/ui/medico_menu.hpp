#pragma once

#include "ui/menu.hpp"
#include "model/medico.hpp"

#include <string>

namespace mediapp::ui {
class MedicoMenu : public Menu {
public:
  MedicoMenu(model::Medico const &medico);
  Menu *next(unsigned option) override;
private:
  model::Medico const &_medico;
};
}
