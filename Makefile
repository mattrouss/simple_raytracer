CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -pedantic
SRC = src/main.cc
OBJ = ${SRC:.cc=.o}
BIN = raytracer

all: tp1

tp1:
	${CXX} ${CXXFLAGS} ${SRC} -o ${BIN}

clean:
	rm -f ${OBJ}

.PHONY: clean
