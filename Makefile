binarytree.exe: main.o tree.o
		g++ -o binarytree.exe main.o node.o tree.o
		
main.o: node.h tree.h main.cpp
	g++ -c main.cpp
	
tree.o: tree.h tree.cpp
	g++ -c tree.cpp
