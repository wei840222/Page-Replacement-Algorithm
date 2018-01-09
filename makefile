main: main.cpp repALG.h fifo.h lru.h
	g++ $^ -o main -std=gnu++0x -lgtest -lpthread

utAll: utFIFO utLRU utRandom utOptimal utSecondChance
	./utFIFO && ./utLRU && ./utSecondChance && ./utOptimal
	make clean

utFIFO: utFIFO.cpp fifo.h
	g++ $^ -o $@ -std=gnu++0x -lgtest -lpthread

utLRU: utLRU.cpp lru.h
	g++ $^ -o $@ -std=gnu++0x -lgtest -lpthread

utRandom: utRandom.cpp random.h
	g++ $^ -o $@ -std=gnu++0x -lgtest -lpthread

utOptimal: utOptimal.cpp optimal.h
	g++ $^ -o $@ -std=gnu++0x -lgtest -lpthread

utSecondChance: utSecondChance.cpp secondChance.h
	g++ $^ -o $@ -std=gnu++0x -lgtest -lpthread

clean:	
	rm -f main *.o *.gch ut*[!.cpp]