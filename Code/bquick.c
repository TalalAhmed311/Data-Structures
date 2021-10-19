
#include <stdio.h>
#include <conio.h>

void quickSort(int *arr,int L, int R)
{
    printf("done");
    if (L<R)
    {
        int pi=setPivot(arr,L,R);
        quickSort(arr,L,pi-1);
        quickSort(arr,pi+1,R);
    }
}

int setPivot(int arr[],int l, int r)
{
    int p_i=(l+r)/2;
    while(r!=l)
    {
        while (p_i!=r)
        {
            if (arr[p_i]<=arr[r])
            {
                r--;
            }
            else
            {
                swap(&arr[p_i],&arr[r]);
                p_i=r;
            }
        }
        while(p_i!=l)
        {
            if (arr[p_i]>arr[l])
            {
                l++;
            }
            else
            {
                swap(&arr[p_i],&arr[l]);
                p_i=l;
            }
        }
    }
    return p_i;
}
void swap(int* x,int* y)
{
    int t=*x;
    *x=*y;
    *y=t;
}

int main(int argc, char *argv[])
{
    int arr[]={20,5,46,81,13,42,2};
   // printf("fnksd");
    quickSort(&arr,0,6);
    int i;
    for(i=0;i<7;i++){
    	printf("%d\n",arr[i]);
	}
	return 0;
}
