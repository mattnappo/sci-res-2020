CC = gcc
FLAGS = -Wall # -g
BIN = bin

$(ALG).out: $(ALG)/test.c $(ALG)/$(ALG).c
	mkdir -p $(BIN)
	$(CC) $^ $(FLAGS) -o $(BIN)/$@

.PHONY: clean
clean:
	rm -rf $(BIN)/
