all: chessviz
chessviz: chessviz.c
	gcc -Wall -Werror -o chessviz chessviz.c
