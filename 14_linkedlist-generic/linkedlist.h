#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define an enumeration for different node types (e.g., Student or Professor).
typedef enum
{
   TYPE_STUDENT,  // Indicates a node containing student data
   TYPE_PROFESSOR // Indicates a node containing professor data
} NodeType;

// Define the LinkedList and ListNode data structures
typedef struct list LinkedList;    // Represents a linked list
typedef struct list_node ListNode; // Represents a node in the linked list

// Operations on the linked list

/**
 * Create an empty linked list and return a pointer to it.
 *
 * @return - A pointer to the newly created linked list.
 */
LinkedList *ll_create();

/**
 * Insert an element at the beginning of the linked list.
 *
 * @param l    - A pointer to the linked list.
 * @param data - A pointer to the data to be inserted.
 * @param type - The type of the data node (Student or Professor).
 */
void ll_insert(LinkedList *l, void *data, NodeType type);

/**
 * Append an element to the end of the linked list.
 *
 * @param l    - A pointer to the linked list.
 * @param data - A pointer to the data to be appended.
 * @param type - The type of the data node (Student or Professor).
 */
void ll_append(LinkedList *l, void *data, int type);

/**
 * Remove the first occurrence of a specific element from the linked list.
 *
 * @param l   - A pointer to the linked list.
 * @param cpf - The CPF of the element to be removed.
 */
void ll_remove(LinkedList *l, const char *cpf);

/**
 * Remove all elements that match a specific value from the linked list.
 *
 * @param l   - A pointer to the linked list.
 * @param cpf - The CPF to match and remove.
 */
void ll_remove_all(LinkedList *l, const char *cpf);

/**
 * Remove all elements from the linked list.
 *
 * @param l - A pointer to the linked list to be cleared.
 */
void ll_clear(LinkedList *l);

/**
 * Get the size (number of elements) of the linked list.
 *
 * @param l - A pointer to the linked list.
 * @return  - The number of elements in the linked list.
 */
int ll_size(LinkedList *l);

/**
 * Check whether a specific element is in the linked list.
 *
 * @param l   - A pointer to the linked list.
 * @param cpf - The CPF to check for.
 * @return    - 1 if the element is in the linked list, 0 otherwise.
 */
int ll_is_in(LinkedList *l, const char *cpf);

/**
 * Check whether the linked list is empty.
 *
 * @param l - A pointer to the linked list.
 * @return  - 1 if the linked list is empty, 0 otherwise.
 */
int ll_is_empty(LinkedList *l);

/**
 * Get the data at a specific position in the linked list.
 *
 * @param l   - A pointer to the linked list.
 * @param pos - The position of the element to retrieve.
 * @return    - A pointer to the data at the specified position.
 */
void *ll_get(LinkedList *l, int pos);

/**
 * Return a new linked list with the elements reversed.
 *
 * @param l - A pointer to the linked list to be reversed.
 * @return  - A new linked list with the elements in reverse order.
 */
LinkedList *ll_reversed(LinkedList *l);

/**
 * Concatenate two linked lists, placing l2 after l1.
 *
 * @param l1 - A pointer to the first linked list.
 * @param l2 - A pointer to the second linked list to be concatenated.
 * @return   - A new linked list containing elements from both l1 and l2.
 */
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

/**
 * Free the memory used by the linked list.
 *
 * @param l - A pointer to the linked list to be freed.
 */
void ll_free(LinkedList *l);

/**
 * Display all elements of the linked list.
 *
 * @param l - A pointer to the linked list to be printed.
 */
void ll_print(LinkedList *l);

/**
 * Display all elements of the linked list in reverse order.
 *
 * @param l - A pointer to the linked list to be printed in reverse order.
 */
void ll_print_reversed(LinkedList *l);

#endif
