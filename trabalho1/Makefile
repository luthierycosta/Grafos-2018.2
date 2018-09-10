### Makefile ###
# Créditos:
# Rafael G. de Paulo
# Luthiery C. Cavalcante

# variaveis
FLAGS  		= -std=c++11 -Wall -g -c
FLAGS_MAIN	= -std=c++11 -Wall -g -o
HEADERS 	= $(wildcard *.h)
SRC			= $(wildcard *.cpp)
OBJ			= $(SRC .cpp=.o)

# all
all: Grafos1

# executavel
Grafos1: $(HEADERS) $(SRC) $(OBJ)
	g++ $(FLAGS_MAIN) Grafos1.exe $(SRC) $(OBJ)

# .o's
grafo.o: grafo.h grafo.cpp
	g++ $(FLAGS) grafo.cpp

coefAglomeracao.o: grafo.h coefAglomeracao.h coefAglomeracao.cpp
	g++ $(FLAGS) coefAglomeracao.cpp

lerArquivo.o: grafo.h lerArquivo.h lerArquivo.cpp
	g++ $(FLAGS) lerArquivo.cpp
