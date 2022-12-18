#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  
  std::regex regularExpr("(\\s*\\d+\\s*)+");

  return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  
  std::stringstream ss(str);
  
  unsigned numero, soma = 0;

  while (ss >> numero) {
    soma += numero;
  }

  std::cout << soma << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {

  std::regex regularExpr("\\s*[a-zA-Z]+\\s*\\d+\\s*[a-zA-Z]+\\s*\\d+");

  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {

  std::stringstream ss(str);

  std::string timeCasa, timeVisitante;
  unsigned golsTimeCasa, golsTimeVisitante;

  ss >> timeCasa >> golsTimeCasa >> timeVisitante >> golsTimeVisitante;

  if (golsTimeCasa > golsTimeVisitante) {
    std::cout << "Vencedor: " << timeCasa << std::endl;
  } else if (golsTimeCasa < golsTimeVisitante) {
    std::cout << "Vencedor: " << timeVisitante << std::endl;
  } else {
    std::cout << "Empate" << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  
  std::stringstream ss(str);

  std::string palavra;

  unsigned count = 0;

  while (ss >> palavra) {
    count++;
  }

  std::cout << count << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {

  std::regex regularExpr("[^a-zA-Z\\s]");

  return !std::regex_search(str, regularExpr);
}

void InversorDeFrases::processaLinha(const std::string &str) {
  
  std::vector<std::string> frase;
  std::vector<std::string>::iterator it;

  std::stringstream ss(str);
  std::string palavra;

  while (ss >> palavra) {
    frase.push_back(palavra);
  }
  
  std::reverse(frase.begin(), frase.end());

  for (it = frase.begin(); it != frase.end(); ++it) {
    std::cout << *it << ' ';
  }

  std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {

  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  std::regex regularExpr(dateFormat);

  return std::regex_match(str, regularExpr);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  
  std::vector<std::string> meses ({"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"});

  std::string dia = "", mes = "", ano = "";
  bool ehDia = true, ehMes = false;

  for (unsigned i = 0; i < str.size(); i++) {
    if (str[i] == '/' && ehDia) {
      ehDia = false;
      ehMes = true;
      continue;
    } else if (str[i] == '/' && !ehDia) {
      ehMes = false;
      continue;
    }
    if (ehDia) {
      dia.push_back(str[i]);
    }
    if (ehMes) {
      mes.push_back(str[i]);
    }
    if (!ehDia && !ehMes) {
      ano.push_back(str[i]);
    }
  }
  std::cout << meses[std::stoi(mes) - 1] << std::endl;

}