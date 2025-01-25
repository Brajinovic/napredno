SRCS =  *.c
CFLAGS = -Isrc/include


compile:
	gcc src/$(SRCS) $(CFLAGS) -o bin/main.out
	./bin/main.out

compile_dynamic: dynamic_lib
	gcc src_dynamic/$(SRCS) $(CFLAGS) -L. -lstack -o bin_dynamic/main.out
	# export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
	./bin_dynamic/main.out

run:
	./bin/main.out

dynamic_lib:
	gcc -c -fPIC src/stack.c -o bin/stack.o -Isrc/include
	gcc -shared -o libstack.so bin/stack.o

pdf:
	pdflatex -shell-escape main.tex