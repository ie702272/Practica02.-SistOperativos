all: init getty sh killp

init: init.c
	chmod +x init.c
	gcc -o init init.c

getty: getty.c
	chmod +x getty.c
	gcc -o init getty.c

sh: sh.c
	chmod +x sh.c
	gcc -o init sh.c


killp: killp.c
	chmod +x killp.c
	gcc -o init killp.c
