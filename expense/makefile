# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -Wall -Wextra -I. $(shell mysql_config --cflags)

# Define linker flags
LDFLAGS = $(shell mysql_config --libs)

# Define the target executable
TARGET = myprogram

# Define the source files
SRCS = main.c database.c menu.c date.c hitung.c

# Define the object files
OBJS = main.o database.o menu.o date.o hitung.o

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile each source file to an object file
main.o: main.c database.h menu.h date.h hitung.h
	$(CC) $(CFLAGS) -c main.c

database.o: database.c database.h
	$(CC) $(CFLAGS) -c database.c

menu.o: menu.c menu.h database.h date.h hitung.h
	$(CC) $(CFLAGS) -c menu.c

date.o: date.c date.h
	$(CC) $(CFLAGS) -c date.c

hitung.o: hitung.c hitung.h database.h date.h
	$(CC) $(CFLAGS) -c hitung.c

# Clean up the build files
clean:
	rm -f $(TARGET) $(OBJS)
