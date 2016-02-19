#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
    srand(time(NULL));
    int num;
    //int i;
    int nums[10];
    for(i = 0; i < 10; i++)
    {
        nums[i] = rand()%2;
        //printf("%d\n", num);
    }
    
    for(i = 0; i < 10; i++)
    {
        printf("woot: %d\n", nums[i]);
    }
    
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
        /* Merge sort with fork function */
    void merge(int arr[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
     
        /* Create temp arrays */
        int L[n1], R[n2];
     
        /* Start the Fork Program */
        printf("About to Fork...\n");
        
        pid_t pid = fork();
        
         /* Copy the data to temp arrays L[] and R[] */
        i = 0;
        if(pid == 0)
        {
            for(; i < 100; i++)
            {
                L[i] = arr[l + i];
                printf("parent: %d\n", i);
            }
        }
        else
        {
            for(; i < 100; i++)
            {
                printf("child (%d): %d\n", pid, i);
                R[j] = arr[m + 1+ j];
            }
        }
         
        /* Merge the temp arrays back into arr[l..r]*/
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
     
        /* Copy the remaining elements of L[] */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
     
        /* Copy the remaining elements of R[] */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
     
    /* l is for left index and r is right index of the sub-array
      of arr to be sorted */
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
        
    
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 
}