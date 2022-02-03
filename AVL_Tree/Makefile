CC = gcc
CFLAGS = -g -Wall
TARGET = test
OBJECT = main.o BinaryTree.o AVLTree.o

all : $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm  *.o $(TARGET)
