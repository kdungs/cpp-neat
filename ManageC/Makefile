CFLAGS=-O3 -Werror -Wall -pedantic -std=c11
CXXFLAGS=-O3 -Werror -Wall -pedantic -std=c++1y

returnParameter: returnParameter.cc

manage: object.o manage.cc

object.o: object.c object.h

clean:
	rm -f *.o manage
