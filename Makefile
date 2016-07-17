CC = gcc
CFLAGS = -Wall
LDFLAGS = -lSDL
LDFLAGS_TST = -lcmocka -lSDL
EXEC = seamcarving
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
SRC_TST = $(wildcard test/*.c)
OBJ_TST = $(SRC_TST:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

test: $(OBJ_TST)
	$(CC) -o unit_tests $^ $(LDFLAGS_TST)
	./unit_tests

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm $(OBJ)
	rm $(OBJ_TST)
