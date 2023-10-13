// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023

#include <iostream>

#include "alphabet.h"

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  out << "{";
  bool comma = true;
   for (const auto& symbol : alphabet.GetAlphabet()) {
     if (!comma) {
      out << ", ";
     }
     out << symbol;
     comma = false;
   }
  out << "}";
  return out;
}