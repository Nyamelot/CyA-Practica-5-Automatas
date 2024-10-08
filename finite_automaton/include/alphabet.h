// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023
// Archivo alphabet.h: Contiene la clase Alphabet que representa el alfabeto de un automata finito

#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>
#include <iostream>
#include <string>

class Alphabet {
 public:
  //Constructor

  
  Alphabet(std::string strings) {
    for (const auto& symbol : strings) {
      if (symbol != ' ' || symbol != '&') {
        alphabet_.emplace(symbol);
      }
    }
  }
  
  //Getter
  inline const std::set<char> GetAlphabet() const { return alphabet_; }

  //Operator Overloading
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);

 private:
  std::set<char> alphabet_;
};

#endif
