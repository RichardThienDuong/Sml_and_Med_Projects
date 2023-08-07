TARGET = my_mastermind 
FILES = my_mastermind functions
SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))
CC = gcc
CFLAGS += -Wall -Wextra -Werror 
#-fsanitize=address

.PHONY: all clean fclean re
all: $(TARGET) 

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	gcc -c  $(CFLAGS) $(SRC)

crun : all
	./$(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

#remove everything and recompile
re: 
	fclean all

# first make file command :)
#hello: another.c
#	echo "hello world"
# "#" inside the recipe line will comment out anything after
# "cc" = gcc basically, 
# the "cc -c" command is for updating for ex: "cc -c main.c -o main.o" to compile main.c into main.o
# "@" pre-fix will suppress the printing of the recipe line and only print what was executed.
# ".PHONY" to specify that the target is an action , not another file by accident. 
#ex: ".PHONY : clean"
# 		"clean :
#			-rm edit $(objects)"
# can use "\" to break recipe into another line
# targets that do not refer to files/prerequisites but are just actions are called phony targets.

# blah examples 
# blah: blah.o
# 	cc blah.o -o blah # Runs third

# blah.o: blah.c
# 	cc -c blah.c -o blah.o # Runs second

# blah.c:
# 	echo "int main() { return 0; }" > blah.c # Runs first

# Makefiles contain: explocit rules, implicit rules, variable definitions, directives, and comments.
# explicit rule says when and how to remake 

#include directives are to tell the makefile to run these other makefiles first before continuing the original
# make file.

# compilation can involve up to fourstages: processing, compilation proper, assembly and linking. Always in that order . 
# GCC is capable of preprocessing and compiling several files either into several assembler input files,
# 	or into one assembler input files: then each assembler input file produces an objust file, and 
# 	linking combines all the objust files (those newly compiled, and those specified as input) into a executable file.
