CC=g++
CFLAGS=-g -Wall -Werror -ansi -pedantic -std=c++11
DFLAGS=-DMAP

MAIN=exec
SRCS=Mapper.cpp Catalogue.cpp ListeTrajets.cpp Trajet.cpp TrajetSimple.cpp TrajetCompose.cpp
OBJS=$(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(DFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : launch
launch : $(MAIN)
	./$(MAIN)

.PHONY : clean
clean:
	rm -f $(MAIN) *.o core
