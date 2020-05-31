#Makefile

#---------------------------#
#------- definições --------#

# Nome do projeto
PROJ_NAME = matrix

# Arquivos .h
H_SOURCE = $(wildcard ./src/*.h)

# Arquivos .c
C_SOURCE = $(wildcard ./src/*.c)

# Object files(arquivos .o)
OBJ = $(subst .c,.o,$(subst src,objects,$(C_SOURCE)))

# Compilador
CC = clang

# Flags
CC_FLAGS = -O3 -g -W -Wall -ansi

# Commando de limpeza
RM = rm -rf

#----------------------------#
#-------- Compilação --------#
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using Clang linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./src/%.c ./src/%.h
	@ echo 'Building target using Clang compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./src/main.c $(H_SOURCE)
	@ echo 'Building target using Clang compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean
