#pragma once
#include <string>

namespace mediapp::model {
struct InfoPessoal {
  std::string primeiro_nome;
  std::string sobrenome;
  unsigned idade;
};

class Usuario {
public:
  Usuario(std::string email, InfoPessoal info);

  std::string email() const;
  std::string nome() const;
  unsigned idade() const;

  virtual std::string to_string() const;
  
private:
  std::string _email;
  InfoPessoal _info;
};
}
