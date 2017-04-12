CC = 'g++'
FLAGS= -c -std=c++17
LINKFLAGS = `fltk-config --ldflags`
LINKMSG = 'Linking object files...'
COMPILEMSG = 'Compiling $^...'

all: game

game: game_algorithm
	@echo $(LINKMSG) 
	@$(CC) game_algorithm.o $(LINKFLAGS) -o game 

game_algorithm: game_algorithm.cpp
	@echo $(COMPILEMSG)
	@$(CC) $(FLAGS) game_algorithm.cpp 
clean:
	@echo "Cleaning files..."
	-@rm *.o game 2> /dev/null
