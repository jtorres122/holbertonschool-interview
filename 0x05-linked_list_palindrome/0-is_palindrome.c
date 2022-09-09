#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - function checks if a singly linked list is a palindrome
 * @head: singly linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int length, center, idx;
	int validator = 1;
	listint_t *head_rev;
	listint_t *actual = *head;
	listint_t *counter = *head;
	listint_t *reversed_actual;

	for (length = 0; counter != NULL; length++)
		counter = counter->next;
	center = length / 2;

	head_rev = *head;
	for (idx = 0; idx < center; idx++)
		head_rev = head_rev->next;
	if (length % 2 != 0)
		head_rev = head_rev->next;
	head_rev = reverse_list(&head_rev);
	reversed_actual = head_rev;
	actual = *head;
	while (reversed_actual != NULL)
	{
		if (reversed_actual->n != actual->n)
			validator = 0;
		reversed_actual = reversed_actual->next;
		actual = actual->next;
	}
	return (validator);
}

/**
 * reverse_list - function reverses singly linked list
 * @head: list to be reversed
 * Return: the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
	listint_t *prev = NULL, *actual = *head, *next = NULL;

	while (actual != NULL)
	{
		next = actual->next;
		actual->next = prev;
		prev = actual;
		actual = next;
	}
	*head = prev;
	return (*head);
}
