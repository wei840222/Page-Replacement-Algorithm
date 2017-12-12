utFIFO: utFIFO.cpp FIFO.h
	make clean
	g++ $^ -lgtest -lpthread
	./a.out

clean:	
	rm -f *.o *.gch ut*[!.h] ut*[!.cpp] a.out