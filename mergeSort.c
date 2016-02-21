#include<stdio.h>
#include<stdlib.h>

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) 
{
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while (i<leftCount && j< rightCount) 
	{
		if (L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while (i < leftCount) A[k++] = L[i++];
	while (j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A,int n) 
{
	int mid,i, *L, *R;
	if (n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for (i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for (i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sort the left
	MergeSort(R,n-mid);  // sort the right
	Merge(A,L,mid,R,n-mid);  // merge left and right as a sorted list
        free(L);
        free(R);
}

int main() 
{
	int A[] = {2,5,1,17,15,3,10,12}; // creating an array of integers. 
	int i,numberOfElements;

	// finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
	numberOfElements = sizeof(A)/sizeof(A[0]); 

	// Use merge sort on the array
	MergeSort(A,numberOfElements);

	//print the elements of an array when all else is finished
	for (i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}