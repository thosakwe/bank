clean:
	rm -f bin/bank

build:clean
	mkdir -p bin
	gcc -o bin/bank src/accounts.c src/balance.c main.c

run:build
	clear
	bin/bank

balance:build
	clear
	bin/bank balance
