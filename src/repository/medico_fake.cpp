#include "repository/medico_fake.hpp"

#include "model/usuario.hpp"
#include "model/medico.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace mediapp::repository {
std::vector<model::Medico> MedicoFake::obter_todos() const {
  // TODO
  return {};
}

model::Medico *MedicoFake::buscar(std::string const &email) const {
  model::RegistroCRM reg_crm = {"123456", "SP"};
  model::InfoPessoal info = {"Dráuzio", "Varela", 80};
  return new model::Medico(reg_crm, "Oncologia", email, info);
}

bool MedicoFake::deletar(std::string const &email) const {
  // TODO
  return false;
}

bool MedicoFake::salvar(model::Medico const &medico) const {
  // TODO
  return false;
}
}
