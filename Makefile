# Specify compiler
CC = gcc

# Source files
SRC = src/*.c

# Executable name
NAME = playgame

# RM + flags
RM = rm -f

# Compiler flags
CFLAGS = -o2 -g -Wall -Werror -Wextra -pedantic -Isrc/headers

# Linker flags
LFLAGS = -lSDL2 -lSDL2_image -lm

# SDL Flags
SDLFLAGS = `sdl2-config --cflags --libs`

# Link object files to create executable
all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(SDLFLAGS)

# Remove temporary files and executable
clean:
	$(RM) *~ $(NAME)

