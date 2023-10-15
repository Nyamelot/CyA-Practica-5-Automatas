// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas, Alfabetos y Símbolos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 21/09/2023

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <set>
#include <vector>
#include <string>

#include "transition.h"

class State {
 public:
  State(int number_state, bool final_state, int number_transitions, const std::vector<std::string>& transitions) {
    number_state_ = number_state;
    final_state_ = final_state;
    if (number_transitions > 0) {
      for (int i = 0; i < number_transitions; i++) {
        Transition transition(transitions[i][0],static_cast<int>(transitions[i][2]));
        transitions_.insert(transition);
      }
    }
  }


 private:
  int number_state_;
  bool final_state_;
  std::set<Transition> transitions_;
};

#endif