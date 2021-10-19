#include<stdio.h>
#include<conio.h>



int fact(int n){
	if(n>1){
		return n*fact(n-1);
	}else{
		return 1;
	}
}


int power(int b,int p){
	
	if(p>1){
		return b*power(b,p-1);
	}else{
		return b;
	}
}

int fab(int n){
	if(n>2){
		return fab(n-1)+fab(n-2);
	}else{
		return 1;
	}
}






void QuickSort(int *arr,int L,int R){
	
	if(L<R){

		int pindex=setpivot(arr,L,R);
		QuickSort(arr,L,pindex-1);
		QuickSort(arr,pindex+1,R);
	}
	
}


int setpivot(int arr[],int l,int r){

	int pi=l;

	while (r!=l){
	
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


int bin_search(int *arr,int l,int r,int tosearch){
	
		
	if(l<=r){
		int mid=(l+r)/2;
		
		if(arr[mid]==tosearch){
	
			return mid;
		}else if(tosearch>arr[mid]){
			
			return bin_search(arr,mid+1,r,tosearch);
				
		}else if(tosearch<arr[mid]){
			
			
			return bin_search(arr,l,mid-1,tosearch);
			
		}
	}

	return -1;
}

int main(int argc, char *argv[]) {
		

	 int arr[]={10,15,1,2,9,16,11};
	 printf("out");
	 QuickSort(&arr,0,6);
	 int i;
	 for(i=0;i<7;i++){
	 	printf("%d\n",arr[i]);
	 }
	//	printf("fnkj");
	return 0;
	
}
