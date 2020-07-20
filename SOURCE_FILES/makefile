all: 
	clear
	make compile
	make run

compile: 
	gcc -g -o prog main.c movie.c listElem.c listArrayList.c rating.c mapElem.c mapArrayList.c

run: 
	./prog

listArraylist:
	clear
	gcc -o prog -g mainList.c listElem.c listArrayList.c
	make run
	
listLinkedlist:
	clear
	gcc -o prog -g mainList.c listElem.c listLinkedList.c
	make run

listClean:
	rm prog

mapArraylist:
	gcc -o prog -g mapElem.c mapArrayList.c main.c 

mapLinkedlist:
	gcc -o prog -g mapElem.c mapLinkedList.c main.c

mapClean:
	rm -f prog

