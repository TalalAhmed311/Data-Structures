#include<stdio.h>
#include<stdlib.h>


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
};


int graphType;
int count=0;




struct Stack{
	char v;
	struct Stack *next;
	 
}*Path=NULL,*top;

void Push(char v){
	struct Stack *ptr=(struct Stack *)malloc(sizeof(struct Stack));
	ptr->v=v;
	ptr->next=NULL;
	
	if(Path==NULL){
		Path=ptr;
		top=Path;
	}else{
		top->next=ptr;
		top=ptr;
	}
}


char Pop(){
	char v;
	if(Path==NULL){
		return '0';
	}
	struct Stack *temp=NULL;
	if(top==Path){
		temp=top;
		v=temp->v;
		Path=Path->next;
		top=Path;
		free(temp);
	}else{
		
		temp=Path;
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




void removeVertex(char v){
	
	
	struct vertex *curr=Graph;
	struct vertex *prev=NULL;
	
	int flag=0;
	
	if(Graph==NULL){
		printf("Graph is Empty.");
		return;
	}
	
	while(curr!=NULL){
		if(curr->data==v){
			flag=1;
			break;
		}
		prev=curr;
		curr=curr->next;
	}	
	
	
	if(flag==1){
	
		
	struct edge *temp=curr->edgelist;
	
	char arr[count];
	int i=0;
	
	while(temp!=NULL){
		arr[i]=temp->v->data;
		temp=temp->next;
		i++;	
	}
	arr[i]='\0';
	
	int j=0;
	while(j<i){
		
		removeEdges(curr->data,arr[j]);
		j++;	
	}
	
	if(graphType==1){
		struct vertex *start=Graph;
		struct edge *e=start->edgelist;
		
		
		
		while(start!=NULL){
		
			int x=0;
			char edges[count];
					
			while(e!=NULL){
				edges[x]=e->v->data;
				e=e->next;
				x++;	
			}
			edges[x]='\0';
			puts(edges);
			printf("\n");
			j=0;
			
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
			
		
			
			if(containsEdge(n1,n2)==1){
				printf("They are already edge to each other");
				return;
			}			
			
		
			struct edge *p2=(struct edge *)malloc(sizeof(struct edge));
			p2->v=n2;
			p2->next=NULL;
	
			struct edge *p1=(struct edge *)malloc(sizeof(struct edge));
			p1->v=n1;
			p1->next=NULL;
			
			
			if(n1->edgelist==NULL){
		
				n1->edgelist=p2;
			
			}else{
		
				
				
				struct edge *temp=n1->edgelist;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				
				temp->next=p2;
			}
			
			
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
		
		if(containsEdge(n1,n2)==1){
			
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



int InDegree(char v){
	
	
	struct vertex *curr=Graph;
	int flag=0;
	int counter=0;
	
	while(curr!=NULL){
		if(curr->data==v){
			flag=1;
			break;
		}
		curr=curr->next;
	}
	
	if(flag==1){
		
		struct vertex *temp=Graph;
		
		while(temp!=NULL){
			struct edge *el=temp->edgelist;
			
			while(el!=NULL){
				if(curr->data==el->v->data){
					counter++;
				}	
				el=el->next;
			}
			temp=temp->next;
		}
		
	}else{
		printf("vertex does not exist.\n");
	}
	
	return counter;
}


int OutDegree(char v){
	
	struct vertex *curr=Graph;
	int flag=0;
	int counter=0;
	
	while(curr!=NULL){
		if(curr->data==v){
			flag=1;
			break;
		}
		curr=curr->next;
	}
	
	if(flag==1){
		
		struct edge *e=curr->edgelist;
		while(e!=NULL){
			counter++;
			e=e->next;
		}
		
	}else{
		printf("Vertex does not exist.\n");
	}
	
	return counter;
}

int findDegree(char v){
	
	int counter=0;
	int flag=0;
	
	struct vertex *curr=Graph;
	
	while(curr!=NULL){
		if(curr->data==v){
			flag=1;
			break;
		}
		curr=curr->next;
	}
	
	
	if(flag==1){
		
		struct edge *temp=curr->edgelist;
		
		while(temp!=NULL){
			counter++;
			temp=temp->next;
		}
		
	}else{
		printf("Vertex Does not exist.\n");
	}
	
	return counter;
}

void isAdjacent(char v1,char v2){
	
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
	
	if(flag==2){
		struct edge *el=n1->edgelist;
		flag=0;
		
		while(el!=NULL){
			if(n2->data==el->v->data){
				printf("%c and %c both are adjacent.\n",n1->data,el->v->data);
				flag=1;
				break;
			}
			el=el->next;
		}
		
		if(flag==0){
			printf("No %c and %c are not adjacent.\n",v1,v2);
		}
		
	}else{
		printf("Vertices does not exist.\n");
	}
	
}


void findNeighbors(char v){
	
	
	struct vertex *curr=Graph;
	int flag=0;
	
	
	while(curr!=NULL){
		if(curr->data==v){
			flag=1;
			break;
		}
		curr=curr->next;
	}
	
	if(flag==1){
		
		
		struct edge *el=curr->edgelist;
		
		printf("%c neighbors are: ",curr->data);
		while(el!=NULL){
			printf("%c, ",el->v->data);
			el=el->next;
		}	
		
		if(graphType==1){
			
				
			struct vertex *start=Graph;
			while(start!=NULL){
				
				struct edge *el=start->edgelist;
				
				while(el!=NULL){
					
					if(el->v->data==v){
						printf("%c, ",start->data);
					}
					el=el->next;
				}
				start=start->next;
				
				
				
			}
			
		}	
			
	
	
	}
	
	printf("\n");
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


void printPath(){
	
	if(Path==NULL){
		return;
	}
	struct Stack *temp=Path;
	while(temp!=NULL){
		printf("%c->",temp->v);
		temp=temp->next;
	}
	
	printf("\n");
}

int path=0;
void findPath(struct vertex *src,struct vertex *des){
	
	src->visited=1;
	Push(src->data);
	struct edge *src_el=src->edgelist;
	
	if(graphType==1){
		
		if(src->data==des->data){
			printPath();
			src->visited=0;
			Pop();
			path++;
			return;
		}
		
	}
	
	while(src_el!=NULL){
		if(src->data==des->data){
			
			printPath();
			src->visited=0;
			Pop();
			path++;
			return;
		}
		
		if(src_el->v->visited==0){
			findPath(src_el->v,des);
		}
		
		src_el=src_el->next;
		
	}
	src->visited=0;
	Pop();	
	
}






void showEdges(struct vertex *p){
	
	struct edge *temp=p->edgelist;
	printf("%c-> ",p->data);
	while(temp!=NULL){
		printf("%c-> ",temp->v->data);
		temp=temp->next;
	}
}







int  UtilCyclic(struct vertex *src,struct vertex *parent){
	
	src->visited=1;
	struct edge *el=src->edgelist;
	while(el!=NULL){
		
		if(el->v->visited==0){
			parent=src;
			if(UtilCyclic(el->v,parent)==1){
				return 1;
			}
			
		}else if(el->v->data!=parent->data){
			return 1;
		}
		
		el=el->next;
	}
	
	return 0;
}

void isCyclic(){
	
	struct vertex *src=Graph;
	struct vertex *parent=NULL;
	int v=0;
	
	
	while(src!=NULL){
		if(src->visited==0){
	 
	 	v=UtilCyclic(src,parent);
			
		}
		
		src=src->next;	
	}
	
	if(v==1){

		printf("Yes cycle exist.");

	}else{
		printf("No cycle exist.");
	}
	
	src=Graph;
	
	while(src!=NULL){
		src->visited=0;
		src=src->next;
	}
}

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

void isGraphConnected(){
	
	struct vertex *src=Graph;
	
	GraphConnection(src);
	src=Graph;
	
	int flag=0;
	while(src!=NULL){
		
		if(src->visited==0){
			printf("Graph is not Connected.\n");
			flag=1;
			break;
		}	
		src=src->next;
	}
	
	src=Graph;
	while(src!=NULL){
		src->visited=0;
		src=src->next;
	}
	
	if(flag==0){
		printf("Graph is Connected.\n");
	}
	
}

int isConnected(struct vertex *src,struct vertex *des){

	
	
	src->visited=1;
	struct edge *src_el=src->edgelist;
	
	if(graphType==1){
		
		if(src->data==des->data){
			
			src->visited=0;
			return 1;
		}
		
	}
	
	while(src_el!=NULL){
	
		if(src->data==des->data){
			
			src->visited=0;
			return 1;
		}
		
		if(src_el->v->visited==0){
			if(isConnected(src_el->v,des)==1){
				return 1;
			}
		}
		
		src_el=src_el->next;
		
	}
	src->visited=0;
	
	return 0;	
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
			printf("2)Remove Vertex\n");
			printf("3)Add Edges\n");
			printf("4)Remove Edges\n");
			
			if(graphType==1){
				printf("5)In Degree\n");
				printf("6)Out Degree\n");
			
			}else{
				printf("5)Find Degree\n");
				printf("6)Is Adjacent\n");
				
			}
			
			printf("7)Find Neighbors\n");
			printf("8)Find Path\n");
			printf("9)Is Cyclic\n");
			printf("10)Is GraphConnected\n");
			printf("11)OutPut Graph\n");
			
			
			printf("Press 0 for exit.\n");
			int option;
			scanf("%d",&option);
			printf("\n");
			char e1,e2;
			
			switch (option) {
			case 1:
				
				printf("Enter the vertex:");
				scanf(" %c",&e1);
				
				addVertex(e1);
				
				
				break;
			case 2:
				printf("Enter the vertex:");
				scanf(" %c",&e1);
				removeVertex(e1);
				break;
			case 3:
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				addEdges(e1,e2);
				
				break;
				
			case 4:
				
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				removeEdges(e1,e2);
					
				break;

			case 5:
			
				if(graphType==1){
	
				printf("Enter the Vertex:");
				scanf(" %c",&e1);
				printf("InDegree of %c: %d",e1,InDegree(e1));
			
				}else{
				
				printf("Enter the Vertex:");
				scanf(" %c",&e1);
				printf("Degree of %c: %d",e1,findDegree(e1));
				
				}	
						
				break;
				
			case 6:
				if(graphType==1){
					
				printf("Enter the Vertex:");
				scanf(" %c",&e1);
				printf("OutDegree of %c: %d",e1,OutDegree(e1));
			
					
				}else{
					
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				isAdjacent(e1,e2);
				
				}
				break;
		
			case 7:
				printf("Enter the src:");
				scanf(" %c",&e1);
				findNeighbors(e1);
				break;
			
			case 8:
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				
				struct vertex *v1,*v2;
				v1=getVertex(e1);				
				v2=getVertex(e2);
				
				
				printf("\n");
				if(v1!=NULL && v2!=NULL){
				
					findPath(v1,v2);	
				
				}else{
					printf("Vertex does not exist.\n");
				}
				
//			
	
				if(path==0){
					printf("Path Does not exist.");
				}
			
				break;
			
			case 9:
				isCyclic();
				break;
			
			case 10:
				isGraphConnected();
				break;
			
			case 11:
				OutputGraph();
				break;
			
			case 12:
				printf("Enter the src:");
				scanf(" %c",&e1);
				printf("Enter the des:");
				scanf(" %c",&e2);
				
				struct vertex *p1,*p2;
				p1=getVertex(e1);				
				p2=getVertex(e2);
				
				if(p1!=NULL && p2!=NULL){
				
					if(isConnected(p1,p2)==1){
						printf("Vertices are Connected.\n");
					}else{
						printf("Vertices are not connected.\n");
					}
					
				}else{
				
					printf("Vertex does not exist.\n");
				
				}
				break;
				
			default:
				flag=0;
				break;
			}
			
		
		printf("\n");		
		}	
	
	
	}else{
		printf("Invalid Input");
	}
	return 0;
}
