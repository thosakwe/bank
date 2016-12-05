OPTS="-std=c++11"
WIN_OPTS="-std=gnu++11"

clean:
	rm -f bin/bank

build:clean
	mkdir -p bin
	g++ ${OPTS} -o bin/bank src/accounts.cpp src/balance.cpp main.cpp

build_win:clean
	g++ ${WIN_OPTS} -o bin/bank.exe src/accounts.cpp src/balance.cpp main.cpp

run:build
	clear
	bin/bank

balance:build
	clear
	bin/bank balance
