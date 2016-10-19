#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

enum vertices{A,B,C,D,E,F,G};
typedef vector<int> Vector;
typedef list<int> List;


class Graph{

    int verticesCount;
    Vector vecList;
    vector<List> adjList;

    public:
    Graph(){cout<<"NO. OF VERTICES : ";cin>> verticesCount;adjList.resize(verticesCount);}

    void vertexList(){
        for(int vertex=A;vertex<verticesCount;++vertex){ vecList.push_back(vertex);}
    }

    void printVertices(){
        cout<<"Following Vertices are Avialabe now: ";
        for(Vector::iterator i=vecList.begin();i!=vecList.end();++i){ cout<<"|"<<(char)(*i+65);}
        cout<<endl;
    }


    void edgeList(){

        int destinationVertex=0;

        for(int index=0;index<verticesCount;++index){

            cout<<"Type Adjacent Vertices of Vertex "<<(char)(index+65)<<": ";
            do{
            cin>>destinationVertex;
            if(destinationVertex!=-1)adjList[index].push_back(destinationVertex);}while(destinationVertex!=-1);
            }
    }

    void addEdge(int u,int v){ adjList[u].push_back(v);}


    void printEdgeList(){
        for(vector<List> ::iterator it=adjList.begin();it!=adjList.end();++it){
        List li=*it;

        unsigned int i=it-adjList.begin();
        cout<<"Vertex "<<(char)(i+65)<<": ";
        for(List::iterator lit=li.begin();lit!=li.end();++lit) cout<<"-["<<(char)(*lit+65)<<"]";
        cout<<endl;
        }
    }

    void dfs(int startVertex){
        stack<int> S;
        int *visited=new int[verticesCount];
        for(int u=startVertex;u<verticesCount;u++) visited[u]=0;

        S.push(startVertex);
        while(!S.empty()){

            int u=S.top();S.pop();
            cout<<(char)(u+65)<<",";
            if(!visited[u]){
                visited[u]=true;
                list<int> li=adjList[u];
                for(List::iterator lit=li.begin();lit!=li.end();++lit){
                if(visited[*lit]==0) S.push(*lit);
                }
            }
        }
    }
};

/*
 DFS(G,v)   ( v is the vertex where the search starts )
         Stack S := {};   ( start with an empty stack )
         for each vertex u, set visited[u] := false;
         push S, v;
         while (S is not empty) do
            u := pop S;
            if (not visited[u]) then
               visited[u] := true;
               for each unvisited neighbour w of u
                  push S, w;
            end if
         end while
      END DFS()
*/

int main(){

Graph newGraph;
newGraph.vertexList();
newGraph.printVertices();
//newGraph.edgeList();
newGraph.addEdge(A,B);
newGraph.addEdge(A,C);
newGraph.addEdge(A,E);
newGraph.addEdge(B,D);
newGraph.addEdge(B,F);
newGraph.addEdge(C,G);
newGraph.addEdge(E,F);


newGraph.printEdgeList();cout<<endl;
newGraph.dfs(A);
}
