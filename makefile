FLAGS= -Wall -Wextra -Werror -pedantic
OBJS=conditional.o logical-negation.o
BINS=tests

tests: tests.c  $(OBJS)
	cc $(FLAGS) -o tests tests.c $(OBJS)

conditional.o: 
	cc $(FLAGS) -c conditional.c 

logical-negation.o: 
	cc $(FLAGS) -c logical-negation.c 

clean:
	rm $(OBJS) $(BINS)
