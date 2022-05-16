#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct song
{
    char artist_name[20];
    char song_name[20];
    unsigned int year;
}*p;
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
    //printf("---%d---",line);
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
    for(int j=0;j<line;j++)
    {
	if(p[j].year==year_input)
	{
		printf("%d. %s %s %d\n",j+1,p[j].song_name,p[j].artist_name,p[j].year);
	}
    }
    free(p);
    fclose(f);
    return 0;
}
