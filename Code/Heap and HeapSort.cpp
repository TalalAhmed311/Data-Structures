
#include <stdio.h>
#include<stdlib.h>


// Sunmitted by Talal Ahmed
//Seat No: B18158059


int heap[10];
int count=0;
int len=sizeof(heap)/4;

void swap(int *t1,int *t2){
	
	int x=*t1;
	*t1=*t2;
	*t2=x;
}


// insertion in heap

void insert(int value){
	
	if(count>=len){
		printf("Heap Overload...");
		return;
	}
	heap[count]=value;
	int i=count;
	
	while(i>0){

// here i am finding the parent index;
		int p=(i-1)/2;


//	If the value which is going to be insert is greater than parent value then swap them
// this works until i reaches to 0		
		if(heap[p]<value){
			swap(&heap[p],&heap[i]);
			i=p;			
		}else{
			break;
		}
	}
	
	count++;
}


void heapify(int arr[],int n,int i){
	
	int j=i;
	int left=(2*i)+1;
	int right=(2*i)+2;
	
	if(arr[left]>arr[j] && left<n){
		j=left;
	}
	
	if(arr[right]>arr[j] && right<n){
		j=right;
	}
	
	if(j!=i){
		swap(&arr[i],&arr[j]);
		heapify(arr,n,j);
	}
}

void build_Max_Heap(int arr[],int n){
	
	// here i am cutting the length of array into half
	
	for(int i=(n-1)/2;i>=0;i--){
		heapify(arr,n,i);
	}
	
}

void heapSort(int arr[],int n){
	
	
	 build_Max_Heap(arr,n);
	
	 for(int i=n-1;i>=0;i--){
 	
 		swap(&arr[0],&arr[i]);
 	
 		heapify(arr,i,0);
	 }
	
}


void printHeap(){
	
	int i=0;
	
	while(i<count){
		
		printf("Value[%d]: %d\n",i,heap[i]);
		i++;
		
	}
	
}

void deleteHeapValue(int arr[],int n,int value){
	
	int index;
	int flag=0;
	for(int i=0;i<n;i++){
		if(arr[i]==value){
			index=i;
			flag=1;
			break;
		}
	}
	
	if(flag){
	
		// swaping the value  when i found that index value which we want to be deleted	
		// swap the value with the last node
		// after the deleted the value become leaf than simply delete it and 
		//reduce the size of array by 1
		
		swap(&arr[index],&arr[n-1]);
		arr[n-1]='\0';
		n--;
		
		
		// after deleting convert the simple array into heap
		
		build_Max_Heap(arr,n);
		count--;
	}else{
		printf("Value does not exist...");
	}
}


int main(){
	
	
	
	insert(26);
	insert(89);
	insert(45);
	insert(24);
	insert(11);
	insert(74);
	insert(98);
	insert(65);
	insert(12);
	insert(36);
	printHeap();

	
//	printf("\nAfter Sorting the array:\n");
//	heapSort(heap,len);
//	printHeap();
// //	
	printf("\nAfter deletion:\n");
	deleteHeapValue(heap,len,65);
	printHeap();
	return 0;
}
