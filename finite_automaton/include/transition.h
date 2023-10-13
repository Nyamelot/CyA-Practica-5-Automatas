// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas, Alfabetos y Símbolos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 21/09/2023

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>

class Transition {
 public:
  Transition(char symbol, int next_state) : symbol_(symbol), next_state_(next_state) {}

  

 private:
  char symbol_;
  int next_state_;
};

#endif