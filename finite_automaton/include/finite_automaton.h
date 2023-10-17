// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

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
  // Constructor
  FiniteAutomaton(const Alphabet& alphabet, int number_states, const State& start_state) 
    : alphabet_(alphabet), number_states_(number_states), start_state_(start_state) {}  

  // Getters 
  inline const Alphabet GetAlphabet() const { return; }
  inline const int GetNumberStates() const { return; }
  inline const State GetStartState() const { return; }
  inline const std::map<State, std::vector<State>> GetStates() const { return; }
  inline const std::map<std::pair<State, State>, char> GetTransitions() const { return; }

  // Methods
  bool AddState(const State& state);
  bool AddTransition(const State& from, const State& to, const char& condition);
  

  

 private:
  Alphabet alphabet_;
  int number_states_;
  State start_state_;
  std::map<State, std::vector<State>> states_;
  std::map<std::pair<State, State>, std::set<char>> transitions_;
};

#endif
