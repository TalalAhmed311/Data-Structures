#include<stdio.h>
#include<stdlib.h>

// Name: Talal Ahmed 
// Roll:B18158059


// THe vertex in whcih the data stores.
struct vertex{
	char data;
	struct vertex *next;
	struct edge *edgelist;
	int visited;
}*Graph=NULL;

// For Edges of that vertex.
struct edge{
	struct vertex *v;
	struct edge * next;
	int weight;
};


int count=0;
int graphType;

struct Queue{
	struct vertex *temp;
	struct Queue *next;
	
}*start=NULL,*tail=NULL;



void Enqueue(struct vertex  *p){
	
	struct Queue *ptr=(struct Queue *)malloc(sizeof(struct Queue));
	ptr->temp=p;
	ptr->next=NULL;
	
	if(start==NULL){
		start=ptr;
		tail=ptr;
	}else{
		
		tail->next=ptr;
		tail=ptr;
		
	}
}

struct vertex *Dequeue(){
	
	struct vertex *value=NULL;
	if(start!=NULL){
		struct Queue *p=start;
		value=p->temp;
		start=start->next;
		free(p);
	}
	return value;
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


void addEdges(char v1,char v2){
	
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
	
			struct edge *p1=(struct edge *)malloc(sizeof(struct edge));
			p1->v=n1;
			p1->next=NULL;
			
			
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

// This method will check eeither an vertex contain another as an edges or not.

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
	
	while(src!=NULL){
		
		if(src->visited==0){
			unSelectVertices();
			return 0;	
		}	
		src=src->next;
	}
	
		
	
	return 1;
}

void OutputGraph(){
	
	struct vertex *start=Graph;
	
	while(start!=NULL){
		struct edge *el=start->edgelist;
		printf("%c->",start->data);
		
		while(el!=NULL){
			
			printf("%c->",el->v->data);	
			el=el->next;
		}
		start=start->next;
		printf("\n");
	}
}


//We start this algorithm with the starting vertex 
//Enqueue it and then start a loop which run until queue becomes empty
//next we pop the element and then take it edge list and also print that  vertex
//After that we enqueue all the edgelist elements of vertex which are unvisited
//Mark them visited and then again repeat the process until queue becomes empty.

void BFS(){
	
	
	struct vertex *src=Graph;
	src->visited=1;
	
	Enqueue(src);
	
	printf("BFS: ");
	while(start!=NULL){
		
		struct vertex *temp=Dequeue();
		struct edge *el=temp->edgelist;
		
		printf("%c,",temp->data);
		while(el!=NULL){
			
			if(el->v->visited==0){
				el->v->visited=1;
				Enqueue(el->v);
				
			}
			
			el=el->next;
		}
		
		
		
	}
	
	printf("\n\n");
	unSelectVertices();	
	
}

// Again we repeat the preious but with small change
//Here we take dequeue element and then check whether it is equal to tosearch data.
void BFSSearch(char value){
	
	int boolean=0;
	unSelectVertices();
	struct vertex *src=Graph;
	src->visited=1;
	
	Enqueue(src);
	
	while(start!=NULL){
		
		struct vertex *temp=Dequeue();
		struct edge *el=temp->edgelist;
	
		if(temp->data==value){
			boolean=1;
			break;
		}
		
		while(el!=NULL){
			if(el->v->visited==0){
				el->v->visited=1;
				Enqueue(el->v);
				
			}
			
			el=el->next;
		}
			
	}
//	
	if(boolean==0){
		printf("Not Found.\n");
	}else{
		printf("Found.\n");
	}
}

void unSelectVertices(){
	
	
	struct vertex *temp=Graph;
	
	while(temp!=NULL){
		temp->visited=0;
		temp=temp->next;
	}
		
}

int main(){
	
	
	printf("Which type of graph you want to make:\n");
    printf("1)Press 1 for Directed:\n");
    printf("2)Press 2 for Undirected:\n");
    scanf("%d",&graphType);

	if(graphType==1 || graphType==2){
		
		printf("Choose option from given option\n");
		int flag=1;
	
		while(flag){
			
			printf("1)Add Vertex\n");
			printf("2)Add Edges\n");
			printf("3)Remove Vertex\n");
			printf("4)Remove Edges\n");
			printf("5)Is Graph Connected\n");
			printf("6)OutPut Graph\n");
			printf("7)BFS Traversal\n");
			printf("8)BFS Search\n");	
			
			printf("Press 0 for exit.\n");
			int option;
			scanf("%d",&option);
			printf("\n");
			char e1,e2;
	
			switch(option){
				
				case 1:
				printf("Enter the vertex:");
				scanf(" %c",&e1);
				addVertex(e1);
				
				printf("\n");
				break;
	
				case 2:
		
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				addEdges(e1,e2);
				
				printf("\n");
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
				
					
					if(isGraphConnected()==1){
						printf("Graph is Connected.\n");
					}else{
						printf("Graph is not connected.\n");
					}
					printf("\n");
					break;
				case 6:
					OutputGraph();
					printf("\n");
					break;
				case 7:
					BFS();
					break;
				case 8:
					
					if(isGraphConnected()==1){
					
					printf("Enter vertex you want to search: ");
					scanf(" %c",&e1);
					BFSSearch(e1);
						
					}else{
						printf("graph is not Connected.\n");
					}
					
					printf("\n");
					break;
				default:
					flag=0;
					break;
			}
			
		}
		
	}else{
		
		printf("Invalid Input.");
	}
		
	return 0;
}
