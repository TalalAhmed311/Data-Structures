#include<stdio.h>
#include<stdlib.h>
#define INFINITY 10000

// THe vertex in whcih the data stores.
struct vertex{
	char data;
	struct vertex *next;
	struct edge *edgelist;
	int visited;
	int distance;
}*Graph=NULL;

// For Edges of that vertex.
struct edge{
	struct vertex *v;
	struct edge * next;
	int weight;
};



// This variable refers for the graph type either diected or undirected.
int count=0;
int graphType;

struct Stack{
	char v;
	struct Stack *next;
	 
}*start=NULL,*top=NULL;

void Push(char v){
	struct Stack *ptr=(struct Stack *)malloc(sizeof(struct Stack));
	ptr->v=v;
	ptr->next=NULL;
	
	if(start==NULL){
		start=ptr;
		top=start;
	}else{
		top->next=ptr;
		top=ptr;
	}
}


char Pop(){
	char v;
	if(start==NULL){
		return '@';
	}
	struct Stack *temp=NULL;
	if(top==start){
		temp=top;
		v=temp->v;
		start=start->next;
		top=start;
		free(temp);
	}else{
		
		temp=start;
		while(temp->next!=top){
			temp=temp->next;
		}
		struct Stack *p=temp->next;
		v=p->v;
		temp->next=NULL;
		top=temp;
		free(p);
		
		
	}
	
	return v;


}



// Here we are getting the required vertex from the graph.

struct vertex *getVertex(char v){
	
	struct vertex *curr=Graph;
	
	while(curr!=NULL){
		if(curr->data==v){
			return curr;
		}
		curr=curr->next;
	}
	
	return curr;
}



// Adding a vertex in the graph.

void addVertex(char v){
	
	struct vertex *ptr=(struct vertex *)malloc(sizeof(struct vertex));
	ptr->data=v;
	ptr->visited=0;
	ptr->next=NULL;
	ptr->edgelist=NULL;
	ptr->distance=-1;
	
	struct vertex *p=getVertex(v);
	
	if(p!=NULL){
		printf("Vertex is already exist.");
		return;
	}
	if(Graph==NULL){
	
		Graph=ptr;
	
	}else{
		
		struct vertex *curr=Graph;
		while(curr->next!=NULL){
			curr=curr->next;
		}	
		
		curr->next=ptr;
	}
	
	count++;
}


// Removing the vertex from the graph.

void removeVertex(char v){
	
	
	struct vertex *curr=Graph;
	struct vertex *prev=NULL;
	
	int flag=0;
	
	if(Graph==NULL){
		printf("Graph is Empty.");
		return;
	}
	
	// Here we are finding the previous and the vertex which will be deleted.
	
	while(curr!=NULL){
		if(curr->data==v){
			flag=1;
			break;
		}
		prev=curr;
		curr=curr->next;
	}	
	
	
	// If vertex eixst...
	
	if(flag==1){
	
	
	// Get that vertex edgeList.
	
	struct edge *temp=curr->edgelist;
	
	char arr[count];
	int i=0;
	
	while(temp!=NULL){
		arr[i]=temp->v->data;
		temp=temp->next;
		i++;	
	}
	arr[i]='\0';
	
	//After storing the edges of that vertices in that array.
	int j=0;
	
	// Here we are removing the vertex.
	// Remove the edges of that the tat vertex.
	
	while(j<i){
		
		removeEdges(curr->data,arr[j]);
		j++;	
	}
	
	//If graph Type is Directed.
	
	if(graphType==1){
	
		struct vertex *start=Graph;
		struct edge *e=start->edgelist;
		
		//First get the starting vertex and get that edge list.
			
		while(start!=NULL){
		
			int x=0;
			char edges[count];
			
			//Storing edgeList into an array.
						
			while(e!=NULL){
				edges[x]=e->v->data;
				e=e->next;
				x++;	
			}
			edges[x]='\0';
			printf("\n");
			j=0;
			
			// Then remove  that vertex.
			// From all of the other vertics.
			
			while(j<x){
				
				if(edges[j]==curr->data){
					removeEdges(start->data,edges[j]);
					break;
				}
				j++;
			}
			start=start->next;
			
			if(start!=NULL){
			
				e=start->edgelist;
				
			}
			
		}
		
		
	}
	
	}
	
	// Here we delete that vertex free its memory.
	if(curr==Graph){
		
		struct vertex *p=Graph;
		Graph=Graph->next;
		free(p);
				
	}else{
		
		struct vertex *p=curr;
		prev->next=curr->next;
		free(p);
		
	}
		
	
	
	
	
	
}


