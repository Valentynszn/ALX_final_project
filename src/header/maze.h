#ifndef MAZE_H
#define MAZE_H

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define TEX_COUNT 6
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MAP_CHAR_COUNT 1275

/* header files */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "structs.h" /* struct definitions */
#include "global.h" /* global variables */

int *parseMap(char *filename, int *map);
void loadImages(void);

bool initializeSDL(void);
void updateRenderer(bool textured);
void endSDL(void);

void movement(int *maze);
bool end(void);

void raycaster(int *maze, bool textured);
void renderWalls(int *maze, SDL_Point map, point_t rayPos, point_t rayDir, double distToWall, int x, int side);
void renderBGTex(SDL_Point map, point_t rayDir, double distToWall, double wallX, int drawEnd, int x, int side);

#endif /* MAZE_H */
