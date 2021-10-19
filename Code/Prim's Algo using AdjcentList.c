#include<stdio.h>
#include<stdlib.h>

//Name: Talal Ahmed
// Roll: B18158059


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

// This is the MST vertex struct
struct MSTVertex{
	
	char data;
	struct MSTVertex *next;
	struct mstEdge *edgelist;
	
}*MST=NULL;

struct mstEdge{
	
	struct MSTVertex *mstv;
	struct mstEdge *next;
	int weight; 
	
};

// This variable refers for the graph type either diected or undirected.
int graphType;
int count=0;
int cost=0;


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
	
//	if(graphType==1){
//	
//		struct vertex *start=Graph;
//		struct edge *e=start->edgelist;
//		
//		//First get the starting vertex and get that edge list.
//			
//		while(start!=NULL){
//		
//			int x=0;
//			char edges[count];
//			
//			//Storing edgeList into an array.
//						
//			while(e!=NULL){
//				edges[x]=e->v->data;
//				e=e->next;
//				x++;	
//			}
//			edges[x]='\0';
//			printf("\n");
//			j=0;
//			
//			// Then remove  that vertex.
//			// From all of the other vertics.
//			
//			while(j<x){
//				
//				if(edges[j]==curr->data){
//					removeEdges(start->data,edges[j]);
//					break;
//				}
//				j++;
//			}
//			start=start->next;
//			
//			if(start!=NULL){
//			
//				e=start->edgelist;
//				
//			}
//			
//		}
//		
//		
//	}
	
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
			
				
				
			if(n2->edgelist==NULL){
				
		
				n2->edgelist=p1;
				
			}else{
		
				
				
				struct edge *temp=n2->edgelist;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=p1;
				
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
			
			printf("%c  %d->  ",el->v->data,el->weight);	
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
			unSelectVertices();
			return 0;
		}	
		src=src->next;
	}
	

	unSelectVertices();
	
	return 1;
}

// Here i am taking the starting vertex.
//And initializing 3 loops.
//1st run unitl no egdes becomes vertex-1
//2nd take that src edgelist and then check whether that src is visited or not
//If it is then in 3rd loop check the edgelist vertex weight with the min weight and also that vertex should not be visited.
//if condition is true then update the min value and in p1 put src and in p2 put edgelist vertex.
//Mark that p2 vertex as visited after these two loops and insert in into the Mst.
//Again start that graph from its starting vertex.
//In this process we just simply checking all the vertices and their edges in order to find the min weight value 
// and then put it into mst.
void createMST(){
	
	struct vertex  *src=Graph;
	
	src->visited=1;
	int n=0;
	
	int min=1000000;
	while(n<count-1){
		
		struct vertex *p1,*p2;
		p1=NULL;
		p2=NULL;
			
		// 0->1 4  0->7 8
		// 1->0 4, 2 8, 7 11
		while(src!=NULL){
		struct edge *el=src->edgelist;	
			
			if(src->visited==1){
				
			
			while(el!=NULL){
				
				if(el->weight<=min && el->v->visited==0){
					min=el->weight;
					p1=src;
					p2=el->v;
			
				}
				el=el->next;
			}
			
				
			}
			src=src->next;
		}
		
		p2->visited=1;
		insertMST(p1,p2,min);
		src=Graph;
		min=100000;
		n++;
		
	}
	
	unSelectVertices();
}


//Inserting into the mst Graph.
void insertMST(struct vertex *v1,struct vertex *v2,int minWeight){
	
	
	
	cost=cost+minWeight;
	if(MST==NULL){


	struct MSTVertex *p1=(struct MSTVertex *)malloc(sizeof(struct MSTVertex));
	p1->data=v1->data;
	p1->edgelist=NULL;
	p1->next=NULL;
	
	struct MSTVertex *p2=(struct MSTVertex *)malloc(sizeof(struct MSTVertex));
	p2->data=v2->data;
	p2->edgelist=NULL;
	p2->next=NULL;

		
		MST=p1;
		MST->next=p2;
	
	
	
	struct mstEdge *e1=(struct mstEdge *)malloc(sizeof(struct mstEdge));
	struct mstEdge *e2=(struct mstEdge *)malloc(sizeof(struct mstEdge));
			
	
	e1->mstv=p2;
	e1->weight=minWeight;
	e1->next=NULL;
	
	e2->mstv=p1;
	e2->weight=minWeight;
	e2->next=NULL;

	p1->edgelist=e1;
	p2->edgelist=e2;
	
	}else{

			struct MSTVertex *p2=(struct MSTVertex *)malloc(sizeof(struct MSTVertex));
			p2->data=v2->data;
			p2->edgelist=NULL;
			p2->next=NULL;
	

		struct MSTVertex *curr=MST;
		
		struct MSTVertex *n1,*n2;
		
		while(curr->next!=NULL){
			curr=curr->next;
		}
		
		curr->next=p2;
	
			
		
		
		curr=MST;
		
		while(curr!=NULL){
			
			if(curr->data==v1->data){
				n1=curr;
			}else if(curr->data==v2->data){
				n2=curr;
			}
			
			curr=curr->next;
		}
		
		
		struct mstEdge *e1=(struct mstEdge *)malloc(sizeof(struct mstEdge));
		struct mstEdge *e2=(struct mstEdge *)malloc(sizeof(struct mstEdge));
			
		e1->mstv=n2;	
		e1->next=NULL;
		e1->weight=minWeight;
		
		
		e2->mstv=n1;
		e2->next=NULL;
		e2->weight=minWeight;
	
		
		if(n1->edgelist==NULL){
			n1->edgelist=e1;
			
		}else{
	
			struct mstEdge *el=n1->edgelist;
			
			while(el->next!=NULL){
				el=el->next;
			}
			
			el->next=e1;
			
		}
		
		
		if(n2->edgelist==NULL){
	
			n2->edgelist=e2;
			
		}else{
			
			
			struct mstEdge *el=n2->edgelist;
			
			while(el->next!=NULL){
				el=el->next;
			}
			el->next=e2;
					
		}
		
	}	
		
	
}


void unSelectVertices(){
	
	
	struct vertex *temp=Graph;
	
	while(temp!=NULL){
		temp->visited=0;
		temp=temp->next;
	}
		
}

void printMST(){
	
	struct MSTVertex *curr=MST;

	
	
	
	while(curr!=NULL){
		printf("%c->",curr->data);
		
		struct mstEdge *el=curr->edgelist;
				
		while(el!=NULL){
			printf(" %c %d -> ",el->mstv->data,el->weight);
			el=el->next;
	
		}
		
		printf("\n");
		curr=curr->next;
	}
	printf("\n");	
	printf("Cost: %d\n",cost);	
	
}

int main(){
	
	
	Graph=NULL;
	
	
	
	
	
	

		
	
	printf("Choose option from given option");
	int flag=1;
	while(flag) {
			printf("\n");
			
			printf("1)Add Vertex\n");
			printf("2)Add Edges\n");
			printf("3)Remove Vertex\n");
			printf("4)Remove Edges\n");
			
			printf("5)OutPut Graph\n");
			printf("6)Create MST:\n");
			printf("7)PrintMST\n");
			
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
			
					createMST();
					
				}else{
					printf("Graph is not Connected.\n");
				}
				printf("\n");
				break;
			
			case 7:
				printMST();
				printf("\n");
				break;
			
				
			default:
				flag=0;
				break;
			}
			
		
		printf("\n");		
		}	
	
	
	return 0;
}
