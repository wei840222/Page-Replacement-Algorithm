utFIFO: utFIFO.cpp fifo.h
	make clean
	g++ $^ -std=gnu++0x -lgtest -lpthread
	./a.out

clean:	
	rm -f *.o *.gch a.out