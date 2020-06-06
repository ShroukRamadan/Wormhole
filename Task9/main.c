#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int Graph[MAX][MAX],int n,int startnode , int endnode);

int main()
{
	int graph[MAX][MAX],i,j,n,s,d;
	printf("Enter no. of plants:");
	scanf("%d",&n);
	printf("\nEnter the cost between plants:\n");

	for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
			if(graph[i][j]==0)
				graph[i][j]=INFINITY;
    }
	printf("\nEnter the source:");
	scanf("%d",&s);
	printf("\nEnter the destination:");
	scanf("%d",&d);
	dijkstra(graph,n,s,d);

	return 0;
}

void dijkstra(int Graph[MAX][MAX],int n,int startnode, int endnode)
{

	int distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	for(i=0;i<n;i++)
	{
		distance[i]=Graph[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)
			if(distance[i] < mindistance && visited[i]==0)
			{
				mindistance=distance[i];
				nextnode=i;

			}

			visited[nextnode]=1;

			for(i=0;i<n;i++)
				if(visited[i]==0)
					if(mindistance+Graph[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+Graph[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	for(i=0;i<n;i++)
    {
       if(i==endnode)
		{
			printf("\nthe the total cost plant[%d] to plant[%d] = %d",startnode,endnode,distance[i]);
			printf("\n The shortest Path = %d ",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	    }
    }

	    printf("\n");
}
