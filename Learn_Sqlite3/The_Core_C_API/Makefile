CC = gcc

CFLAG0 = -O3
CFLAG1 = -lsqlite3

SRCS = $(wildcard *.c)
OBJS = $(patsubst %c, %exe, $(SRCS))

all : $(OBJS)

$(OBJS) : %.exe : %.c
	$(CC) $(CFLAG0) $(CFLAG1) -o $@ $<

clean :
	rm -f *.exe *.db
