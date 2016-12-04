OPTS="-std=c++11"

clean:
	rm -f bin/bank

build:clean
	mkdir -p bin
	g++ ${OPTS} -o bin/bank src/accounts.cpp src/balance.cpp main.cpp

run:build
	clear
	bin/bank

balance:build
	clear
	bin/bank balance
