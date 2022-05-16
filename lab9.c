#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie
{
    int year,budget;
    char title[101];
}film;
typedef struct node
{
    int info;
    film f;
    struct node *next;
}nod;
nod *head,*tail;

void print_list(nod *x)
{
	x=head;
	while(x)
	{
	    printf("%d ",x->info);
	    x=x->next;
	}
}
void add_to_front(nod *x)
{
    x->next=head;
    if(NULL==head)
    {
	tail=x;
    }
    head=x;
}
void add_to_back(nod *x)
{
    if(NULL==tail)
    {
	head=x;
    }
    else
    {
	tail->next=x;
    }
    tail=x;
    x->next=NULL;
}
//This function is for reading the file and printing the content
void readfile(FILE *f)
{
    char v[1024];
    int nr_line=0;
    while(fgets(v,1024,f))
    {
	nr_line++;
    }
    film *a=(film *)malloc(sizeof(film)*nr_line);
    fseek(f,0,SEEK_SET);
    int i=0;
    while(fgets(v,1024,f))
    {
	if(i>nr_line*sizeof(film))
	{
	    break;
	}
	int state=0;
	char *separator=strtok(v,",");
	while(separator!=NULL)
	{
	    if(state==0)
	    {
		a[i].year=atoi(separator);
	    }
	    if(state==2)
	    {
		if(v[0]=='"')
		{
			strncpy(a[i].title,separator+1,100);
			separator=strtok(NULL,"\"");
			strncat(a[i].title,separator,100);
		}
		else
		{
		    strncpy(a[i].title,separator,100);
		}
	    }
	    if(state==6)
	    {
		a[i].budget=atoi(separator);
		break;
	    }
	separator=strtok(NULL,",");
	state++;
	}
	i++;
    }
    nod *p;
//Now we add the elements to the list
    for(int j=1;j<nr_line;j++)
    {
	p=(nod*)malloc(nr_line*sizeof(nod));
	p->f.year=a[j].year;
	p->f.budget=a[j].budget;
	strncpy(p->f.title,a[j].title,100);
	if((!head) || (p->f.year<=head->f.year))
	{
	    add_to_front(p);
	}
	else if(p->f.year>=tail->f.year)
	{
	    add_to_back(p);
	}
	else
	{
	    nod *before,*after;
	    before=NULL;
	    after=head;
	    int exception=0;
	    while(after->f.year<=p->f.year)
	    {
		if(after->f.year==p->f.year)
		{
		    while(strcmp(after->f.title,p->f.title)<0 && (after->f.year==p->f.year))
		    {
			before=after;
			after=after->next;
			if(!after)
			{
				add_to_back(p);
				exception=1;
				break;
			}
		    }
			if(!before)
			{
				add_to_front(p);
				exception=1;
			}
			break;
		}
		else
		{
			before=after;
			after=after->next;
		}
	    }
	    if(!exception)
	    {
		before->next=p;
		p->next=after;
	    }
	}
    }
    for(p=head;p;p=p->next)
    {
	printf("%d %s %d\n",p->f.year,p->f.title,p->f.budget);
    }
free(a);
free(p);
fclose(f);
}
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
	printf("Invalid input\n");
    }
    FILE *f=fopen(argv[1],"r");
    if(!f)
    {
	printf("Error opening file\n");
    }
    readfile(f);
    return 0;
}