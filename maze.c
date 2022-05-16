#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char maze[1000][1000];
int n,m;
void length(FILE *f)
{
    char v[1001];
    int ok=0;
    while(fgets(v,1000,f))
    {
	n++;
	if(ok<2)
	{
	    ok++;
	    m=strlen(v);
	}
    }
    printf("The number of lines is %d:\n",n);
    printf("The number of columns is %d:",m);
}
void readfile(FILE *f)
{
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<m;j++)
	{
		fscanf(f,"%c",&maze[i][j]);
	}
    }
}
void print_sol()
{
    FILE *fout=fopen("test.txt","w");
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<m;j++)
	{
	    fprintf(fout,"%c",maze[i][j]);
	}
    }
}
int movexy(int i, int j)
{
	if(maze[i][j]=='E')
	{
	    print_sol();
	}
	if((i>0) && (i<n) && (j>0) && (j<m) && maze[i][j]!='#' && maze[i][j]!='.')
	{
		maze[i][j]='.';
		movexy(i-1,j);
		movexy(i,j-1);
		movexy(i+1,j);
		movexy(i,j+1);
		maze[i][j]=' ';
	}
    return 0;
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
    length(f);
    fseek(f,0,SEEK_SET);
    readfile(f);
    movexy(1,1);
    return 0;
}