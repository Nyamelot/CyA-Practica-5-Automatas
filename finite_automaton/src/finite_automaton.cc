/// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

#include <iostream>

#include "finite_automaton.h"
#include "state.h"

bool FiniteAutomaton::AddState(const State& state) {
  if (!states_.count(state)) {
    states_.emplace(state, std::vector<State>());
  }
}

bool FiniteAutomaton::AddTransition(const State& from, const State& to, const char& condition) {
  if (!states_.count(from)) {
    AddState(from);
  }
  if (!states_.count(to)) {
    AddState(to);
  }
  if (!transitions_.count(std::make_pair(from, to))) {
    auto conditions = std::set { condition };
    transitions_.emplace(std::make_pair(from, to), conditions);
    states_.at(from).emplace_back(to);
  } else {
    transitions_.at(std::make_pair(from, to)).emplace(condition);
  }
}