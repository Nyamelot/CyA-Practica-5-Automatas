// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <set>

class Transition {
 public:
  Transition(std::set<char> symbol) : symbol_(symbol) {}

  

 private:
  std::set<char> symbol_;
};

#endif