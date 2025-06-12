SRC := main.c
OBJ := ${SRC:.c=.o}
OUT := main
CFLAGS := -Wall -Werror
LDLIBS := `pkg-config --libs raylib`

all: ${OUT}

clean:
	@rm -f ${OBJ} ${OUT}

main.o:

${OUT}: ${OBJ}
	${CC} ${LDLIBS} -o $@ $^

.PHONY: all clean
