all:
	g++ -I ../SDLTEMPLATE/src/include -I include/ -L ../SDLTEMPLATE/src/lib -o main src/project/main.cpp src/Circle.cpp -lmingw32 -lSDL2main -lSDL2
