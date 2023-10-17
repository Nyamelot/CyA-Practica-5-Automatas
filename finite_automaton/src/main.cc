// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

#include <iostream>


#include "finite_automaton.h"

int main(int argc, char* argv[]) {
  // auto automaton = FiniteAutomaton::CreateFromFile(argv[1]);
  auto automaton = FiniteAutomaton(Alphabet(""));
  automaton.AddTransition(State("q0"), State("q0"), '0');
  automaton.AddTransition(State("q0"), State("q0"), '1');
  automaton.AddTransition(State("q0"), State("q1"), '1');
  automaton.AddTransition(State("q1"), State("q2"), '0');
  automaton.AddTransition(State("q1"), State("q2"), '1');
  automaton.AddTransition(State("q2"), State("q3"), '0');
  automaton.AddTransition(State("q2"), State("q3"), '1');
  automaton.SetFinal(State("q3"));
  automaton.SetInitial(State("q0"));
  std::cout << automaton.Crawl("&") << std::endl;

  return 0;
}
