// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023
// Archivo menu.h: Contiene la declaración de las funciones de menu.cc

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void Usage(int argc, char* argv[]);
std::vector<std::string> FileReader(std::ifstream& input_files);
std::vector<std::string> NoSpacesStrings(const std::vector<std::string>& strings);
