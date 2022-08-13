#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - function inserts a number into a sorted singly linked list
 * @head: pointer to the head node
 * @number: number to be inserted in the linked list
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *buffer = *head;
	listint_t *newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);

	if (*head == NULL)
		return (NULL);

	if (buffer == NULL || number <= buffer->n)
	{
		newNode->n = number;
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	while (number >= buffer->n)
	{
		if (buffer == NULL || buffer->next == NULL)
			return (NULL);

		if (buffer->next->n > number)
		{
			newNode->n = number;
			newNode->next = buffer->next;
			buffer->next = newNode;
			return (newNode);
		}

		if (buffer->next->next == NULL && buffer->next->n < number)
			add_nodeint_end(&buffer, number);
		buffer = buffer->next;
	}
	return (NULL);
}