void addEdges(char v1,char v2,int w){
	
	struct vertex *n1,*n2,*curr;
	curr=Graph;
	int flag=0;
	if(Graph!=NULL){
		
		// Get vertices with which we make edges.
		
		while(curr!=NULL){
			if(curr->data==v1){
				n1=curr;
				flag++;
				
			}else if(curr->data==v2){
				n2=curr;
				flag++;
			}
			
			curr=curr->next;
		}
		
			
		if(flag==2){
			
		
			// If They are not edges to each other.
				
			if(containsEdge(n1,n2)==1){
				printf("They are already edge to each other");
				return;
			}			
			
		
			// Storing that vertices into temporary pointers.
			
			struct edge *p2=(struct edge *)malloc(sizeof(struct edge));
			p2->v=n2;
			p2->next=NULL;
			p2->weight=w;
			
			struct edge *p1=(struct edge *)malloc(sizeof(struct edge));
			p1->v=n1;
			p1->next=NULL;
			p1->weight=w;
			
			// IF starting edges edge is null then make n2 edge to n1.
			// If not starting get n1 edgelist then move it forward until we reach to a null edge.
			// Ten make n2 edge to n1.
			if(n1->edgelist==NULL){
		
				n1->edgelist=p2;
			
			}else{
		
				
				
				struct edge *temp=n1->edgelist;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				
				temp->next=p2;
			}
			
			
			// If the graph is Undirected 
			// Then make n1 edge to n2 and vice versa.
			
			if(graphType==2){
				
			if(n2->edgelist==NULL){
				
		
				n2->edgelist=p1;
				
			}else{
		
				
				
				struct edge *temp=n2->edgelist;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=p1;
				
			}	
			}	
			
			
				
			
		}else{
			printf("Please Enter correct vertices.");
		}
		
		
		
	}else{
		printf("Graph is Empty.");
	}
}


// This method will check either an vertex contain another as an edges or not.

int containsEdge(struct vertex *src,struct vertex *des){
	
	struct edge *temp=src->edgelist;
	while(temp!=NULL){
		if(temp->v->data==des->data){
			return 1;
		}
		
		temp=temp->next;
	}
	
	return 0;
	
}



// As we add edges,same process will to remove edges.

void removeEdges(char v1,char v2){
	
	struct vertex *n1,*n2,*curr;
	curr=Graph;
	int flag=0;
	
		
		while(curr!=NULL){
			if(curr->data==v1){
				n1=curr;
				flag++;
				
			}else if(curr->data==v2){
				n2=curr;
				flag++;
			}
			
			curr=curr->next;
		}
		
	printf("\n");
	if(flag==2){
	
		flag=0;
		
		// if n1 contain n2 as an edges
		
		if(containsEdge(n1,n2)==1){
			
			// If edge id found then simply takke that edge into an 
			// temporay pointer and then free its memory.	
			if(n1->edgelist->v->data==n2->data){
				struct edge *p=n1->edgelist;
				n1->edgelist=n1->edgelist->next;
				flag++;
				free(p);
			}else{
				
				struct edge *prev,*temp;
				prev=n1->edgelist;
				temp=n1->edgelist->next;
				
				while(temp!=NULL){
					
					if(temp->v==n2){
						struct edge *p=temp;
						prev->next=temp->next;
						free(p);
						flag++;
						break;	
					}
					prev=temp;
					temp=temp->next;
				}
			}
			
			
			// If the graph is Undirected then we have apply same process as mention above on n2
			
			if(graphType==2){
				
			if(n2->edgelist->v->data==v1){
				
				struct edge *p=n2->edgelist;
				n2->edgelist=n2->edgelist->next;
				flag++;
				free(p);
				
			}else{
				struct edge *prev,*temp;
				prev=n2->edgelist;
				temp=n2->edgelist->next;
				
				while(temp!=NULL){
					
					if(temp->v->data==n1->data){
						struct edge *p=temp;
						prev->next=temp->next;
						free(p);
						flag++;
						break;	
					}
					prev=temp;
					temp=temp->next;
				}
				
			}
			
		}
			
			
		
		
		
			
		}
			
		if(flag==0){
			printf("They are not edges to each other.");
		}
		
	}else{
		
		printf("vertices does not exist.\n");
	}

	
	
	
}




