all: exercicio1a exercicio1b exercicio1c exercicio1d exercicio2a exercicio2b exercicio2c

exercicio1a: 
	gcc exercicio1a.c -lm -o exercicio1a

exercicio1b: 
	gcc exercicio1b.c -lm -o exercicio1b

exercicio1c: 
	gcc exercicio1c.c -lm -o exercicio1c

exercicio1d: 
	gcc exercicio1d.c -lm -o exercicio1d

exercicio2a: 
	gcc exercicio2a.c -lm -o exercicio2a

exercicio2b: 
	gcc exercicio2b.c -lm -o exercicio2b

exercicio2c: lista.o exercicio2c.o
	gcc exercicio2c.o lista.o -o exercicio2c -lm

lista.o:
	gcc -c lista.c -o lista.o

exercicio2c.o:
	gcc -c exercicio2c.c -o exercicio2c.o

clean:
	rm *.o exercicio1a exercicio1b exercicio1c exercicio1d exercicio2a exercicio2b exercicio2c

run:
	./exercicio1a && ./exercicio1b && ./exercicio1c && ./exercicio1d && ./exercicio2a && ./exercicio2b && ./exercicio2c 