CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lSDL
LDFLAGS_TST = -lcmocka -lSDL
EXEC = seamcarving
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
SRC_TST = $(wildcard test/*.c)
OBJ_TST = $(OBJ)
OBJ_TST += $(SRC_TST:.c=.o)
OBJ_TST := $(filter-out src/main.o, $(OBJ_TST))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

test: $(OBJ_TST)
	$(CC) -o unit_tests $^ $(LDFLAGS_TST)
	./unit_tests

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm src/*.o