void OutputGraph(){
	
	struct vertex *start=Graph;
	
	while(start!=NULL){
		struct edge *el=start->edgelist;
		printf("%c->",start->data);
		
		while(el!=NULL){
			
			printf("%c  %d ->",el->v->data,el->weight);	
			el=el->next;
		}
		start=start->next;
		printf("\n");
	}
}






void showEdges(struct vertex *p){
	
	struct edge *temp=p->edgelist;
	printf("%c-> ",p->data);
	while(temp!=NULL){
		printf("%c-> ",temp->v->data);
		temp=temp->next;
	}
}





//Here simply using DFS i am making all vertices visited
void GraphConnection(struct vertex *src){

	src->visited=1;
	struct edge *el=src->edgelist;

	while(el!=NULL){
		if(el->v->visited==0){
			GraphConnection(el->v);
		}
		el=el->next;
	}
}


// If graph is not connected then we also check all of the other vertices.

int isGraphConnected(){
	
	struct vertex *src=Graph;
	
	GraphConnection(src);
	src=Graph;
	
	int flag=0;
	while(src!=NULL){
		
		if(src->visited==0){
			return 0;
		}	
		src=src->next;
	}
	
	src=Graph;
	while(src!=NULL){
		src->visited=0;
		src=src->next;
	}
	
	
	return 1;
	
}

// Here we taking the smallest vertex of distance.
struct vertex *getSmallest(){
	
	struct vertex *temp=NULL;
	struct vertex *curr=Graph;
	int min=1000000;
	
	while(curr!=NULL){
		
		if(curr->visited==0){
			if(min>curr->distance){
				min=curr->distance;
				temp=curr;
			}
		}
		
		curr=curr->next;
	}
	
	
	return temp;
}


// Making all the vertices distnaces as infinite.
void makeDisInfinite(){
	
	
	struct vertex *src=Graph;
	
	while(src!=NULL){
		
		src->distance=INFINITY;
		src=src->next;
	}
		
}


// I used the same appraoch which i used in Prim'Algo MST
// First make all the distance as infinite and 0 for starting vertex.
// In loop take that vertex edgelist and then check the condition of Dijkstra Algo
//If it is true then simply update the distance of the vertex.
//after this loop getthe smallest distance value verte from Graph which are unvisited.
// And after that repeat the process until we have Vertex left as unvisited.
// And lastly print all the paths and distances. 

void dijkstra(){
	
	struct vertex  *src=Graph;
	
	makeDisInfinite();
	
	src->distance=0;
	src->visited=1;
	int n=0;
	
	while(n<count-1){
		
		struct edge *el=src->edgelist;
		
		while(el!=NULL){
			
			if(el->v->visited==0){
				
				if((src->distance+el->weight)<el->v->distance){
					
					el->v->distance=src->distance+el->weight;
				}
			}
			
			el=el->next;
		}	
		
		src=getSmallest();
		
		if(src==NULL){
			
			break;
		}
		
		src->visited=1;
		n++;
	}
	
	printPath();	
	unSelectVertices();
}



