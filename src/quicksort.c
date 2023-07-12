/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:22:08 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/12 13:25:45 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int arr[], int low, int high)
{
	int pivot;
	int low_idx;
	int i;

	pivot = arr[high];
	low_idx = (low - 1);
	i = low;

	while (i <= high - 1)
	{
		if (arr[i] < pivot)
		{
			low_idx++;
			swap(&arr[low_idx], &arr[i]);
		}
		i++;
	}
	swap(&arr[low_idx + 1], &arr[high]);
	return (low_idx + 1);
}

void	quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot;

		pivot = partition(arr, low, high);

		quicksort(arr, 0, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}