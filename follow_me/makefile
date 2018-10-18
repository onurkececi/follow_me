
CC = g++
CFLAGS  = -g -Wall -lstdc++ -std=c++11

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: follow_me_run clean

# To create the executable file count we need the object files
#
follow_me_run:  follow.o Clip_Manager.o 
	$(CC) $(CFLAGS) -o follow_me follow.o Clip_Manager.o

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
Clip_Manager.o: headers/Clip.h headers/Clip_Manager.h headers/Globals.h headers/Ticks.h src/Clip_Manager.cpp
	$(CC) $(CFLAGS) -c src/Clip_Manager.cpp

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
follow.o:  src/Clip_Manager.cpp src/follow.cpp headers/Clip.h headers/Clip_Manager.h headers/Globals.h headers/Ticks.h
	$(CC) $(CFLAGS) -c src/follow.cpp



# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) Clip_Manager.o follow.o
