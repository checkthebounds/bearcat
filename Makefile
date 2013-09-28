all: bearcat
bearcat: bearcat.c
	gcc -Wall bearcat.c -o bearcat
clean:
	rm -f bearcat
