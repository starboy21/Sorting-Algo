// Priority Queue
#include <stdlib.h>
#include <stdio.h>
int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}


// Function to insert into priority queue
void insert(int array[], int newNum);
// Function to insert an element into the tree
void insert(int array[], int newNum) 
{
  if (size == 0) 
  {
    array[0] = newNum;
    size += 1;
  } 
  else
  {
    array[size] = newNum;
    size += 1;
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
// Function to delete from priority queue
// Function to delete an element from the tree
void deleteRoot(int array[], int num) {
  int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
	printf("After deleting an element: ");
	printArray(array, size);      
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  //int i;
  for (i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}
// to display the priority queue
// Print the array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int main(void)
{
	int size,*array;
	int choice;
	int newNum, num;
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	
	array = (int*)malloc(size*sizeof(int));
	

	printf("Enter the choice of operation on priority queue.\n'1' for insert\n'2' for delete \n'3' for display\n");
	scanf("%d",&choice);


	
    while (choice < 4)
    {
        switch (choice)
    	{
		case 1:
			printf("Enter newNum to insert\n");
		    scanf("%d",&newNum);
		    insert(array,newNum);
	        printf("%d successfully inserted\n", newNum);
	        break;
	
		case 2:
			printf("Enter num to delete\n");
			scanf("%d",&num);
			deleteRoot(array,num);
			printf("%d successfully deleted\n", newNum);
			break;
	
		case 3:
			printArray(array,size);
			break;
	
		default:
			printf("Enter the correct option\n");
            break;
        }
		printf("Enter the choice of operation on priority queue.\n'1' for insert\n'2' for delete \n'3' for display\n");
		scanf("%d",&choice);	    
    }

}
