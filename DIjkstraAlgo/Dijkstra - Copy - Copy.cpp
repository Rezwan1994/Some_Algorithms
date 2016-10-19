#include <bits/stdc++.h>
#include <process.h>
#include <conio.h>
using namespace std;

int main()
{
    int cost[10][10],path[10][10],i,j,n,p,minimum,v,index=1;

    int distence[10],row,coloum;

    //clrscr();
    cout<<"enter no. of node";
    cin>>n;
    cout<<"ebter cost of metrex:";
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        cin>>cost[i][j];
    }

    cout<<"chose the node you want to visit:";
    cin>>v;
    cout<<"enter no. of path from the node:";
    cin>>p;
    cout<<"enter the path matrix ";
    for(i=1;i<=p;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>path[i][j];
        }
    }
    for(i=1;i<=p;i++)
    {
        distence[i]=0;
        row=1;
        for(j=1;j<=n;j++)
        {
            if(row!=v)
            {
                coloum=path[i][j+1];
                distence[i]=distence[i]+cost[row][coloum];
            }
            row=coloum;
        }
    }

    minimum=distence[1];
    for(i=1;i<=p;i++)
    {
        if(distence[i]<=minimum)
        {
            minimum=distence[i];
            index=i;
        }
    }

    cout<<"the minimum destence is"<<minimum;
    cout<<"the shortest path is:";
    for(i=1;i<=n;i++)
    {
        if(path[index][i]!=0)
        {
            cout<<"-->"<<path[index][i];
        }
    }
    getch();
}
