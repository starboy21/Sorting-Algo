#include <stdio.h>  
  
int getk(int a[], int n) {  
   int k = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > k)  
         k = a[i];  
   }  
   return k; //get maximum element from the array  
}  
  
void countingSort(int a[], int n, int place)  
{  
  int B[n + 1];  
  int count[10] = {0};    
  
  // Calculate count of elements  
  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;  
      
  // Calculate cumulative frequency  
  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];  
  
  // Place the elements in sorted order  
  for (int i = n - 1; i >= 0; i--) {  
    B[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  
  for (int i = 0; i < n; i++)  
    a[i] = B[i];  
}  
  
// function to implement radix sort  
void radixsort(int a[], int n) {  
   
  // get maximum element from array  
  int k = getk(a, n);  
  
  // Apply counting sort to sort elements based on place value  
  for (int place = 1; k / place > 0; place *= 10)  
    countingSort(a, n, place);  
}  
  
// function to print array elements  
void printArr(int a[], int n) {  
  for (int i = 0; i < n; ++i) {  
    printf("%d  ", a[i]);  
  }  
  printf("\n");  
}  
  
void main() {

    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements in the array\n");
    // taking input and storing it in an array
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
 
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    radixsort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
}
