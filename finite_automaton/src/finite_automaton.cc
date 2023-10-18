/// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "finite_automaton.h"
#include "state.h"
#include "menu.h"
#include "alphabet.h"

/// ## Descripción
/// Añade un estado al autómata
/// ## Argumentos
/// * `state` - Estado a añadir
void FiniteAutomaton::AddState(const State& state) {
  if (!states_.count(state)) {
    states_.insert({ state, std::set<State>() });
    states_.at(state) = std::set<State>();
  }
}

/// ## Descripción
/// Añade una transición al autómata
/// ## Argumentos
/// * `from` - Estado de partida
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

/// ## Descripción
/// Establece un estado como final
/// ## Argumentos
/// * `state` - Estado final
void FiniteAutomaton::SetFinal(const State& state) {
  final_states_.emplace(state);
}

/// ## Descripción
/// Establece el estado inicial del autómata
/// ## Argumentos
/// * `state` - Estado inicial
void FiniteAutomaton::SetInitial(const State& state) {
  initial_state_ = state;
}

/// ## Descripción
/// Comprueba si un string es aceptado por el autómata
/// ## Argumentos
/// * `input` - String a comprobar
/// ## Devuelve
/// * `true` - Si el string es aceptado
/// * `false` - Si el string no es aceptado
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

/// ## Descripción
/// Divide un string en un vector de strings utilizando un delimitador
/// ## Argumentos
/// * `input` - String a dividir
/// * `delimiter` - Delimitador a utilizar
/// ## Devuelve
/// * `std::vector<std::string>` - Vector de strings resultante
std::vector<std::string> SplitString(const std::string& input, const char& delimiter) {
  std::vector<std::string> result;
  std::string current_string;
  for (const auto& character : input) {
    if (character == delimiter) {
      result.emplace_back(current_string);
      current_string.clear();
    } else {
      current_string += character;
    }
  }
  result.emplace_back(current_string);
  return result;
}

/// ## Descripción
/// Lee un fichero de texto y lo devuelve en un vector de strings
/// ## Argumentos
/// * `input_file` - Fichero de texto a leer
/// ## Formato del fichero
/// ```txt
/// 0 1 Alfabeto
/// 4   Numero de Estados
/// 0   Estado de arranque
/// 0 0 3 0 0 1 0 1 1
/// | | | | |
/// Nombre de estado
/// - | Si es estado de aceptación o no
/// -   | Número de transiciones
/// - {   | Condición de transición } 
/// - {     | Estado adyacente      } 
///   Se repite el número de transiciones *veces*
/// 1 0 2 0 2 1 2
/// 2 0 2 0 3 1 3
/// 3 1 0
/// ```
FiniteAutomaton FiniteAutomaton::CreateFromFile(std::ifstream& input_file) {
  std::vector<std::string> text_file = FileReader(input_file);
  Alphabet alphabet = text_file[0];
  auto result = FiniteAutomaton(alphabet);
  int number_states = std::stoi(text_file[1]);
  result.SetInitial(text_file[2]);
  for (int i = 3; i < text_file.size(); i++) {
    std::vector<std::string> state_info = SplitString(text_file[i], ' ');
    State current_state = state_info[0];
    bool is_final = (state_info[1] == "1");
    result.AddState(current_state);
    if (is_final) {
      result.SetFinal(current_state);
    }
    int num_transitions = std::stoi(state_info[2]);
    for (int j = 0; j < num_transitions; j++) {
      char transition_char = state_info[3 + 2*j][0];
      State next_state = state_info[4 + 2*j];
      result.AddTransition(current_state, next_state, transition_char);
    }
  }
  if (number_states != result.GetNumberStates()) {
    std::cerr << "The number of states doesn't match the actual states" << std::endl;
    exit(EXIT_FAILURE);
  }
  return result;
}
