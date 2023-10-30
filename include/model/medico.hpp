#pragma once

#include "model/usuario.hpp"
#include <string>

namespace mediapp::model {
struct RegistroCRM {
  std::string id_crm;
  std::string estado_crm;
};

class Medico : public Usuario {
public:
  Medico(RegistroCRM reg_crm, std::string especialidade,
	 std::string email, InfoPessoal info);
  
  std::string crm() const;
  std::string especialidade() const;
  std::string to_string() const override;
  
private:
  RegistroCRM _reg_crm;
  std::string _especialidade;
};
}
