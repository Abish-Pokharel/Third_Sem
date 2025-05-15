#include <stdio.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int size = 0;

// Function to insert an element at a given position
void insertElement(int position, int element)
{
    if (size == MAX_SIZE)
    {
        printf("Error: List is full, cannot insert element.\n");
        return;
    }
    if (position < 0 || position > size)
    {
        printf("Error: Invalid position. Valid range is 0 to %d.\n", size);
        return;
    }
    for (int i = size; i > position; i--)
    {
        list[i] = list[i - 1]; // Shift elements to the right
    }
    list[position] = element; // Insert the new element
    size++;
    printf("Inserted %d at position %d.\n", element, position);
}

// Function to insert an element at the beginning
void insertAtBeginning(int element)
{
    insertElement(0, element);
}

// Function to insert an element at the end
void insertAtEnd(int element)
{
    insertElement(size, element);
}

// Function to delete an element from a given position
void deleteElement(int position)
{
    if (size == 0)
    {
        printf("Error: List is empty, cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= size)
    {
        printf("Error: Invalid position. Valid range is 0 to %d.\n", size - 1);
        return;
    }
    for (int i = position; i < size - 1; i++)
    {
        list[i] = list[i + 1]; // Shift elements to the left
    }
    size--;
    printf("Deleted element at position %d.\n", position);
}

// Function to delete an element from the beginning
void deleteAtBeginning()
{
    deleteElement(0);
}

// Function to delete an element from the end
void deleteAtEnd()
{
    deleteElement(size - 1);
}

// Function to search for an element in the list
int searchElement(int element)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == element)
        {
            return i; // Return index of the element
        }
    }
    return -1; // Element not found
}

// Function to display all elements in the list
void displayList()
{
    if (size == 0)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Main function to demonstrate the list operations
int main()
{
    insertAtBeginning(5);  // Insert 5 at the beginning
    insertAtEnd(15);       // Insert 15 at the end
    insertElement(1, 10);  // Insert 10 at position 1
    insertAtEnd(20);       // Insert 20 at the end
    insertAtBeginning(2);  // Insert 2 at the beginning
    
    displayList(); // Display the list
    
    deleteAtBeginning(); // Delete element from beginning
    deleteAtEnd();       // Delete element from end
    deleteElement(1);    // Delete element at position 1
    
    displayList();    // Display the list after deletions
    
    int search = 15; // Search for element 15
    int index = searchElement(search);
    if (index != -1)
    {
        printf("Element %d found at position %d.\n", search, index);
    }
    else
    {
        printf("Element %d not found in the list.\n", search);
    }
    getchar();
    getchar();
    return 0;
}

