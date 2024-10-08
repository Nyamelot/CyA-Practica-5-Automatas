// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023
// Archivo state.h: Contiene la clase State que representa un estado de un autómata finito

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <set>
#include <vector>
#include <string>

/// ## Descripción
/// Clase que representa un estado de un autómata finito
class State {
 public:
  // Constructor
  State() : id_("") {}
  State(std::string id) : id_(id) {}
  
  // Getter
  const std::string GetId() const { return id_; }

  // Operator Overloading
  bool operator>(const State& state1) const;
  bool operator<(const State& state1) const;
  bool operator==(const State& state1) const;
  bool operator!=(const State& state1) const;
  friend std::ostream& operator<<(std::ostream& out, const State& state);

 private:
  std::string id_;
};

#endif