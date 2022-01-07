#include "pathfinding.h"

/**
 * rec_worker - uses dfs backtracking to find path
 * @map: pointer to a read-only two-dimensional array
 * @rows: number of rows
 * @cols: number of columns
 * @start: coordinates of the starting point
 * @target: coordinates of the target point
 * @x: x coordinate
 * @y: y coordinate
 * @arr: array's momentum
 * Return: 1 if found, 0 otherwise
 */

int rec_worker(char **map, int rows, int cols, point_t const *target,
	int x, int y, queue_t *arr)
{
	point_t *closet_monk;

	if (x < 0 || x >= cols || y < 0 || y >= rows || map[y][x] != '0')
	{
		return (0);
	}

	map[y][x] = '1';
	closet_monk = calloc(1, sizeof(*closet_monk));
	if (!closet_monk)
	{
		exit(1);
	}

	closet_monk->x = x;
	closet_monk->y = y;
	queue_push_front(arr, closet_monk);
	printf("Checking coordinates [%d, %d]\n", x, y);
	if (x == target->x && y == target->y)
	{
		return (1);
	}
	if (rec_worker(map, rows, cols, target, x + 1, y, arr) ||
		rec_worker(map, rows, cols, target, x, y + 1, arr) ||
		rec_worker(map, rows, cols, target, x - 1, y, arr) ||
		rec_worker(map, rows, cols, target, x, y - 1, arr))
		return (1);

	free(dequeue(arr));
	return (0);
}

/**
 * backtracking_array - searches for the first path from a starting point
 * to a target point
 * @map: pointer to a read-only two-dimensional array
 * @rows: number of rows
 * @cols: number of columns
 * @start: coordinates of the starting point
 * @target: coordinates of the target point
 * Return: queue
 */

queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target)
{
	queue_t *arr = queue_create();
	queue_t *rra = queue_create();
	char **clone;
	int i;
	point_t *closet_monk;

	if (!arr || !rra)
	{
		return (NULL);
	}
	clone = malloc(rows * sizeof(char *));
	if (!clone)
	{
		exit(1);
	}
	for (i = 0; i < rows; i++)
	{
		clone[i] = malloc(cols + 1);
		if (!clone[i])
			exit(1);
		strcpy(clone[i], map[i]);
	}
	if (rec_worker(clone, rows, cols, target, start->x, start->y, arr))
	{
		while ((closet_monk = dequeue(arr)))
			queue_push_front(rra, closet_monk);
		free(arr);
	}
	else
	{
		free(arr);
		free(rra);
		rra = NULL;
	}
	for (i = 0; i < rows; i++)
	{
		free(clone[i]);
	}
	free(clone);
	return (rra);
}
