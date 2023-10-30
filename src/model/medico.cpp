#include "model/medico.hpp"
#include "model/usuario.hpp"
#include <string>

namespace mediapp::model {
Medico::Medico(RegistroCRM reg_crm, std::string especialidade,
	       std::string email, InfoPessoal info)
  : Usuario(email, info), _reg_crm(reg_crm), _especialidade(especialidade) {}

std::string Medico::crm() const {
  return "CRM/" + _reg_crm.estado_crm + " " + _reg_crm.id_crm;
}

std::string Medico::especialidade() const {
  return _especialidade;
}

std::string Medico::to_string() const {
  return Usuario::to_string() + " (" + crm() + ", " + _especialidade + ")";
}
}
