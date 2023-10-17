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


void FiniteAutomaton::AddState(const State& state) {
  if (!states_.count(state)) {
    states_.insert({ state, std::set<State>() });
    states_.at(state) = std::set<State>();
  }
}

void FiniteAutomaton::AddTransition(const State& from, const State& to, const char& condition) {
  if (!states_.count(from)) {
    AddState(from);
  }
  if (!states_.count(to)) {
    AddState(to);
  }
  if (!transitions_.count({ from, to })) {
    auto conditions = std::set { condition };
    transitions_.insert({ { from, to }, conditions });
    states_.at(from).emplace(to);
  } else {
    transitions_.at({ from, to }).emplace(condition);
  }
}

void FiniteAutomaton::SetFinal(const State& state) {
  final_states_.emplace(state);
}

void FiniteAutomaton::SetInitial(const State& state) {
  initial_state_ = state;
}

bool FiniteAutomaton::Crawl(const std::string& input) {
  auto current_states = std::set { initial_state_ };
  for (const auto& symbol : input) {
    auto next_states = std::set<State>();
    for (const auto& current_state : current_states) {
      for (const auto& adyecent_state : states_.at(current_state)) {
        const auto& transition = transitions_.at({current_state, adyecent_state});
        if (
          transition.count(symbol) || 
          transition.count('&')
        ) {
          next_states.emplace(adyecent_state);
        }
      }
    }
    current_states = next_states;
  }
  for (const auto& state : current_states) {
    if (final_states_.count(state)) {
      return true;
    }
  }
  return false;
}

