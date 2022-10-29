CC=gcc

run: build
	./a.out 800 600

build: main.c
	$(CC) -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl main.c glad.c

clean:
	rm -rf ./a.out
