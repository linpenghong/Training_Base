MatrixProduct :: MatrixProduct.o
	mpicxx -o $@ $^ -lmpi -larmadillo

MatrixProduct.o :: MatrixProduct.cpp
	mpicxx -o $@ -c $^

clean :
	rm -f *.o
	rm -f MatrixProduct
