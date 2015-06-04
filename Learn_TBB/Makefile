CC = icc

CFLAG0 = -O3
CFLAG1 = -ltbb

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %cpp, %exe, $(SRCS))

all : $(OBJS)

$(OBJS) : %.exe : %.cpp
	$(CC) $(CFLAG0) $(CFLAG1) -o $@ $<

clean :
	rm -f *.exe
