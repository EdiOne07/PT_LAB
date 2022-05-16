#include <stdio.h>
///1.Oradea
///2.Cluj
///3.Timisoara
///4.Bucuresti
///5.Iasi
///6.Oradea
///I am going to explain the code below

int v[5];///Here is the frequeny array
void parcurgere(int a[5][5],int city)
{
    int s=0;/// This variable is to compute the length
    int c=0;/// This variable is to compute the number of cities we have passed through
    int begin=city;/// This variable is to mark the city we start from
    int next=city;/// This variable is to mark the next city we go to
    while(c<5)
    {
	int vmin=9999999;
	v[city]=1; /// We mark the city that we started from
	if(c==4)
	{
	    v[begin]=0;   ///We must return to the first city, so we set the value to 0 for the city that we started from
	}
	for(int i=0;i<5;i++)
	{
	    if(v[i]!=1)
	    {
		if(vmin>a[next][i])
		{
		    vmin=a[next][i];
		    city=i;
		}
	    }
	}
	s=s+vmin; /// We compute the length
	next=city; 
	c++;
    }
    printf("The minimum length is:%d",s);
}
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
	printf("Invalid input");
    }
    FILE *f=fopen(argv[1],"r");
    if(!f)
    {
	printf("Couldn't open file");
    }
    int a[5][5];
    for(int i=0;i<5;i++)
    {
	for(int j=0;j<5;j++)
	{
		fscanf(f,"%d",&a[i][j]);
		printf("%d ",a[i][j]);
	}
	printf("\n");
    }
    parcurgere(a,1);
    return 0;
}