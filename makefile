CC=g++
CFLAGS=-g -Wall -Werror -ansi -pedantic -std=c++11 -DMAP

MAIN=exec
SRCS=Mapper.cpp
OBJS=$(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : launch
launch : $(MAIN)
	./$(MAIN)

.PHONY : clean
clean:
	rm -f $(MAIN) *.o core
