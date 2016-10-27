
#include<stdio.h>
//using namespace std;
#include<conio.h>
#define INFINITY 999
struct node
{
    int cost;
    int value;
    int from;
}a[5];
void addEdge(int am[][5],int src,int dest,int cost)
{
     am[src][dest] = cost;
     return;
}
void bell(int am[][5])
{
    int i, j, k, c = 0, temp;
    a[0].cost = 0;
    a[0].from = 0;
    a[0].value = 0;
    for (i = 1; i < 5; i++)
    {
        a[i].from = 0;
        a[i].cost = INFINITY;
        a[i].value = 0;
    }
    while (c < 5)
    {
        int min = 999;
        for (i = 0; i < 5; i++)
        {
            if (min > a[i].cost && a[i].value == 0)
            {
                min = a[i].cost;
            }
            else
            {
                continue;
            }
        }
        for (i = 0; i < 5; i++)
        {
            if (min == a[i].cost && a[i].value == 0)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        temp = i;
        for (k = 0; k < 5; k++)
        {
            if (am[temp][k] + a[temp].cost < a[k].cost)
            {
                a[k].cost = am[temp][k] + a[temp].cost;
                a[k].from = temp;
            }
            else
            {
                continue;
            }
        }
        a[temp].value = 1;
        c++;
    }
    printf("Cost"<<"\t"<<"Source Node");
    for (j = 0; j < 5; j++)
    {
        printf(a[j].cost<<"\t"<<a[j].from);
    }
}
int main()
{
    int n, am[5][5], c = 0, i, j, cost;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            am[i][j] = INFINITY;
        }
    }
    while (c < 8)
    {
        cout<<"Enter the source, destination and cost of edge\n";
        //cin>>i>>j>>cost;
        scanf("%d %d %d",i,j,cost);
        addEdge(am, i, j, cost);
        c++;
    }
    bell(am);
    getch();
}
