all:
	g++ main.cpp game.cpp entity.cpp audio.cpp input.cpp object.cpp update.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -o game
	./game
run:
	./game
clean:
