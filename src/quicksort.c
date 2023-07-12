/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:22:08 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/12 12:43:38 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int arr[], int low, int high)
{
	int pivot;
	int low_idx;
	int i;

	pivot = arr[high];
	low_idx = (low - 1);
	i = 0;

	while (i < high - 1)
	{
		if (arr[i] < pivot)
		{
			low_idx++;
			swap(arr[low_idx], arr[i]);
		}
		i++;
	}
	swap(&arr[low_idx + 1], &arr[high]);
	return (low_idx);
}

void	quicksort(int arr[], int low, int high)
{
	int index;

	index = partition(arr, low, high);

	quicksort(arr, 0, index);
	quicksort(arr, index + 1, high);
}