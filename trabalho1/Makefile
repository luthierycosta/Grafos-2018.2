### Makefile ###
# por: Luthiery C. Cavalcante
# original por: Rafael G. de Paulo


# variaveis
FLAGS  		= -std=c++11 -Wall -g
HEADERS_DIR = headers
SRC_DIR		= src
HEADERS 	= $(wildcard $(HEADERS_DIR)/*.h)

# all
all: Grafos1 clean

# executavel
Grafos1: $(HEADERS) grafo vertice lerArquivo imprime
	g++ $(FLAGS) -o Grafos1.exe $(SRC_DIR)/main.cpp grafo.o vertice.o lerArquivo.o imprime.o

# .o's
grafo: $(HEADERS) $(SRC_DIR)/grafo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/grafo.cpp

vertice: $(HEADERS) $(SRC_DIR)/vertice.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/vertice.cpp

lerArquivo: $(HEADERS) $(SRC_DIR)/lerArquivo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/lerArquivo.cpp

imprime: $(HEADERS) $(SRC_DIR)/imprime.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/imprime.cpp

clean:
	rm *.o