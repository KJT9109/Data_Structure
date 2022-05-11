CC = gcc
CFLAGS = -g -Wall
TARGET = test
OBJECT = main.o HashTable.o Person.o

all : $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm  *.o $(TARGET)
