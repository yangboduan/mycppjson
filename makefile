CPP      = g++
CC       = gcc
CFLAGS   = -std=gnu++0x -g 
OBJ      = main.o funcmyjson.o 
LINKOBJ  = main.o funcmyjson.o
LIBS     = -ljson 
BIN      = jsontest
RM       = rm -rf

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)  


clean: 
	${RM} $(OBJ) $(BIN)

cleanobj:
	${RM} *.o

