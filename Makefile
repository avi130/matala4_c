CC = gcc
AR = ar
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: frequency
frequency: main.o trie.o
	$(CC) $(FLAGS) -o $@ $^
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -fPIC -c $<
main.o: main.c trie.h
	$(CC) $(FLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o frequency
