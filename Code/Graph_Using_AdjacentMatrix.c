#include<stdio.h>
#include<stdlib.h>

#define n 30
int count=0;

// The structure for holding the graph data
struct vertex{
	char data;
};
int len;

//Default Array of Graph 
struct vertex Graph[];
int adj_mat[n][n];

// This method gives the index of Particular graph node 

int getIndex(char data){
	
	int i;
	for(i=0;i<n;i++){
		if(Graph[i].data==data){
			return i;
		}
	}
	
	return -1;
}

//In this method we are making edges between two vertices
//But How?

//First we get the index of of both vertices if they exist in graph
//After checking the vertices in graph then we check whether that graph is Directed or Undirected
//If the Graph is Directed then simply at the row of that first vertex 
// and at the column of 2nd vertex we put 1 there.
//If the Graph is Undirected we simply take 1st and 2nd vertex rows and put 1 at the specify columns


void addEdges(char v1,char v2,int graphType){
	
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

// Here the same process is going as i mention above in the addEdges function
//But different is we put 0 at that specify position.

void removeEdges(char v1,char v2,int graphType){
	
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


//Here we are use a counter to count the degree
//first loop will run row wise and the 2nd loop whill goes in column wise manner 
//It will check if there is 1 in any wow or column we increase the counter.
//And at the end return the counter.


int findDeg(char vertex){
	
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

// here i am doning the procedure but in this method i am just checking the row 
//If there is 1 then increase the counter.

int OutDeg(char vertex){
	
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


//Here i am checking in the column wise manner for In Degree 

int InDeg(char vertex){
	
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


//If the Graph is Directed then we check the 1 by using indexs in vice versa manner
//For exam:adj_mat[0][1] and adj_mat[1][0]/
//In Undirected graph i am checking it in that specific row from where the vertex belong.

void findNeighbors(char vertex,int graphType){
	
	
		int i=getIndex(vertex);
		int j;
		if(i!=-1) {
			printf("Neighbors of %c:",vertex);
			if(graphType==1) {
				
				
				for (j = 0; j <n; j++) {
					
					if(adj_mat[i][j]==1) {
						printf("%c,",Graph[j].data);
						
					}else if (adj_mat[j][i]==1) {
						
						printf("%c,",Graph[j].data);
					}
					
				}
				
			}else {
				
				
				for (j = 0; j <n; j++) {
					
					if(adj_mat[i][j]==1) {
						printf("%c,",Graph[j].data);
					}
				}
				
			}
			
		}else{
			printf("vertex does not exist.\n");
		}
		
	printf("\n");
}

//If there is 1 on a specific vertex and
//same as the other side then the vertices are adjacent.

void isAdjacent(char v1,char v2){
	
	
	int i1=getIndex(v1);
	int i2=getIndex(v2);
		
		if(i1!=-1 && i2!=-1) {
			
			if(adj_mat[i1][i2]==1) {
				printf("Yes Both are Adjecent.");
			}else {
				printf("Both are not adjacent.");
			}
		}else{
			printf("vertices does not exist.\n");
		}
	
}


// Here i am just simply printing the matrix.
void printMatrix(int len){
	
	int i,j;
	
	for(i=0;i<len;i++){
		
		for(j=0;j<len;j++){
			printf("%d ",adj_mat[i][j]);
		}
		printf("\n");
	}
		
	
}

// Printing the Whole Graph.
void showGraph(int len,struct vertex Graph[]){
	
	int i,j;
	
	for(i=0;i<len;i++){
		printf("%c->",Graph[i].data);
		for(j=0;j<len;j++){
			
			if(adj_mat[i][j]==1){
				printf("%c->",Graph[j].data);
			}
		}
		printf("\n");
	}
	
}

int main(int argc,char *argv[]){

	
	int graphType;
	
	printf("Enter the length of the Graph= ");
    scanf("%d",&len);
    
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
		scanf(" %c",&Graph[i].data);
		
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
			printf("6)PrintMatrix\n");
			printf("7)Print Graph\n");
			printf("Press 0 for exit.\n");
			int option;
			scanf("%d",&option);
			printf("\n");
			char e1,e2;
			
			switch (option) {
			case 1:
				
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				addEdges(e1, e2,graphType);
				
				
				break;
			case 2:
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				removeEdges(e1, e2,graphType);
				break;
			case 3:
				printf("Enter the Vertex:");
				scanf(" %c",&e1);
				findNeighbors(e1,graphType);
				
				break;
				
			case 4:
				
				if(graphType==1) {
					
					printf("Enter the Vertex:");
					scanf(" %c",&e1);
					printf("In Degree:%d",InDeg(e1));	
				}else {
			
					printf("Enter the Vertex1:");
					scanf(" %c",&e1);
					printf("Enter the Vertex2:");
					scanf(" %c",&e2);
					isAdjacent(e1, e2);
				
				}
				
				break;

			case 5:
				
				if(graphType==1) {
				
					printf("Enter the Vertex:");
					scanf(" %c",&e1);
					printf("Out Degree: %d\n",OutDeg(e1));
				}else{
					
					printf("Enter the Vertex:");
					scanf(" %c",&e1);
					printf("Degree: %d\n",findDeg(e1));		
				}
				
				break;
				
			case 6:
				printMatrix(len);
				break;
			case 7:
				showGraph(len,Graph);
				break;
			default:
				flag=0;
				break;
			}
			
		
			
		}	
	
	
	return 0;
}
