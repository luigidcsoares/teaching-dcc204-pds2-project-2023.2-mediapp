#pragma once

#include "model/usuario.hpp"
#include "model/medico.hpp"
#include "repository/medico.hpp"

#include <string>

namespace mediapp::repository {
class MedicoFake : public Medico {
public:
  std::vector<model::Medico> obter_todos() const override;
  model::Medico *buscar(std::string const &email) const override;
  bool deletar(std::string const &email) const override;
  bool salvar(model::Medico const &medico) const override;
};
}
