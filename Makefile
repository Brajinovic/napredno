SRCS =  *.c
CFLAGS = -Isrc/include
vpath %.c $(src/)
vpath %.o %(src/)

compile:
	gcc src/$(SRCS) $(CFLAGS) -o bin/main.out
	./bin/main.out

run:
	./bin/main.out
