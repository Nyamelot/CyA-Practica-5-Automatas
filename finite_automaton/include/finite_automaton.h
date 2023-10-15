// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas, Alfabetos y Símbolos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 21/09/2023

#ifndef FINITE_AUTOMATON_H
#define FINITE_AUTOMATON_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "alphabet.h"
#include "state.h"

class FiniteAutomaton {
 public:
  FiniteAutomaton(std::vector<std::string> file_path) {
    for (int i = 0)
  }

 private:
  Alphabet alphabet_;
  int number_states_;
  int start_state_;
  std::map<int, State> states_;
};

#endif
