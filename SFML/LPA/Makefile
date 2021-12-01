# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = LPA

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) -c $(TARGET).cpp && $(CC) $(TARGET).o -o -g sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app

clean:
	$(RM) $(TARGET)
