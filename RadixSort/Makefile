CC = gcc
CFLAGS = -g -Wall
TARGET = test
OBJECT = main.o radixSort.o linkedList.o

all : $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm  *.o $(TARGET)
