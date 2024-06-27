#ifndef MAZE_H
#define MAZE_H

/* macros */
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define TOTAL_TEXTURE 6
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MAP_CHAR_COUNT 1275

/* header files */
#include <SDL.h>
#include <SDL_image.h>
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

int *parseMap(char *filename, int *map);
void loadImages(char *mapName);

bool initializeSDL(void);
void updateRenderer(bool textured);
void endSDL(void);

void movement(int *maze);
bool end(void);

void raycaster(int *maze, bool textured);
void renderWalls(int *maze, SDL_Point map, point_t rayPos, point_t rayDir, double distToWall, int x, int side, bool textured);
void renderBGFlat(void);
void renderBGTex(SDL_Point map, point_t rayDir, double distToWall, double wallX, int drawEnd, int x, int side);

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;
extern uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
extern uint32_t tiles[TOTAL_TEXTURE][TEX_HEIGHT][TEX_WIDTH];
extern point_t pos;
extern point_t dir;
extern point_t plane;
extern double time;

/**
 * struct point_s - data structure for XY point coordinates of type double
 * @x: X coordinate
 * @y: Y coordinate
 * Description: struct point
 */

typedef struct point_s
{
	double x;
	double y;
} point_t;


#endif /* MAZE_H */

