CC = gcc
FLAGS = -Wall -g
BIN = bin

$(ALG).out: $(ALG)/test.c $(ALG)/$(ALG).c testlib.c stack.c
	mkdir -p $(BIN)
	$(CC) $^ $(FLAGS) -o $(BIN)/$@

bst_recur: ./bst_recur/test.c ./bst_recur/bst_recur.c ./testlib.c
	mkdir -p $(BIN)
	$(CC) $^ $(FLAGS) -o $(BIN)/$@.out

stack_test: stack_test.c stack.c bst_iter/bst_iter.c
	mkdir -p $(BIN)
	$(CC) $(FLAGS) -o ./bin/$@.out $^

.PHONY: clean
clean:
	rm -rf $(BIN)/
