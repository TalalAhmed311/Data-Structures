#include<stdio.h>
#include<conio.h>




void QuickSort(int *arr,int L,int R){
	
	if(L<R){

		int pindex=setpivot(arr,L,R);
		QuickSort(arr,L,pindex-1);
		QuickSort(arr,pindex+1,R);
	}
	
}

int setpivot(int arr[],int l,int r){

	int pi=(l+r)/2;

	while (r!= l){
	
		while (pi!=r)
		{
			if(arr[pi]<=arr[r]){
				r--;
			}else
			{
				swap(&arr[pi],&arr[r]);
				pi=r;
			}
			
		}


		while (pi!=l)
		{
			if(arr[pi]>arr[l]){
				l++;
			}else
			{
				swap(&arr[pi],&arr[l]);
				pi=l;
			}
			
		}
		
		
	}


	return pi;
	

}

void swap(int *x,int *y){
	int t=*x;
	*x=*y;
	*y=t;
}


int main(int argc, char *argv[]) {
		

	 int arr[]={10,45,98,74,12,36,65,41,21,87,324};
 	
	 QuickSort(&arr,0,10);
	 int i;
	 for(i=0;i<11;i++){
	 	printf("%d\n",arr[i]);
	 }
	return 0;
	
}
