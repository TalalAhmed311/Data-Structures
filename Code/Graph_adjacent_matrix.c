#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define n 30
int count=0;
//int n;
struct vertex{
	int data;
};
int len;
struct vertex Graph[];
int adj_mat[n][n];

int getIndex(int data){
	
	int i;
	for(i=0;i<n;i++){
		if(Graph[i].data==data){
			return i;
		}
	}
	
	return -1;
}

void addEdges(int v1,int v2,int graphType){
	
		int i1=getIndex(v1);
		int i2=getIndex(v2);
		
		if(i1!=-1 && i2!=-1) {

			if(graphType==1) {
				adj_mat[i1][i2]=1;
				
			}else {
				adj_mat[i1][i2]=1;
				adj_mat[i2][i1]=1;
				
			}

		}else{
			printf("Vertex does not exist.\n");
		}

}

void removeEdges(int v1,int v2,int graphType){
	
	int i1=getIndex(v1);
	int i2=getIndex(v2);
		
		if(i1!=-1 && i2!=-1) {
			
			if(graphType==1) {
				
				adj_mat[i1][i2]=0;
				
			}else {
				adj_mat[i1][i2]=0;
				adj_mat[i2][i1]=0;
			}

			
		}else{
			printf("vertex does not exist.\n");
		}

}


int findDeg(int vertex){
	
		int i=getIndex(vertex);
		int counter=0;
		int j;
		if(i!=-1) {
			
			for (j = 0; j < n; j++) {
				
				if(adj_mat[i][j]==1) {
					counter++;
				}
			}
		}else{
			printf("vertex does not exist.\n");
		}
		
		return counter;

}


int OutDeg(int vertex){
	
		int i=getIndex(vertex);
		int counter=0;
		int j;
		
		if(i!=-1) {
			

			for (j = 0; j <n; j++) {
				
				if(adj_mat[i][j]==1) {
					counter++;
				}
				
			}
			
		}else{
			printf("vertex does not exist.\n");
		}
		
		return counter;
}


int InDeg(int vertex){
	
		int i=getIndex(vertex);
		int counter=0;
		int j;
		
		if(i!=-1) {
			

			for ( j = 0; j < n; j++) {
				
				if(adj_mat[j][i]==1) {
					counter++;
				}
				
			}
			
		}else{
			printf("vertex does not exist.\n");
		}
		
		return counter;

}


void findNeighbors(int vertex,int graphType){
	
	
		int i=getIndex(vertex);
		int j;
		if(i!=-1) {
			
			if(graphType==1) {
				
				
				for (j = 0; j <n; j++) {
					
					if(adj_mat[i][j]==1) {
						printf("%d\n",Graph[j].data);
						
					}else if (adj_mat[j][i]==1) {
						printf("%d\n",Graph[j].data);
					}
					
				}
				
			}else {
				
				
				for (j = 0; j <n; j++) {
					
					if(adj_mat[i][j]==1) {
						printf("%d\n",Graph[j].data);
					}
				}
				
			}
			
		}else{
			printf("vertex does not exist.\n");
		}
		
	
}

void isAdjacent(int v1,int v2){
	
	
	int i1=getIndex(v1);
		int i2=getIndex(v2);
		
		if(i1!=-1 && i2!=-1) {
			
			if(adj_mat[i1][i2]==1) {
				printf("Yes Both are Agjecent.");
			}else {
				printf("Both are not adjacent.");
			}
		}else{
			printf("vertices does not exist.\n");
		}
	
}


void printMatrix(int len){
	
	int i,j;
	
	for(i=0;i<len;i++){
		
		for(j=0;j<len;j++){
			printf("%d ",adj_mat[i][j]);
		}
		printf("\n");
	}
		
	
}

int main(int argc,char *argv[]){

	
	int graphType;
	
	printf("Enter the length of the Graph= ");
    scanf("%d",&len);
//    
	printf("Which type of graph you want to make:\n");
    printf("1)Press 1 for Directed:\n");
    printf("2)Press 2 for Undirected:\n");
    scanf("%d",&graphType);
	
	
	Graph[len];
	
	int i;
	
	for(i=0;i<n;i++){
		int x;
		for(x=0;x<n;x++){
			adj_mat[i][x]=0;
		}	
	}


	for(i=0;i<len;i++){
		printf("Enter Data:");
		scanf("%d",&Graph[i].data);
		
	}		
		
	for(i=0;i<len;i++){
		printf("%d,",Graph[i].data);
	}		
	printf("\n");	 


	printf("Choose option from given option");
	int flag=1;
	while(flag) {
			printf("\n");
			
			printf("1)Add Edges\n");
			printf("2)Remove Edges\n");
			printf("3)Find Neighbors\n");
			
			if(graphType==1) {
				printf("4)InDegree\n");
				printf("5)OutDegree\n");
				
			}else{
				
				printf("4)IsAdjacent:\n");
				printf("5)FindDegree\n");
				
			}
			
			int option;
			scanf("%d",&option);
			printf("\n");
			int e1,e2;
			
			switch (option) {
			case 1:
				
				printf("Enter the src:");
				scanf("%d",&e1);
				printf("Enter the des:");
				scanf("%d",&e2);
				addEdges(e1, e2,graphType);
				
				
				break;
			case 2:
				printf("Enter the src:");
				scanf("%d",&e1);
				printf("Enter the des:");
				scanf("%d",&e2);
				removeEdges(e1, e2,graphType);
				break;
			case 3:
				printf("Enter the Vertex:");
				scanf("%d",&e1);
				findNeighbors(e1,graphType);
				
				break;
				
			case 4:
				
				if(graphType==1) {
					
					printf("Enter the Vertex:");
					scanf("%d",&e1);
					printf("%d",InDeg(e1));	
				}else {
			
					printf("Enter the Vertex1:");
					scanf("%d",&e1);
					printf("Enter the Vertex2:");
					scanf("%d",&e2);
					isAdjacent(e1, e2);
				
				}
				
				break;

			case 5:
				
				if(graphType==1) {
				
					printf("Enter the Vertex:");
					scanf("%d",&e1);
					printf("%d\n",OutDeg(e1));
				}else{
					
					printf("Enter the Vertex:");
					scanf("%d",&e1);
					printf("%d\n",findDeg(e1));		
				}
				
				break;
				
			case 6:
				printMatrix(len);
				break;
				
			default:
				flag=0;
				break;
			}
			
		
			
		}	
	
	
	return 0;
}
