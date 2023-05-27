#https://gitlab.fit.cvut.cz/husekrad/pa2-cvika-2022/blob/master/cv10/semestralka/Makefile

LOGIN = majtaada
CXX = g++
BASIC_FLAGS = -std=c++17 -O2 -g -Wall -pedantic
FLAGS = -lpng -lz -lstdc++fs -pthread -fsanitize=address

ZIP = Makefile Doxyfile DOCUMENTATION.md zadani.txt prohlaseni.txt \
  .gitignore $(wildcard examples/*) $(wildcard src/*)

SOURCES = $(filter-out src/testmain.cpp, $(wildcard src/*.cpp))
TEST_SOURCES = $(filter-out src/main.cpp, $(SOURCES))
OBJECTS = $(patsubst src/%.cpp, build/%.o, ${SOURCES})
TEST_OBJECTS = $(patsubst src/%.cpp, build/%.o, ${TEST_SOURCES})
DEPS = $(patsubst src/%.cpp, build/%.dep, ${SOURCES})

.PHONY: all compile run doc clean count zip

all: compile doc

compile: ${LOGIN}

${LOGIN}: ${OBJECTS}
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS}  $^ -o $@ ${FLAGS}

build/%.o: src/%.cpp
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS}  -c $< -o $@ ${FLAGS}

run: compile
	./${LOGIN}

valgrind: compile
	valgrind ./${LOGIN} --leak-check=full -s

test: $(TEST_OBJECTS) src/testmain.cpp
	@mkdir -p build/
	${CXX} ${BASIC_FLAGS} $^ -o test ${FLAGS}
	./test

doc: doc/index.html

doc/index.html: Doxyfile DOCUMENTATION.md $(wildcard src/*)
	doxygen Doxyfile

count:
	wc -l src/*

clean:
	rm -rf build doc
	rm -f ${LOGIN} ${LOGIN}.zip
	rm -rf *.png*

zip: ${LOGIN}.zip

${LOGIN}.zip: ${ZIP}
	rm -rf tmp/
	rm -f $@
	mkdir -p tmp/${LOGIN}/
	cp --parents -r $^ tmp/${LOGIN}/
	cd tmp/ && zip -r ../$@ ${LOGIN}/
	rm -rf tmp/

build/%.dep: src/%.cpp src/*
	@mkdir -p build/
	${CXX} -MM -MT $(patsubst src/%.cpp, build/%.o, $<) $< > $@

include ${DEPS}

