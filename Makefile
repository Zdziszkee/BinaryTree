CC = g++
CFLAGS = -Wall -Wextra -O3 -pedantic -std=c++17

all: BinaryTree.x

BinaryTree.x: BinaryTree.cpp
	$(CC) $(CFLAGS) -o BinaryTree.x BinaryTree.cpp
clean:
	rm -f *.x