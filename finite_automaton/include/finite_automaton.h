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
  FiniteAutomaton(const std::vector<std::string>& file_path) : alphabet_(file_path[0]) {
    number_states_ = static_cast<int>(file_path[1][0]);
    start_state_ = static_cast<int>(file_path[2][0]);
    for (int i = 3; i < file_path.size(); i++) {
      int state_key = static_cast<int>(file_path[i][0]);
      bool final_state = static_cast<bool>(file_path[i][2]);
      int number_transitions = static_cast<int>(file_path[i][0]);
      if (number_transitions = 0) {
        State state(state_key, final_state, number_transitions);
        states_.insert(state_key, State);
      } else {
        std::vector<std::string> transitions;
        std::string transition;
        int counter = 0;
        for (int j = 6; 6 < file_path[i].length(); j++) {
          if (file_path[i][j] != ' ') {
            transition.push_back(file_path[i][j]);
            counter++;
          }
          if (counter == 2) {
            counter = 0;
            transitions.emplace_back(transition);
          }
        }
        State state(state_key, final_state, number_transitions, transitions);
        states_.insert(state_key, state);
      }
    }
  }

  

 private:
  Alphabet alphabet_;
  int number_states_;
  int start_state_;
  std::map<int, State> states_;
};

#endif
