utFIFO: utFIFO.cpp fifo.h
	make clean
	g++ $^ -lgtest -lpthread
	./a.out

clean:	
	rm -f *.o *.gch a.out