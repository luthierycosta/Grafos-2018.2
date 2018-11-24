### Makefile ###
# grupo: 
# Lucas Vinícius M. Pinheiro
# Luthiery C. Cavalcante

# variaveis
FLAGS  		= -std=c++11 -Wall -g
HEADERS 	= $(wildcard headers/*.h)
SRC			= $(filter-out src/main.cpp, $(wildcard src/*.cpp))
OBJ			= $(SRC:.cpp=.o)

# all
all: Grafos4

# executavel
Grafos4: $(HEADERS) $(OBJ)
	g++ $(FLAGS) -o Grafos4.exe src/main.cpp $(OBJ)

# .o's
%.o: %.cpp $(HEADERS)
	g++ $(FLAGS) -c $< -o $@
	
clean:
	rm src/*.o