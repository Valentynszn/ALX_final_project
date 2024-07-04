#include "header/maze.h"

/**
 * loadImages - loads images from file and puts element information in buffer
 * Return: void
 */
void loadImages(void)
{
	SDL_Surface * imgSrc[TEX_COUNT]; /* array of loaded textures */
	uint8_t *element; /* color value of element at given coordinate */
	int a, b, c; /* loop counters */

		imgSrc[0] = IMG_Load("images/wall1.png");
		imgSrc[1] = IMG_Load("images/wall2.png");
		imgSrc[2] = IMG_Load("images/window1.png");
		imgSrc[3] = IMG_Load("images/window2.png");
		imgSrc[4] = IMG_Load("images/ceiling.png");
		imgSrc[5] = IMG_Load("images/floorboard.png");

	/* get colors from texture elements and put in array */
	for (a = 0; a < TEX_COUNT; a++)
	{
		for (b = 0; b < TEX_HEIGHT; b++)
		{
			for (c = 0; c < TEX_WIDTH; c++)
			{
				element = (uint8_t *)imgSrc[a]->pixels
					+ c * imgSrc[a]->pitch + b *
					imgSrc[a]->format->BytesPerPixel;

tiles[a][b][c] = element[0] | element[1] << 8
					| element[2] << 16;
			}
		}
	}

	/* free SDL_Surfaces */
	for (a = 0; a < TEX_COUNT; a++)
	{
		SDL_FreeSurface(imgSrc[a]);
		imgSrc[a] = NULL;
	}
}

