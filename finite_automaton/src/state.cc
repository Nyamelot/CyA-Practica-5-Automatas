/// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023
// Archivo state.cc: contiene la implementación de los métodos de la clase State.

#include <iostream>
 
#include "state.h"

bool State::operator>(const State& state1) const {
  return id_ > state1.id_;
}

bool State::operator<(const State& state1) const {
  return id_ < state1.id_;
}

bool State::operator==(const State& state1) const {
  return id_ == state1.id_;
}

bool State::operator!=(const State& state1) const {
  return id_ != state1.id_;
}

std::ostream& operator<<(std::ostream& out, const State& state) {
  out << state.id_;
  return out;
}
