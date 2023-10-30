#pragma once

#include "model/medico.hpp"

#include <string>
#include <vector>

namespace mediapp::repository {
class Medico {
public:
  virtual std::vector<model::Medico> obter_todos() const = 0;
  virtual model::Medico *buscar(std::string const &email) const = 0;
  virtual bool deletar(std::string const &email) const = 0;
  virtual bool salvar(model::Medico const &medico) const = 0;
  virtual ~Medico() = default;
};
}
