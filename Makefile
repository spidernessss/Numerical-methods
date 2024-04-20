FINAL = Mermaid
COMPILER = gcc
FLAGS = -std=c99 -c 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

$(FINAL) : $(OBJ)
	$(COMPILER) $(OBJ) -o $(FINAL) -lm

%.o : %.c
	$(COMPILER) $(FLAGS) $< -o $@ 
clean :
	rm $(FINAL) *.o
