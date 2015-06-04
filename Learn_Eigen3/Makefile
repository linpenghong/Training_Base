object = getting_started.exe size_set_run_time.exe size_set_compile_time.exe \
		 resize.exe addition_subtraction.exe multiplication_division.exe \
		 transposition_conjugation.exe large_mat_multi.exe coefficient.exe \
		 array_multi.exe array_operations.exe block.exe block_2.exe \
		 row_vector.exe table.exe norm.exe boolean_reductions.exe visitors.exe\
		 map.exe storage.exe EigenBase.exe generic.exe

all : $(object)

.PHONY : all clean

%.exe : %.cpp
	g++ -I ./Eigen3 $< -o $@
# $< -- target file
# $^ -- all files depended
# $< -- the first file depended

clean :
	rm -f *.exe
