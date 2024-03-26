VMtranslator: main.o parser.o codewriter.o includes.h
	gcc -o VMtranslator main.o parser.o codewriter.o

main.o: main.c parser.h codewriter.h includes.h
	gcc -c main.c

parser.o: parser.c parser.h includes.h
	gcc -c parser.c

code.o: codewriter.c codewriter.h includes.h
	gcc -c codewriter.c

clean:
	rm *.o VMtranslator