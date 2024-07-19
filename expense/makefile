# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -Wall -Wextra -I. $(shell mysql_config --cflags)

# Define linker flags
LDFLAGS = $(shell mysql_config --libs)

# Define the target executable
TARGET = myprogram

# Define the source files
SRCS = main.c database.c menu.c

# Define the object files
OBJS = main.o database.o menu.o

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile each source file to an object file
main.o: main.c types.h database.h menu.h
	$(CC) $(CFLAGS) -c main.c

database.o: database.c types.h database.h
	$(CC) $(CFLAGS) -c database.c

menu.o: menu.c types.h menu.h
	$(CC) $(CFLAGS) -c menu.c

# Clean up the build files
clean:
	rm -f $(TARGET) $(OBJS)
