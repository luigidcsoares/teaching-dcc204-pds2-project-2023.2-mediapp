#pragma once

#include "model/medico.hpp"
#include "repository/medico.hpp"

#include <string>

namespace mediapp::service {
class Medico {
public:
  Medico(repository::Medico const &repo);
  model::Medico *autenticar(std::string const &email) const;
  
private:
  repository::Medico const &_repo;
};
}
