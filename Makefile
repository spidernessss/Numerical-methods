FINAL = Mermaid

COMPILER = gcc
ASSEMBLER = nasm

CFLAGS = -std=c99 -c -m32
SFLAGS = -f elf32
OFLAGS = -no-pie -z noexecstack

SRCC = $(wildcard *.c)
SRCS = $(wildcard *.s)

OBJC = $(patsubst %.c, %.o, $(SRCC))
OBJS = $(patsubst %.s, %.o, $(SRCS))

$(FINAL) : $(OBJC) $(OBJS)
	$(COMPILER) $(OBJC) $(OBJS) $(OFLAGS) -o $(FINAL) -m32 -lm

%.o : %.c
	$(COMPILER) $(CFLAGS) $< -o $@
%.o : %.s
	$(ASSEMBLER) $(SFLAGS) $< -o $@
clean :
	rm $(FINAL) *.o
