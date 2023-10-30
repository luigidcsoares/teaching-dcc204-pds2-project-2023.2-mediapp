#pragma once

#include "model/usuario.hpp"
#include <string>

namespace mediapp::model {
class Paciente : public Usuario {
public:
  Paciente(std::string _plano_saude, std::string email,
	   InfoPessoal info);
  
  std::string plano_saude() const;
  
private:
  std::string _plano_saude;
};
}
