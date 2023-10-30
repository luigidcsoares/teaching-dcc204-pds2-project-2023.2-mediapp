#include "service/medico.hpp"
#include "model/medico.hpp"
#include "repository/medico.hpp"

#include <string>

namespace mediapp::service {
Medico::Medico(repository::Medico const &repo) : _repo(repo) {}

model::Medico *Medico::autenticar(std::string const &email) const {
  // TODO: Verificar senha
  // TODO: Buscar notificações, outras informações, etc
  return _repo.buscar(email);
}
}
