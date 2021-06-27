CXX = g++
CXXFLAGS = -Wall -Wno-unknown-pragmas
CXXLINKFLAGS = #-pthread

EXEC_NAME = main

SRC_FILES = main.cpp

LIBS = GL GLU glut

LIB_PATH = /usr/local/lib64 /usr/lib64
INCLUDE_PATH = ./include /usr/local/include/

# The rest is madness

SRC_FILES := $(addprefix src/,$(SRC_FILES))
OBJ_FILES = $(basename $(SRC_FILES))
OBJ_FILES := $(OBJ_FILES:src/%=dist/obj/%.o)

LIBS := $(addprefix -l,$(LIBS))
LIB_PATH := $(addprefix -L,$(LIB_PATH))
INCLUDE_PATH := $(addprefix -I,$(INCLUDE_PATH))

all: prog
	./dist/bin/$(EXEC_NAME)

prog: $(OBJ_FILES)
	$(CXX) $(CXXLINKFLAGS) $^ $(LIB_PATH) $(LIBS) -o dist/bin/$(EXEC_NAME)

dist/obj/%.o: src/%.c
	$(CXX) -c $(CXXFLAGS) -o $@ $< $(INCLUDE_PATH)

dist/obj/%.o: src/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $< $(INCLUDE_PATH)

clean:
	rm -rf dist/bin/$(EXEC_NAME) dist/obj/*.o

init:
	mkdir dist dist/bin dist/obj

test:
	@echo Source Files: $(SRC_FILES) 
	@echo Object Files: $(OBJ_FILES)
	@echo Libs: $(LIBS)
	@echo Lib Path: $(LIB_PATH)
	@echo Include Path: $(INCLUDE_PATH)
	@echo Executable Name: $(EXEC_NAME)
	@echo Compiler: $(CXX) $(CXXFLAGS)
	@echo Linker: $(CXX) $(CXXLINKFLAGS)