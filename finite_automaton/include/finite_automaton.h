// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023
// Archivo finite_automaton.h: contiene la definición de la clase

#ifndef FINITE_AUTOMATON_H
#define FINITE_AUTOMATON_H

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <fstream>


#include "alphabet.h"
#include "state.h"

/// ## Descripción
/// Clase que representa un autómata finito
class FiniteAutomaton {
 public:
  // Constructor
  FiniteAutomaton(const Alphabet& alphabet) 
    : alphabet_(alphabet) {}  

  // Getters
  inline const Alphabet GetAlphabet() const { return alphabet_; }
  inline const int GetNumberStates() const { return states_.size(); }
  inline const State GetInitialState() const { return initial_state_; }
  inline const std::map<State, std::set<State>> GetStates() const { return states_; }
  inline const std::map<std::pair<State, State>, std::set<char>> GetTransitions() const { return transitions_; }

  // Methods
  void AddState(const State& state);
  void AddTransition(const State& from, const State& to, const char& condition);
  void SetFinal(const State& state);
  void SetInitial(const State& state);
  bool Crawl(const std::string&  input);
  static FiniteAutomaton CreateFromFile(std::ifstream& input_file);

  // Modification
  std::set<State> DeadState();


 private:
  Alphabet alphabet_;
  State initial_state_;
  std::set<State> final_states_;
  std::map<State, std::set<State>> states_;
  std::map<std::pair<State, State>, std::set<char>> transitions_;
};

#endif
