CC = 'g++'
FLAGS= -c -std=c++17
LINKFLAGS = `fltk-config --ldflags --use-images`
LINKMSG = 'Linking object files...'
COMPILEMSG = 'Compiling $^...'

all: game

splash: splash_screen.cpp
	@echo $(COMPILEMSG) 
	@$(CC) splash_screen.cpp $(LINKFLAGS) -o game 

game: game_algorithm splash main
	@echo $(LINKMSG) 
	@$(CC) game_algorithm.o splash_screen.o main.o $(LINKFLAGS) -o game 

game_algorithm: game_algorithm.cpp
	@echo $(COMPILEMSG)
	@$(CC) $(FLAGS) game_algorithm.cpp 
splash: splash_screen.cpp
	@echo $(COMPILEMSG)
	@$(CC) $(FLAGS) splash_screen.cpp 
main: main.cpp
	@echo $(COMPILEMSG)
	@$(CC) $(FLAGS) main.cpp 
clean:
	@echo "Cleaning files..."
	-@rm *.o game 2> /dev/null
