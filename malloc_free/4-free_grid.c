#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid previously created
 * by your alloc_grid function
 * @grid: pointer to the grid
 * @height: number of rows in the grid
 *
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
int i;

if (grid == NULL)
	return;

for (i = 0; i < height; i++)
	free(grid[i]);
free(grid);
}
