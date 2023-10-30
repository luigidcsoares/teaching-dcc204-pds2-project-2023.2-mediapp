#include "model/usuario.hpp"
#include <string>

namespace mediapp::model {
Usuario::Usuario(std::string email, InfoPessoal info)
  : _email(email), _info(info) {}

std::string Usuario::email() const {
  return _email;
}

std::string Usuario::nome() const {
  return _info.primeiro_nome + " " + _info.sobrenome;
}

unsigned Usuario::idade() const {
  return _info.idade;
}

std::string Usuario::to_string() const {
  return nome() + " (" + email() + ", " + std::to_string(idade()) + " anos)";
}
}
