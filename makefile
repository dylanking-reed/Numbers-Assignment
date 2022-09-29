FLAGS= -Wall -Wextra -Werror -pedantic
OBJS=conditional.o
BINS=tests

tests: tests.c  $(OBJS)
	cc $(FLAGS) -o tests tests.c $(OBJS)

conditional.o: 
	cc $(FLAGS) -c conditional.c 

clean:
	rm $(OBJS) $(BINS)
