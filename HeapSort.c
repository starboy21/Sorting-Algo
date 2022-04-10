// Heap Sort

#include <stdio.h>
#include <stdlib.h>

// Main function to do heap sort
void heapSort(int arr[], int n);
//Build max heap function
void BuildMaxHeap(int arr[], int n);
// Find largest among root, left child and right child
void maxheapify(int arr[], int n, int i);
// Function to swap the the position of two elements
void swap(int *a, int *b);

void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

void maxheapify(int arr[], int n, int i) {
// Find largest among root, left child and right child
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < n && arr[left] > arr[largest])
  largest = left;

if (right < n && arr[right] > arr[largest])
  largest = right;

// Swap and continue heapifying if root is not largest
if (largest != i) {
  swap(&arr[i], &arr[largest]);
  maxheapify(arr, n, largest);
}
}

//Build max heap function
void BuildMaxHeap(int arr[], int n) {

for (int i = n / 2 - 1; i >= 0; i--)
  maxheapify(arr, n, i);
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
// Build max heap
BuildMaxHeap(arr, n);

// Heap sort
for (int i = n - 1; i >= 0; i--) {
  swap(&arr[0], &arr[i]);

  // Heapify root element to get highest element at root again
  maxheapify(arr, i, 0);
}
}

// Print an array
void printArray(int arr[], int n) {
for (int i = 0; i < n; ++i)
  printf("%d ", arr[i]);
printf("\n");
}

// Driver code
int main() {
int size,*array;
int choice;
printf("Enter the size of the array\n");
scanf("%d",&size);

array = (int*)malloc(size*sizeof(int));
printf("Enter the elements in the array\n");
for(int i =0;i<size;i++)
{
	scanf("%d",&array[i]);
}

heapSort(array, size);

printf("Sorted array is \n");
printArray(array, size);
}


//i/o: 1
//12
//9
//5
//6
//10
//
//o/p: 1 5 6 9 10 12 
