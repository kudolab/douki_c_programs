PROGRAMS:= \
bin/fft_hardcorder \
bin/fft_test


.PHONY: all clean
all: init ${PROGRAMS}

init: 
	@if [ ! -d "bin" ]; then mkdir bin; fi
	@if [ ! -d "lib" ]; then mkdir lib; fi

install: all
	install -s ${PROGRAMS} ${HOME}/local/bin

clean:
	rm -rf bin lib

lint:
	cppcheck --enable=all .

bin/fft_hardcorder: fft_hardcorder.cpp
	g++ fft_hardcorder.cpp -o bin/fft_hardcorder -O2 -Wall -I/usr/local/include -lm

bin/fft_test: fft_test.cpp Array2D.o fft.o
	g++ fft_test.cpp Array2D.o fft.o -o bin/fft_test -O2 -Wall -I/usr/local/include -I./ -lm

.INTERMEDIATE: Array2D.o fft.o

Array2D.o: Array2D.cpp
	g++ -c Array2D.cpp -o Array2D.o -I/usr/local/include -I./ -lm

fft.o: fft.cpp
	g++ -c fft.cpp -o fft.o -I/usr/local/include -I./ -lm
