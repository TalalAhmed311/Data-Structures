#include<stdio.h>
#include<conio.h>


void merge(int arr[],int l,int mid,int r){
	
	int i,j,k;
	int l1=mid-l+1;
	int l2=r-mid;
	int temp1[l1],temp2[l2];

	for(i=0;i<l1;i++){
		temp1[i]=arr[l+i];
	}
	
	for(j=0;j<l2;j++){
		temp2[j]=arr[mid+1+j];
	}


	i=0,j=0,k=l;
	
	while(i<l1 && j<l2){
		if(temp1[i]<=temp2[j]){
			arr[k]=temp1[i];
			i++;
		}else{
			arr[k]=temp2[j];
			j++;
		}
		
		k++;	
	}	

	while(i<l1){
		arr[k]=temp1[i];
		i++;
		k++;
	}
	
	while(j<l2){
		arr[k]=temp2[j];
		j++;
		k++;
	}
	

//	printf("Merge %d-%d-%d\n",l,mid,r);
//	while(i<=mid && j<=r){
//		if(arr[i]<=arr[j]){
//			temp[k]=arr[i];
//			i++;
//		}else{
//			temp[k]=arr[j];
//			j++;
//		}
//		k++;
//	}
//	
//	if(i>mid){
//		while(j<=r){
//			temp[k]=arr[j];
//			k++;
//			j++;
//		}
//	}
//	
//	if(j>r){
//		
//		while(i<=mid){
//			temp[k]=arr[i];
//			k++;
//			i++;
//		}
//	}
//	
//	
//	int x;
//	for(x=0;x<k;x++){
//		arr[l++]=temp[x];
//	}


	

}



void mergeSort(int arr[],int l,int r ){
	
	if(l<r){
	printf("\nL-R:%d-%d\n",l,r);
	int mid=(l+r)/2;
	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,r);
	merge(arr,l,mid,r);
		
	}
}

int main(int argc, char *argv[]) {
			
	int arr[]={78,80,90,20,15,72,117,92,30};
	int i;
	for(i=0;i<9;i++){
		printf("%d\n",arr[i]);
	}
	mergeSort(arr,0,8);
	printf("after sort\n");
	for(i=0;i<9;i++)
	printf("%d\n",arr[i]);
	return 0;
}
