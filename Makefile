CC = g++
CFLAGS = -I /usr/include/eigen3 -std=c++11 -Wall -g

TARGET = myprogram.exe
SRCS = main.cpp Layer.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = Layer.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
