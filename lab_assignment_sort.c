#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct song
{
    char artist_name[20];
    char song_name[20];
    unsigned int year;
}*p;
void bubblesort( struct song *arr, int n)
{
    int i,modified;
    struct song aux;
    do {
	modified=0;
	for(i=1;i<n;i++)
	{
	    if(arr[i-1].artist_name> arr[i].artist_name)
	    {
		aux=arr[i-1];
		arr[i-1]=arr[i];
		arr[i]=aux;
		modified=1;
	    }
	}
    }while(modified);
}
int comp(const void *a, const void *b)
{
	struct song *x=(struct song*) a;
	struct song *y=(struct song*) b;
	return x->artist_name-y->artist_name;
}
int main(int argc, char *argv[])
{
    if(argc!=3)
    {
	printf("Invalid input");
	return -1;
    }
    FILE *f=fopen(argv[1],"r");
    if(!f)
    {
	printf("Error,couldn't open file");
	return -2;
    }
    int year_input=atoi(argv[2]);
    int line=0;
    char s[1025];
    while(fgets(s,1023,f)!=NULL)
    {
	line++;
    }
    p=(struct song*)malloc(line*sizeof(struct song));
    int i=0,state=0;
    rewind(f);
    char *separator;
    while(fgets(s,1023,f)!=NULL)
    {   if(i>line*sizeof(struct song))
	    {
		break;
	    }
	state=0;
	separator=strtok(s,",");
	while(separator!=NULL)
	{
		if(state==0)
		{
			if(s[0]=='"')
			{
			    strncpy(p[i].song_name,separator+1,20);
			    separator=strtok(NULL,"\"");
			    strncat(p[i].song_name,separator,20);
			}
			else
			{
				strncpy(p[i].song_name,separator,20);
			}
		}
		if(state==1)
		{
			strncpy(p[i].artist_name,separator,20);
		}
		if(state==2)
		{
		    p[i].year=atoi(separator);
		}
		separator=strtok(NULL,",");
		state++;
	}
	i++;
    }
    clock_t start,end;
    start=clock();
    bubblesort(p,1024);
    end=clock();
    printf("Execution time of bubblesort: %ld\n",end-start);
    start=clock();
    qsort(p,1024,sizeof(struct song),comp);
    end=clock();
    printf("Execution time of qsort: %ld\n", end-start);
    for(int j=0;j<line;j++)
    {
	if(p[j].year==year_input)
	{
		printf("%d. %s %s  %d\n",j+1,p[j].artist_name,p[j].song_name,p[j].year);
	}
    }
    free(p);
    fclose(f);
    return 0;
}
