main: main.cpp repALG.h fifo.h lru.h
	make clean
	g++ $^ -std=gnu++0x -lgtest -lpthread
	./a.out
	make clean

utFIFO: utFIFO.cpp fifo.h
	make clean
	g++ $^ -std=gnu++0x -lgtest -lpthread
	./a.out
	make clean

utLRU: utLRU.cpp lru.h
	make clean
	g++ $^ -std=gnu++0x -lgtest -lpthread
	./a.out
	make clean

clean:	
	rm -f *.o *.gch a.out