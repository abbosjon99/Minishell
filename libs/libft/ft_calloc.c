/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:38:18 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/07 01:03:06 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && size && (nmemb > (SIZE_MAX / size)))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
struct Point {
	int x;
	int y;
};

int	main(void) {
	int *intArray;
	double *doubleArray;
	char **charMatrix;
	struct Point **pointMatrix;

	// Example 1: Allocating an array of integers
	intArray = (int *)ft_calloc(5, sizeof(int));
	printf("Example 1: Array of integers\n");
	for (int i = 0; i < 5; ++i) {
		printf("%d ", intArray[i]); // The elements should be initialized to 0
	}
	printf("\n");
	free(intArray);

	// Example 2: Allocating an array of doubles
	doubleArray = (double *)ft_calloc(3, sizeof(double));
	printf("\nExample 2: Array of doubles\n");
	for (int i = 0; i < 3; ++i) {
		printf("%lf ", doubleArray[i]); // Elements be initialized to 0.00
	}
	printf("\n");
	free(doubleArray);

	// Example 3: Allocating a 2D array of characters
	charMatrix = (char **)ft_calloc(2, sizeof(char *));
	printf("\nExample 3: 2D Array of characters\n");
	for (int i = 0; i < 2; ++i) {
		charMatrix[i] = (char *)ft_calloc(3, sizeof(char));
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%c ", charMatrix[i][j]); // Elements be initialized to '\0'
		}
		printf("\n");
	}
	// Freeing memory
	for (int i = 0; i < 2; ++i) {
		free(charMatrix[i]);
	}
	free(charMatrix);

	// Example 4: Allocating a 2D array of structures
	pointMatrix = (struct Point **)ft_calloc(2, sizeof(struct Point *));
	printf("\nExample 4: 2D Array of structures\n");
	for (int i = 0; i < 2; ++i) {
		pointMatrix[i] = (struct Point *)ft_calloc(3, sizeof(struct Point));
	}
	// Initializing elements
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			pointMatrix[i][j].x = i + 1;
			pointMatrix[i][j].y = j + 1;
			printf("(%d, %d) ", pointMatrix[i][j].x, pointMatrix[i][j].y);
		}
		printf("\n");
	}
	// Freeing memory
	for (int i = 0; i < 2; ++i) {
		free(pointMatrix[i]);
	}
	free(pointMatrix);

	return (0);
}*/