//In loop i used a method print all paths from the initial vertex to all the other vertices with their distances.

void printPath(){
	
	struct vertex *src=Graph;
	char data=src->data;
	src=src->next;
	
	printf("Vertex\t\t");
	printf("Destination\t\t");
	printf("Distance\t\t");
	printf("Path");
	printf("\n\n");
	
	
	while(src!=NULL){
		
		printf("  %c \t\t",data);
		printf("    %c \t\t",src->data);		
		printf("  \t%d \t\t\t",src->distance);
		printAllPaths(data,src);
		printf("\n");
		src=src->next;
	}
	
	
	
	
	
}




void unSelectVertices(){
	
	
	struct vertex *temp=Graph;
	
	while(temp!=NULL){
		temp->visited=0;
		temp=temp->next;
	}
		
}

//Take the des value and then take that destination to its initial source 
// Just by calculating a simple formula
//I am taking the distance of the des(Destination) - from the weight of its edgelist.
// If we found an vertex whose distance is  equal to this formula this means that we found its src
//And push that into stack.
// Reapeat this process until our des and src matches  
// after this print the stack-> whic is our path.
void printAllPaths(char src_data,struct vertex *des){

	
	// If graph is Undirected.
	if(graphType==2){
		
	struct edge *el=des->edgelist;
	while(des->data!=src_data){
		
		if((des->distance)-(el->weight)==el->v->distance){
			Push(des->data);
			des=el->v;
			el=des->edgelist;
		}else{
			el=el->next;
		}
		
	}
//	
//	
	printf("%c,",src_data);
	while(start!=NULL){

	char v=Pop();
	printf("%c, ",v);
		
	}
	
	}else if(graphType==1){
		
		struct vertex *src=Graph;
		int f=0;
		
		
		while(src!=NULL){
			f=0;
			struct edge *el=src->edgelist;
			
			while(el!=NULL){
						
				if(des->data==el->v->data){
					if(des->distance-el->weight==src->distance){
						Push(des->data);
						des=src;
						src=Graph;
						f=1;
						break;
					}
				}
				
				el=el->next;
			}
			
			if(src->data==des->data){
				break;
			}
			
			if(f==0){
				src=src->next;
			}
		}
		
		printf("%c, ",src_data);
		while(start!=NULL){
			char v=Pop();
			printf("%c,",v);
		}
	}
}


int main(){
	
	
	Graph=NULL;
	
	printf("Which type of graph you want to make:\n");
    printf("1)Press 1 for Directed:\n");
    printf("2)Press 2 for Undirected:\n");
    scanf("%d",&graphType);

	if(graphType==1 || graphType==2){
		
	
	
	printf("Choose option from given option");
	int flag=1;
	while(flag) {
			printf("\n");
			
			printf("1)Add Vertex\n");
			printf("2)Add Edges\n");
			printf("3)Remove Vertex\n");
			printf("4)Remove Edges\n");
			printf("5)OutPut Graph\n");
			printf("6)Shortest Path Using Dijkstra\n");
			
			printf("Press 0 for exit.\n");
			int option;
			scanf("%d",&option);
			printf("\n");
			char e1,e2;
			int w;
			
			switch (option) {
			
			case 1:
		
				printf("Enter the vertex:");
				scanf(" %c",&e1);
				addVertex(e1);
				break;
			case 2:
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				printf("Enter the wight:");
				scanf("%d",&w);
				addEdges(e1,e2,w);
				break;
			case 3:
				printf("Enter the vertex:");
				scanf(" %c",&e1);
				removeVertex(e1);
				break;
			case 4:
			
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				removeEdges(e1,e2);
			
				break;
			case 5:
				OutputGraph();
				break;	
			
			case 6:
			
				if(isGraphConnected()==1){
				
					dijkstra();
					
				}else{
					printf("Graph is not Connected");
				}
				break;
			default:
				flag=0;
				break;
			}
			
		
		printf("\n");		
		}	
	}else{
		printf("Invalid Input.\n");
	}
	
	return 0;
}
