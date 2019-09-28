#Sidney Robinson
#Makefile for list.h and list.c with macros

FLAGS = -std=c99 -Wall
SOURCES = list.c main.c listUtil.c
OBJECTS = list.o  main.o  listUtil.o
HEADERS = list.h listUtil.h
EXEBIN = lists

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

#clean which obtains a function to stop clock skrew errors from occurring within my Unix Timeshare
clean :
	find . -type f | xargs touch
	rm -f $(EXEBIN) $(OBJECTS)
