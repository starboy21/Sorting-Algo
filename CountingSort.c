//Counting Sort

#include<stdio.h>
#include<stdlib.h>


void CountingSort(int arr[], int n)
{
	int B[n+1];
	int k = arr[0];
	for(int i =1; i<n; i++)
		if(arr[i] > k)
			k=arr[i];
			
	int c[k+1];
	//int c[10]; //static
	//or i=0 to k
	int i;
	for(i=0; i<=k; i++)
	{
		c[i]=0;
	}
		
	//for i=0 to n-1
	for(i=0; i<n; ++i)
	{
		//c[A[j]]+=c[A[j]] + 1;
		c[arr[i]]++;
	}
			
	//for i=1 to k
	for(i=1; i<=k; ++i)
	{
		c[i]=c[i] + c[i-1];
	}
	
	for (i=n-1; i>=0; i--)
	{
		B[c[arr[i]] - 1] = arr[i];
		//c[A[i]] = c[A[i]] - 1;
		c[arr[i]]--;		
	}
	
	for(i=0; i<n; i++)
	{
		arr[i]=B[i];
	}
}

// Print an array
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Driver code
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
    CountingSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
}
