CC = g++
CFLAGS = -std=c++11 -Wall -g

TARGET = myprogram
SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)
DEPS = 

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
