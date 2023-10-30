#include "model/paciente.hpp"
#include "model/usuario.hpp"

namespace mediapp::model {
Paciente::Paciente(std::string plano_saude, std::string email, InfoPessoal info)
  : Usuario(email, info), _plano_saude(plano_saude) {}

std::string Paciente::plano_saude() const {
  return _plano_saude;
}
}
