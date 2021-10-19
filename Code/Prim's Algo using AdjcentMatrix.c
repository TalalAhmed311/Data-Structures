#include<stdio.h>
#include<stdlib.h>

#define n 30
int count=0;

//The structure for holding the graph data
struct vertex{
	char data;
};
int len;
int graphType;
//Default Array of Graph 
struct vertex Graph[n];
int adj_mat[n][n];
int mst[n][n];

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


void addEdges(char v1,char v2,int weight){
	
		int i1=getIndex(v1);
		int i2=getIndex(v2);
		
		if(adj_mat[i1][i2]!=0){
			printf("Already Edge to each other.");
			return;
		}
		
		if(i1!=-1 && i2!=-1) {

			if(graphType==1) {
				adj_mat[i1][i2]=weight;
				
			}else {
				adj_mat[i1][i2]=weight;
				adj_mat[i2][i1]=weight;
				
			}

		}else{
			printf("Vertex does not exist.\n");
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
			
			if(adj_mat[i][j]!=0){
				printf("%c->",Graph[j].data);
			}
		}
		printf("\n");
	}
	
}

void createMst(){
	
	
	int min=100000;
	int noEdge=0;
	
//	Make array for selected vertices.

	int selected[len];
	
// set all of them as unvisited
	
	int i=0,j;
	while(i<len){
		selected[i]=-1;
		i++;
	}
	
//	select 1st one
	selected[0]=1;
	
	int x=0,y=0;
	while(noEdge<len-1){
		for(i=0;i<len;i++){
			if(selected[i]==1){
				
				
				for(j=0;j<len;j++){
					
					if(selected[j]!=1 && adj_mat[i][j]!=0){
					
					if(min>=adj_mat[i][j] ){
						
						min=adj_mat[i][j];
						x=i;
						y=j;						
						
					}
						
					}
					
				}
				
			}
			
		}	
		
//		insert into mst 
		insertMst(x,y,min);
		selected[y]=1;
		min=100000;	
		noEdge++;
	}
	printMst();
}

void insertMst(int i,int j,int minWeight){
	
		if(graphType==1){
			
			mst[i][j]=minWeight;
		}
		else{
		
	    	mst[i][j]=minWeight;
		    mst[j][i]=minWeight;
		
		}
		
}

void printMst(){
	
	int i,j;
	
	for(i=0;i<len;i++){
		
		printf("%c-> ",Graph[i].data);
		
		for(j=0;j<len;j++){
			
			if(mst[i][j]!=0){
				
				printf("V:%c W:%d -> ",Graph[j].data,mst[i][j]);
				
			}
			
		}
			
		printf("\n");
		
	}
	
}

void mstMatrix(){
	
	int i,j;
	
	for(i=0;i<len;i++){
		
		for(j=0;j<len;j++){
			
			printf("%d ",mst[i][j]);
		}
		printf("\n");
	}
	
}

int main(int argc,char *argv[]){

	
	
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
			printf("2)OutPut Graph\n");
			printf("3)Create MST:\n");
			printf("4)mstMatrix\n");
			
			printf("Press 0 for exit.\n");
			int option;
			scanf("%d",&option);
			printf("\n");
			char e1,e2;
			int w;
			
			switch (option) {
			
			case 1:
	
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				printf("Enter the wight:");
				scanf("%d",&w);
				addEdges(e1,e2,w);
	
				break;
			case 2:
				showGraph(len,Graph);
				break;
			
			case 3:
				createMst();
				break;	
			
			case 4:
				mstMatrix();
				break;
			
				
			default:
				flag=0;
				break;
			}
			
		
		printf("\n");		
		}	
	
	
	return 0;
}
