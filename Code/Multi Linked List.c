#include<stdio.h>
#include<conio.h>


struct Student {
	int rollno;
	char name[25];
	struct Student *next;
};

struct course{
	
	int Course;
	int Class;
	struct Student *start;
	struct course *next;	
}*cstart;


void DeleteC(){
	
	int c,flag=0;
	printf("\nEnter the course you want to delete=");
	scanf("%d",&c);
	struct course *temp=cstart->next;
	struct course *prev=cstart;
	struct course *first=NULL;
	if(cstart->Course==c){
		flag=1;
		first=cstart;
	}else{
	
	while(temp!=NULL){
		if(temp->Course==c){
			flag=1;
			break;
		}
		prev=temp;
		temp=temp->next;
	
	}
		
	}
	
	if(flag==1){
		
		struct Student *del=NULL;
		if(first==cstart){
			del=cstart->start;
		}else{
			del=temp->start;
		}
		
		while(del!=NULL){
			struct Student *x=del;
			del=del->next;
			free(x);			
		}
		
		if(first==cstart){
			struct course *x=cstart;
			cstart=cstart->next;
			free(x);
			
		}else{
			
			struct course *x=temp;
			prev->next=temp->next;
			free(x);
			
			
		}
		
		
	}else{
		printf("\nCourse not exist.");
	}
}

void DeleteS(){
	
	int c,flag=0;
	printf("\nEnter the course in which student studying whom you want to delete=");
	scanf("%d",&c);
	struct course *temp=cstart;
	while(temp!=NULL){
		if(temp->Course=c){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	
	if(flag==1){
		int r,an=0;
		printf("Enter the roll no of student=");
		scanf("%d",&r);
		if(temp->start->rollno==r){
			struct Student *ptr=temp->start;
			temp->start=temp->start->next;
			an=1;
			free(ptr);
		}else{
	
			struct Student *curr=temp->start->next;
			struct Student *p=temp->start;
			while(curr!=NULL){
			if(curr->rollno==r){
				struct Student *ptr=curr;
				p->next=curr->next;
				free(ptr);
				an=1;
				break;
				
			}
			
			p=curr;
			curr=curr->next;
		}
			
		}
		if(an==0){
			printf("Student does not exist.");
		}
		
	}else{
		printf("\nCourse not exist.");
	}
	
	
	
}


void searchC(){
	int c,flag=0;
	printf("\nEnter the course which you want to search=");
	scanf("%d",&c);
	struct course *temp=cstart;
	while(temp!=NULL){
		if(temp->Course==c){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1){
		printf("\nFound");
		
		
	}else{
		printf("\nNot found");
	}
	
}

void searchS(){
	
	int c,flag=0;
	printf("\nEnter the course which you want to search=");
	scanf("%d",&c);
	struct course *temp=cstart;
	while(temp!=NULL){
		if(temp->Course=c){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	
	if(flag==1){
		
		int r ,an=0;
		printf("\nEnter Student Roll no=");
		scanf("%d",&r);
		struct Student *std=temp->start;
		
		while(std!=NULL){
			if(std->rollno==r){
				printf("\nFound:");
				an=1;
				break;
			}
			std=std->next;
		}
		
		if(an==0){
			printf("Student does not exist.");
		}
				
	}else{
		printf("COurse does not exist.");
	}
	
}

void insertC(){
	
	int c, i;
	printf("How many courses you want=");
	scanf("%d",&c);
	for(i=0;i<c;i++){

	printf("\nCourse %d:\n",i+1);
	
	struct	course *ptr=(struct course *)malloc(sizeof(struct course));
	printf("Course no=");
	scanf("%d",&ptr->Course);
	printf("Class=");
	scanf("%d",&ptr->Class);
	ptr->start=NULL;
	ptr->next=NULL;
	if(cstart==NULL){
		cstart=ptr;
	}else{
	
		struct course *curr;
		curr=cstart;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=ptr;

	}
		
		
	}
	
	
	
}




void print(){
	
	struct course *curr=cstart;
	while(curr!=NULL){
		printf("Course:%d\n",curr->Course);
		printf("Class:%d\n",curr->Class);
		curr=curr->next;
	}

	
}

void insertS(){
	int lim,i,c,flag=0;
	printf("In which course you want to enter Student List");
	scanf("%d",&c);
	struct course *temp=cstart;
	while(temp!=NULL){
		if(temp->Course==c){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	
	if(flag==1){
		
		printf("How many students you want in this course=");
		scanf("%d",&lim);
		
		
		int i;
		for(i=1;i<=lim;i++){
			
			struct Student *ptr=(struct Student*)malloc(sizeof(struct Student));
			printf("\nStudent %d",i);
			printf("Name: ");
			scanf("%s",&ptr->name);
			printf("Roll=");
			scanf("%d",&ptr->rollno);
			ptr->next=NULL;
							
			if(temp->start==NULL){
				temp->start=ptr;
			}else{
				
				struct Student *curr=temp->start;
				while(curr->next!=NULL){
					curr=curr->next;
				}
				curr->next=ptr;
			}
			
		}
		
		
	}else{
		printf("\nCourse dont exist.");
	}
	
}

void printstd(){
	
	int c,flag=0;
	printf("Which course information you want.");
	scanf("%d",&c);
	struct course *curr=cstart;
	
	while(curr!=NULL){
		if(curr->Course==c){
			flag=1;
			break;
		}
		curr=curr->next;
	}
	
	if(flag==1){
		
		if(curr->start!=NULL){
			int x=1;
			struct Student *temp=curr->start;
			while(temp!=NULL){
				
				printf("\nStudent %d",x);
				printf("\nName:%s",temp->name);
				printf("\nRoll no=%d\n",temp->rollno);
				temp=temp->next;
			}
			
		}else{
			printf("\nStudents are not enrolled in this course.");
		}
		
	}else{
		printf("\nCourse does not exist.");
	}
}

int main(int argc, char *argv[]) {
		
	printf("he");	
	return 0;

}

