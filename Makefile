all:
	g++ -I ../SDLTEMPLATE/src/include -L ../SDLTEMPLATE/src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
