trie: trie.o main.o
	gcc trie.o main.o -o programa
main.o: main.c trie.h
	gcc -g -c main.c
trie.o: trie.h trie.c
	    gcc -g -c trie.c 
clean:
	rm *.o *.gch
	rm programa


