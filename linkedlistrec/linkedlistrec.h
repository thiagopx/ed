#ifndef LINKEDLISTREC_H
#define LINKEDLISTREC_H

// Define the LinkedListRec and ListNode data structures
typedef struct list LinkedListRec; // Represents a linked list
typedef struct list_node ListNode; // Represents a node in the linked list

// Operations on the linked list

// Create an empty linked list and return a pointer to it
LinkedListRec *ll_create();

// Insert an element at the beginning of the linked list
void ll_insert(LinkedListRec *l, int v);

// // Internal recursive function used by insert_sorted_into_the_list
// static void _insert_sorted(LinkedListRec *l, int v);

// // Insert an element into the linked list while keeping it sorted
// void ll_insert_sorted(LinkedListRec *l, int v);

// // Append an element to the end of the linked list
// void ll_append(LinkedListRec *l, int v);

void ll_remove(LinkedListRec *l, int val);

void ll_remove_all(LinkedListRec *l, int val);

// Get the size (number of elements) of the linked list
int ll_size(LinkedListRec *l);

// // Check whether a specific element is in the linked list
// int ll_is_in(LinkedListRec *l, int v);

// Check whether the linked list is empty
int ll_is_empty(LinkedListRec *l);

int ll_sum(LinkedListRec *l);
// // Return a new linked list with the elements reversed
// LinkedListRec *ll_reversed(LinkedListRec *l);

// // Concatenate two linked lists, placing l2 after l1
// LinkedListRec *ll_concatenate(LinkedListRec *l1, LinkedListRec *l2);

// Free the memory used by the linked list
void ll_free(LinkedListRec *l);

// Display all elements of the linked list
void ll_print(LinkedListRec *l);

#endif
