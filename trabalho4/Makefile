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
Grafos1: $(HEADERS) grafo vertice lerArquivo
	g++ $(FLAGS) -o Grafos4.exe $(SRC_DIR)/main.cpp *.o

# .o's
grafo: $(HEADERS) $(SRC_DIR)/grafo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/grafo.cpp

vertice: $(HEADERS) $(SRC_DIR)/vertice.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/vertice.cpp

lerArquivo: $(HEADERS) $(SRC_DIR)/lerArquivo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/lerArquivo.cpp
	
clean:
	rm *.o