.PHONY: clean obj

main: obj
	$(CC) -o main *.o

# Thank you https://stackoverflow.com/questions/1633527/wildcard-targets-in-a-makefile
obj: $(addsuffix .o, $(basename $(wildcard *.c)))

%.o: %.c
	$(CC) -Wall -Werror -std=c11 -g -c $^ -o $@

clean:
	$(RM) main
	$(RM) *.o
