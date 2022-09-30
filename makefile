FLAGS= -Wall -Wextra -Werror -pedantic
OBJS=conditional.o logical-negation.o tinyfloat.o
BINS=tests

tests: tests.c  $(OBJS)
	gcc -Wall -Wextra -pedantic -o tests tests.c $(OBJS) rounding.o masking.o

conditional.o: 
	gcc $(FLAGS) -c conditional.c 

logical-negation.o: 
	gcc $(FLAGS) -c logical-negation.c 

tinyfloat.o: 
	gcc $(FLAGS) -c tinyfloat.c 

clean:
	rm $(OBJS) $(BINS)
