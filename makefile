FLAGS= -Wall -Wextra -Werror -pedantic
OBJS=
BINS=tests

tests: tests.c  $(OBJS)
	cc $(FLAGS) -o tests tests.c $(OBJS)

clean:
	rm $(OBJS) $(BINS)
