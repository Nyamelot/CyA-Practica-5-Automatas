PROJECT_NAME=practica_5
DIRPATH=$(shell realpath .)
DIRNAME=$(shell basename $(DIRPATH))

cmake:
	cmake -S . -B build

build: cmake
	cd build; make

clean:
	rm -rf build

tar:
	cd ..; tar cvfz $(DIRNAME)/p05_JoseAngel_PortilloGarcia-$(NAME).tar.gz --exclude-from=./$(DIRNAME)/.gitignore $(DIRNAME)