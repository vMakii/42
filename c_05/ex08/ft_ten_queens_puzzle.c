/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:37:21 by mivogel           #+#    #+#             */
/*   Updated: 2024/08/01 20:37:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_grid(int *grid)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		grid[i] = 0;
		i++;
	}
}

void	print(int grid[10])
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = grid[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	issafe(int grid[10], int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (grid[i] == row || grid[i] - i == row - col)
			return (0);
		else if (grid[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int grid[10], int col, int *sol)
{
	int	i;

	if (col == 10)
	{
		print(grid);
		(*sol)++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (issafe(grid, i, col))
		{
			grid[col] = i;
			solve(grid, col + 1, sol);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[10];
	int	sol;

	sol = 0;
	init_grid(grid);
	solve(grid, 0, &sol);
	return (sol);
}
/*
#include <stdio.h>

int main() {
	int num_solutions = ft_ten_queens_puzzle();
	printf("Number of solutions to the Ten Queens Puzzle: %d\n", num_solutions);
	return 0;
}*/
