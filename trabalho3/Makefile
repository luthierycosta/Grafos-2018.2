### Makefile ###
# por: Luthiery C. Cavalcante
# original por: Rafael G. de Paulo


# variaveis
FLAGS  		= -std=c++11 -Wall -g
HEADERS_DIR = headers
SRC_DIR		= src
HEADERS 	= $(wildcard $(HEADERS_DIR)/*.h)
OBJ			= $(wildcard *.o)

# all
all: Grafos1 clean

# executavel
Grafos1: $(HEADERS) grafo vertice escola professor lerArquivo matching
	g++ $(FLAGS) -o Grafos3.exe $(SRC_DIR)/main.cpp *.o

# .o's
grafo: $(HEADERS) $(SRC_DIR)/grafo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/grafo.cpp

vertice: $(HEADERS) $(SRC_DIR)/vertice.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/vertice.cpp

escola: $(HEADERS) $(SRC_DIR)/escola.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/escola.cpp

professor: $(HEADERS) $(SRC_DIR)/professor.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/professor.cpp

lerArquivo: $(HEADERS) $(SRC_DIR)/lerArquivo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/lerArquivo.cpp

matching: $(HEADERS) $(SRC_DIR)/matching.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/matching.cpp
	
clean:
	rm *.o