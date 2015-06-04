CC = icc

CFLAG0 = -O3
CFLAG1 = -ltbb
LIB = -I /opt/intel/tbb/include

Example_1.exe: Example_1.cpp
	$(CC) $(CFLAG0) $(CFLAG1) -o $@ $<

clean :
	rm -f *.exe
