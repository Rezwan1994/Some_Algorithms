#include<bits/stdc++.h>
using namespace std;
void bellmanford(int G[10][10],int s,int n);
void Relax(int u,int v,int G[10][10]);
#define infinity 999
int dist[10],pred[10];
int main()
{
    int G[10][10],i,j,n,s;
    cout<<"How many node?";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>G[i][j];
        }
    }
    cout<<"enter source node";
    cin>>s;

    bellmanford(G,s,n);

    /*for(i=1;i<=n;i++)
    {
        cout<<"-->"<<pred[i];
    }*/

    return 0;
}

void bellmanford(int G[10][10],int s,int n)
{
    int i,pred[10],dist[10],u,v;
    for(i=1;i<=n;i++)
    {
        dist[i]= infinity;
        pred[i]= 0;

    }
    dist[s]=0;
    for(i=1;i<=n-1;i++)
    {
        for(int u=1;u<=n;u++)
        {
            for(v=2;v<=n;v++)
            {
                Relax(u,v,G);
            }
        }
    }

    /* for(int u=1;u<=n;u++)
        {
            for(v=1;v<=n;v++)
            {
                if (dist[v] > dist[u] + G[u][v])
                return false;

            }

        }

          return true;*/

}

void Relax(int u,int v,int G[10][10])
{

    if (dist[v] > dist[u] + G[u][v])
    {
         dist[v] = dist[u] + G[u][v];
         pred[v] = u;

    }


}
