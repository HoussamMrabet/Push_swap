/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:33:38 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/08 21:30:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void printList(t_stack *head)
{
    while (head != NULL) {
        ft_printf("Value: %d, LIS: %d\n", head->value, head->lis);
        head = head->next;
    }
}

void	ft_lis(t_stack **a)
{
	t_stack *current = *a;
    t_stack *lisEnd = NULL;  // Points to the end of the longest subsequence
    t_stack *lisStart = NULL; // Points to the start of the longest subsequence

    while (current != NULL) {
        t_stack *temp = current;
        int currentLIS = 1;  // Length of the current LIS

        // Iterate through previous nodes to find the LIS
        while (temp->previous != NULL && temp->value > temp->previous->value) {
            currentLIS++;
            temp = temp->previous;
        }

        // Update the LIS pointers if the current LIS is longer
        if (lisEnd == NULL || currentLIS > lisEnd->lis) {
            lisEnd = current;
            lisStart = temp;
        }

        current = current->next;
    }

    // Print the longest increasing subsequence
    ft_printf("Longest Increasing Subsequence: ");
    while (lisStart != NULL && lisStart != lisEnd->next) {
        ft_printf("%d ", lisStart->value);
        lisStart = lisStart->next;
    }
    ft_printf("\n");
	printList(*a);
}