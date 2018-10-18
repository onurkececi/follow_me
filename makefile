# Makefile for gtest examples

CC = g++
CFLAGS  = -g -Wall -lstdc++ -pthread  -lgtest_main  -lgtest -lpthread 

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: follow_me_gtests clean

# To create the executable file count we need the object files
#
follow_me_gtests:  follow.o Clip_Manager.o gtest-all.o
	$(CC) $(CFLAGS) -o follow_me follow.o Clip_Manager.o gtest-all.o

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
Clip_Manager.o: follow/headers/Clip.h follow/headers/Clip_Manager.h follow/headers/Globals.h follow/headers/Ticks.h follow/src/Clip_Manager.cpp
	$(CC) $(CFLAGS) -c follow/src/Clip_Manager.cpp

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
follow.o:  follow/src/Clip_Manager.cpp follow/src/follow.cpp follow/headers/Clip.h follow/headers/Clip_Manager.h follow/headers/Globals.h follow/headers/Ticks.h
	$(CC) $(CFLAGS) -c follow/src/follow.cpp

gtest-all.o: gUnitTests/unitTests/gtest/gtest.h gUnitTests/unitTests/gtest/gtest-all.cpp 
	$(CC) $(CFLAGS) -c gUnitTests/unitTests/gtest/gtest-all.cpp

GOOGLE_TEST_LIB = ../googletest/googletest
GOOGLE_TEST_INCLUDE = ../googletest/googletest/src/

G++ = g++
G++_FLAGS = -c -Wall -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

OBJECTS = Clip_Manager.o follow.o gtest-all.o
TARGET = follow_me_gtests

all: $(TARGET)

$(TARGET): $(OBJECTS) g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

%.o : %.cpp $(G++) $(G++_FLAGS) $<

clean: rm -f $(TARGET) $(OBJECTS)
                    
.PHONY: all clean
