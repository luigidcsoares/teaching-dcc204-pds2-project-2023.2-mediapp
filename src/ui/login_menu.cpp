#include "ui/login_menu.hpp"
#include "ui/medico_menu.hpp"

#include "model/medico.hpp"
#include "model/paciente.hpp"
#include "model/usuario.hpp"

#include "repository/medico_fake.hpp"
#include "service/medico.hpp"

#include <iostream>
#include <string>

namespace mediapp::ui {
LoginMenu::LoginMenu() {
  _title = "Menu de Autenticação";
  _options.push_back("1 - Entrar");
  _options.push_back("2 - Cadastrar Paciente");
  _options.push_back("3 - Cadastrar Médico");
}

Menu *LoginMenu::next(unsigned option) {
  auto ler_autenticacao = [](std::string &email) {
    std::cout << "> Email: ";
    std::cin >> email;
  };

  auto ler_info_pessoal = [](model::InfoPessoal &info) {
    std::cout << "> Primeiro nome: ";
    std::cin >> info.primeiro_nome;

    std::cout << "> Sobrenome: ";
    std::cin >> info.sobrenome;

    std::cout << "> Idade: ";
    std::cin >> info.idade;
  };

  repository::MedicoFake r_medico;
  service::Medico s_medico(r_medico);
 
  switch (option) {
  case 1: {
    char tipo;
    std::cout << "> Tipo de usuário (p: paciente, m: médico): ";
    std::cin >> tipo;

    std::string email;
    ler_autenticacao(email);

    std::cout << "Logando: " << email << std::endl;

    if (tipo == 'm') {
      model::Medico *medico = s_medico.autenticar(email);
      // if (medico == nullptr) ...
      return new MedicoMenu(*medico);
    } else {
      // TODO: paciente
    }
      
    break;
  }
  case 2: {
    std::string plano_saude;
    std::cout << "> Plano de Saúde: ";
    std::cin >> plano_saude;
    
    std::string email;
    ler_autenticacao(email);

    model::InfoPessoal info;
    ler_info_pessoal(info);
    
    model::Paciente paciente(plano_saude, email, info);
    std::cout << "Salvando paciente: " << paciente.to_string() << std::endl;
    break;
  }
  case 3: {
    model::RegistroCRM reg_crm;
    
    std::cout << "> ID CRM: ";
    std::cin >> reg_crm.id_crm;

    std::cout << "> Estado CRM: ";
    std::cin >> reg_crm.estado_crm;

    std::string especialidade;
    std::cout << "> Especialidade: ";
    std::cin >> especialidade;

    std::string email;
    ler_autenticacao(email);

    model::InfoPessoal info;
    ler_info_pessoal(info);

    model::Medico medico(reg_crm, especialidade, email, info);
    std::cout << "Salvando Médico: " << medico.to_string() << std::endl;

    return new MedicoMenu(medico);
  }
  }

  // TODO: próximo menu
  return nullptr;
}
}
