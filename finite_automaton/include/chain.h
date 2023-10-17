// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <vector>
#include <string>

#include "alphabet.h"

class Chain {
 public:
  // Constructor
  explicit Chain (const std::string& chain) : chain_(chain), alphabet_(chain) {}

  // Getters
  inline const Alphabet GetAlphabet() const { return alphabet_; }

  // Functions
  std::vector<Chain> Prefix();
  std::vector<Chain> Suffix();
  Chain Invert();
  int Length();

  // Operator Overloading
  friend std::ostream& operator<<(std::ostream& out, const Chain& chain);

 private:
  Alphabet alphabet_;
  std::string chain_;
};

#endif
