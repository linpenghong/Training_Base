VectorSum :: VectorSum.o
	mpicxx -o $@ $^ -lmpi -larmadillo

VectorSum.o :: VectorSum.cpp
	mpicxx -o $@ -c $^

clean :
	rm -f *.o
	rm -f VectorSum
