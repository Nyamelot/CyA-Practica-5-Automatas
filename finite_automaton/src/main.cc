// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023
// Archivo main.cc: programa principal

#include <iostream>
#include <fstream>
#include <iomanip>

#include "finite_automaton.h"
#include "menu.h"
#include "state.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_automaton_file(argv[1]);
  auto automaton = FiniteAutomaton::CreateFromFile(input_automaton_file);
  std::ifstream input_string_file(argv[2]);
  for (std::string line; std::getline(input_string_file, line);) {
    std::cout << std::left << std::setw(10) << line << ": ";
    std::cout << std::setw(10) << (automaton.Crawl(line) ? "Accepted 😊" : "Rejected 😔") << std::endl;
  }

  // Modification
  std::set<State> dead_states = automaton.DeadState();
  if (dead_states.size() != 0) {
    std::cout << "The dead states are: " << std::endl;
    for (const auto& dead_state : dead_states) {
      std::cout << dead_state << std::endl;
    }
  } else {
    std::cout << "There are no dead states" << std::endl;
  }
  return 0;
}
