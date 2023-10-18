// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Simulador de automatas finitos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 13/10/2023
// Archivo menu.cc: Contiene la implementación de la clase Menu.

#include "menu.h"

const std::string kTitle = "P05-finite-automaton";
const std::string kHelpText =
"  \n\033[1m>> Example:\033[0m"\
"    ./a.out input.fa input.txt\n"\
  
"  \033[1m>> Parameters:\033[0m\n"\
"     - \033[1minput.fa:\033[0m is the automaton to be parsed\n"\
"     - \033[1minput.txt:\033[0m is the text to be run on the automaton\n"\
  
"  \033[1m>> Output:\033[0m\n"\
"    The program will output the result of the automaton on the text, either"\
" accepted or rejected.\n";

std::vector<std::string> FileReader(std::ifstream& input_files) {
  std::vector<std::string> text_file;
  std::string text_line;
  while (!input_files.eof()) {
    std::getline(input_files, text_line);
    text_file.emplace_back(text_line);
  }
  return text_file;
}

std::vector<std::string> NoSpacesStrings(const std::vector<std::string>& strings) {
  std::vector<std::string> strings_without_spaces;
  std::string string_without_spaces;
  for (const auto& string : strings) {
    for (const auto& character : string) {
      if (character != ' ') {
        string_without_spaces.push_back(character);
      }
    }
    strings_without_spaces.emplace_back(string_without_spaces);
  }
  return strings_without_spaces;
}




void Usage(int argc, char* argv[]) {
  const std::string kHelp = "--help";
  if (argc == 1) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "How to use: " << argv[0]
              << " input.fa input.txt"
              << std::endl;
    std::cerr << "Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[1] == kHelp) {
    std::cout << kTitle << std::endl;
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc > 3) || ((argc < 3))) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "How to use: " << argv[0]
              << " input.fa input.txt"
              << std::endl;
    std::cerr << "Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
}