SRC = 
INCLUDE = 
LIBS = 

all: open_test fopen_test

open_test: open_test.c
	$(CC) $< -o $@

fopen_test: fopen_test.c
	$(CC) $< -o $@

clean:
	./clean.sh
	rm fopen_test open_test
