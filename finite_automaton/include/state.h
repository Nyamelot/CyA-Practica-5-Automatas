// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <set>
#include <vector>
#include <string>

#include "transition.h"

class State {
 public:
  // Constructor
  State(std::string id) : id_(id) {}
    
 
  bool operator>(const State& state1);
  bool operator<(const State& state1);
  bool operator==(const State& state1);
  bool operator!=(const State& state1);

 private:
  std::string id_;
};

#endif