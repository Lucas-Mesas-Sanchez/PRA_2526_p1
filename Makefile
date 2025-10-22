bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h List.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListLinked: testListArray.cpp ListLinked.h List.h Node.h 
	mkdir -p bin
	g++ -o bin/testListLinked testListArray.cpp ListArray.h List.h
clean:
	rm -r *.o *.gch bin
