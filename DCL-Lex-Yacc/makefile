LEX = lex
YACC = yacc
CNFLAG = -rm -f
LIBS = -ll -ly
OUT = -o
CC = gcc
DEPS = y.tab.h
LF = lex.l
YF = yacc.y
OBJ = lex.yy.o y.tab.o

%.o: %.c $(DEPS)
	$(CC) -c $(OUT) $@ $<

prog: $(OBJ)
	$(CC) $(OUT) $@ $^ $(LIBS)

lex.yy.c: $(LF)
	$(LEX) $(LF)

y.tab.c $(DEPS): $(YF)
	$(YACC) $(YF) -dy

clean:
	$(CNFLAG) $(OBJ) lex.yy.c *.tab.*
