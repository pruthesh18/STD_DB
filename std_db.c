#include"header.h"

//function defination
extern void stud_add(STU **);
/*extern*/ void stud_del(STU **);
/*extern*/ void stud_show(STU *);
/*extern*/ void stud_mod(STU *);
/*extern*/ void serarch_node(STU *,char);
/*extern*/ void sort_data(STU *ptr);
/*extern*/ void exit_with(STU *);
/*extern*/ void save_data(STU *);
/*extern*/ void delete_all(STU **);
/*extern*/ void reverse_links(STU **);

int count_node(STU *ptr)
{
	int count=0;
	while(ptr)
	{
		count++;
		ptr=ptr->next;
	}

	return count;
}

int r_no_count=1,ary_rn[100];
void main()
{
	char op;
	STU *headptr=0;	
	while(1)
	{
		printf("============STUDENT RECORD MENU===============\n\n");
		printf("	\033[345ma/A: add new record\033[0m\n");
		printf("	d/D: delete a record\n");
		printf("	s/S: show the list\n");
		printf("	m/M: modifiy a record\n");
		printf("	v/V: save\n");
		printf("	e/E: exit\n");
		printf("	t/T: sort the list\n");
		printf("	l/L: delete all records\n");
		printf("	r/R: reverse the list\033[0m\n");
		printf("\n=============================================\n");
		printf("Enter your choice:\n");
		scanf(" %c",&op);


		switch(op)
		{
			case 'a':stud_add(&headptr);break;
			case 'A':stud_add(&headptr);break;
			case 'd':stud_del(&headptr);break;
			case 'D':stud_del(&headptr);break;
			case 's':stud_show(headptr);break;
			case 'S':stud_show(headptr);break;
			case 'm':stud_mod(headptr);break;
			case 'M':stud_mod(headptr);break;
			case 'v':
			case 'V':save_data(headptr);break;
			case 't':sort_data(headptr);break;
			case 'T':sort_data(headptr);break;
			case 'l':delete_all(&headptr);break;
			case 'L':delete_all(&headptr);break;
			case 'r':reverse_links(&headptr);break;
			case 'R':reverse_links(&headptr);break;
			case 'e':exit_with(headptr);break;
			case 'E':exit_with(headptr);break;
			default:
				printf("\n\033[365mUnknown option\033[0m\n");
		}
	}

}


// a add records

