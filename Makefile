### Makefile ###
# por: Luthiery C. Cavalcante
# original por: Rafael G. de Paulo


# variaveis
FLAGS  		= -std=c++11 -Wall -g
HEADERS_DIR = headers
SRC_DIR		= src
HEADERS 	= $(wildcard $(HEADERS_DIR)/*.h)
OBJ_1		= $(SRC_1: .cpp=.o)

# all
all: Grafos1 clean

# executavel
Grafos1: $(HEADERS) main1.o grafo.o vertice.o lerArquivo.o imprime.o
	g++ $(FLAGS) -o Grafos1.exe main1.o grafo.o vertice.o lerArquivo.o imprime.o

# .o's
main1.o: $(HEADERS) $(SRC_DIR)/main1.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/main1.cpp

grafo.o: $(HEADERS) $(SRC_DIR)/grafo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/grafo.cpp

vertice.o: $(HEADERS) $(SRC_DIR)/vertice.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/vertice.cpp

lerArquivo.o: $(HEADERS) $(SRC_DIR)/lerArquivo.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/lerArquivo.cpp

imprime.o: $(HEADERS) $(SRC_DIR)/imprime.cpp
	g++ $(FLAGS) -c $(SRC_DIR)/imprime.cpp

clean:
	rm *.o