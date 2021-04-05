.PHONY: all
all:  task1 task2 task3

task1: hello_ariel.c hello_ariel.h main1_1.c
	gcc -o main1_1 hello_ariel.c main1_1.c

task2: hello_ariel.h main1_2.c lib
	gcc main1_2.c -L. -l Hello -o main1_2

task3:	hello_ariel.h main1_3.c lib
	gcc main1_3.c -fPIC -ldl -o main1_3

lib: hello_ariel.c hello_ariel.h
	gcc -shared hello_ariel.c -fPIC -o libHello.so

.PHONY: clean
clean:
	-rm -f *.o *.so  main1_1 main1_2 main1_3