// b. delete records
void stud_del(STU **ptr)
{
	char ch;
	printf("r/R: enter roll no to del\n");
	printf("n/N: enter name to del\n");
	scanf(" %c",&ch);
	if(ch=='r'|ch=='R')
	{
		if(*ptr==0)
		{
			printf("records not found");
			return;
		}
		int num;
		printf("enter the rollno to delete\n");
		scanf("%d",&num);
		STU *del=*ptr,*prev;
		while(del)
		{
			if(del->rollno==num)
			{
				if(del==*ptr)
					*ptr=del->next;
				else
					prev->next=del->next;
			//	ary_rn[i]=del->rolno;//have to mange ib value still pending
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}
		printf("roll no is not found\n");
	}
	else if(ch=='n'|ch=='N')
	{
		if(*ptr==0)
		{
			printf("records not found");
			return;
		}
		char name[100];;
		printf("enter the name\n");
		scanf(" %s",name);
		int f=0;
		STU *del=*ptr,*prev,*temp=*ptr;
		while(temp)
		{
			if(strcmp(temp->name,name)==0)
			{
				if(del==*ptr)
					*ptr=del->next;
				else
					prev->next=del->next;
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}
		printf("name is not found\n");
	}
}

// c. show the list

void stud_show(STU *ptr)
{
	if(ptr==0)
	{
		printf("No record found\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}

// d.modifiy the record
void stud_mod(STU *ptr)
{
	char ch;
	printf("\033[32mAccording to which record, data has to be modified\n");
	printf("r/R: to serarch roll no \n");
	printf("n/N: to serarch name\n");
	printf("p/P: to serarch percentage\n");
	scanf(" %c",&ch);
	system("clear");
	if(ch=='r'|ch=='R')
	{
		serarch_node(ptr,ch);
	}
	else if(ch=='n'|ch=='N')
	{
		serarch_node(ptr,ch);
	}
	else if(ch=='p'|ch=='P')
	{
		serarch_node(ptr,ch);
	}
}

// Search node  

void serarch_node(STU *ptr,char srch_type)
{
	char name[100];
	float percentage;
	STU *temp=ptr;
	if(temp==0)
	{
		printf("No record found \n");
		return;
	}
	L1:
	if(srch_type=='r'|srch_type=='R')
	{
		int num,f=0;
		printf("enter the rollno to search\n");
		scanf("%d",&num);
		    printf("\n\033[37m===============================================================\n");
		while(temp)
		{
			if(temp->rollno==num)
			{
				printf("\033[37mrollno: %d\tname: %s\tpercentage: %f\033[0m\n\033[35m----------------------------------------------------------\033[0m\n\n",temp->rollno,temp->name,temp->marks);
				f=1;
				printf("rollno: %d\n",temp->rollno);
				printf("name: ");
				scanf("%s",name);
				printf("Percentage: ");
				strcpy(temp->name,name);
				scanf("%f",&percentage);
				temp->marks=percentage;
			}
			temp=temp->next;
		}
		    printf("\n\033[37m===============================================================\n");
		if(f==0)
		{
			printf("\033[35mstudent data with %d rollno not found\033[0m\n",num);
		}
	}
	else if(srch_type=='n'|srch_type=='N')
	{
		char name[100],f=0;
		printf("enter the name to search\n");
		scanf("%s",name);
		    printf("\n\033[37m===============================================================\n");
		while(temp)
		{
			if(strcmp(temp->name,name)==0)
			{
				printf("%d %s %.2f\n",temp->rollno,temp->name,temp->marks);
				f=1;
			}
			temp=temp->next;
		}
		    printf("\n\033[37m===============================================================\n");
		if(f==0)
		{
			printf("record not found");	
		}
		else if(f==1)
		{
		temp=ptr;
		srch_type='r';
		goto L1;
		}
	}
	else if(srch_type=='p'|srch_type=='P')
	{
		float mark,f=0;
		printf("enter the rollno to search\n");
		scanf("%f",&mark);
		    printf("\n\033[37m===============================================================\n");
		while(temp)
		{
			if(temp->marks==mark)
			{
				printf("%d %s %.2f\n",temp->rollno,temp->name,temp->marks);
				f=1;
			}
			temp=temp->next;
		}
		    printf("\n\033[37m===============================================================\n");
		if(f==0)
		{
			printf("record not found");	
		}
		else if(f==1)
		{
		temp=ptr;
		srch_type='r';
		goto L1;
		}
	}


}

// sort the data

void sort_data(STU *ptr)
{
	char ch;
    printf("n/N: sort with nmae  \n");
    printf("p/P: to serarch percentage \n");
    scanf(" %c",&ch);
	if(ch=='n'|ch=='N')
    {
		 if(ptr==0)
		 {
			 printf("no record found");
			 return;
		 }
		 STU *p1=ptr,*p2,t;
		 int i,j;
		 while(p1)
		 {
		     p2=p1->next;
		     while(p2)
		     {
		         if(strcmp(p1->name,p2->name)>0)
		    	{
		    	    printf("%f %f",p1->marks,p2->marks);
    				t.rollno=p1->rollno;
    				strcpy(t.name,p1->name);
    				t.marks=p1->marks;
    
    				p1->rollno=p2->rollno;
    				strcpy(p1->name,p2->name);
    				p1->marks=p2->marks;
    					
    				p2->rollno=t.rollno;
    				strcpy(p2->name,t.name);
    				p2->marks=t.marks;
		    	}
			    p2=p2->next;
		     }
		     p1=p1->next;
		 }
	}
	else if(ch=='p'|ch=='P')
	{
		 if(ptr==0)
		 {
			 printf("no record found");
			 return;
		 }
		 STU *p1=ptr,*p2,t;
		 int i,j;
		 while(p1)
		 {
		     p2=p1->next;
		     while(p2)
		     {
		         if(p1->marks>p2->marks)
		    	{
		    	    printf("%f %f",p1->marks,p2->marks);
    				t.rollno=p1->rollno;
    				strcpy(t.name,p1->name);
    				t.marks=p1->marks;
    
    				p1->rollno=p2->rollno;
    				strcpy(p1->name,p2->name);
    				p1->marks=p2->marks;
    					
    				p2->rollno=t.rollno;
    				strcpy(p2->name,t.name);
    				p2->marks=t.marks;
		    	}
			    p2=p2->next;
		     }
		     p1=p1->next;
		 }
	}
}

// exit with or without save

void exit_with(STU *ptr){
    char ch;
    printf("s/S: save and exit \n");
    printf("e/E: exit without saving \n");
    scanf(" %c",&ch);
    if(ch=='s'|ch=='S')
    {
        save_data(ptr);
    }
    else if(ch=='e'|ch=='E')
    {
        exit(0);
    }
    
}
// save the data

void save_data(STU *ptr)
{
    if(ptr==0)
    {
        printf("no records found\n");
		return;
    }
    FILE *fp;
    fp=fopen("student.txt","w");
    while(ptr)
    {
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
    printf("saved the data in the file\n");
	fclose(fp);
	exit(0);
}

// delete all node

void delete_all(STU ** ptr)
{
	if(ptr==0)
	{
		printf("No records found");
		return;
	}
	STU *del=*ptr;
	int c=0;
	while(del)
	{
		*ptr=del->next;
		sleep(1);
		printf("node pos %d delete succesfully\n",++c);
		free(del);
		del=*ptr;
	}
	printf("All node delted\n");
}

// reverse the list 

void reverse_links(STU **ptr)
{
	if(*ptr==0)
	{
	printf("no records found");
	return;
	}
	int c=count_node(*ptr);
	STU **arr,*t=*ptr;
	if(c>=2)
	{
		arr=malloc(sizeof(STU*)*c);
		int i=0;
		while(t)
		{
		arr[i++]=t;
		t=t->next;
		}
		for(i=0;i<c;i++)
			arr[i]->next=arr[i-1];

		arr[0]->next=0;
		*ptr=arr[c-1];
		
	}
}










