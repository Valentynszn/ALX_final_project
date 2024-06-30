# Specify compiler
CC = gcc

# Source files
SRC = $(wildcard src/*.c)

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
NAME = playgame

# RM + flags
RM = rm -f

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -Isrc/headers

# Linker flags
LFLAGS = -lSDL2 -lSDL2_image -lm

# SDL Flags
SDLFLAGS = `sdl2-config --cflags --libs`

# Default target
all: $(NAME)

# Link object files to create executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME) $(SDLFLAGS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove temporary files and executable
clean:
	$(RM) $(OBJ) $(NAME)

