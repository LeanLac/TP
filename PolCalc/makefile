CNFLAG = -rm -f
OUT = -o
CC = gcc
DEPS = Scanner.h StackOfCharsModule.h
OBJ = Calculator.o Scanner.o StackOfDoublesModule.o

%.o: %.c $(DEPS)
	$(CC) -c $(OUT) $@ $<

prog: $(OBJ)
	$(CC) $(OUT) $@ $^

clean:
	$(CNFLAG) $(OBJ) prog
