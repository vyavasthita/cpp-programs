PYTHON_LIB = -L/usr/lib/i386-linux-gnu -lpython2.7
CPP_LIB = -L. -lcppsample
PYTHON_INC = -I/usr/include/python2.7

result: libcppsample.a main.o
	c++ -o result main.o $(CPP_LIB) $(PYTHON_LIB)

main.o: main.cpp
	c++ -c main.cpp

libcppsample.a: cppsample.o
	ar -crs libcppsample.a cppsample.o

cppsample.o: cppsample.h cppsample.cpp
	c++ -c cppsample.h cppsample.cpp $(PYTHON_INC) $(PYTHON_LIB)

.PHONY: clean

clean:
	rm *.o *.pyc *.a *.gch result