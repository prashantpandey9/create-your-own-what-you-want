#include <iostream>
#include <list>
#include <stack>
using namespace std;
class Graph {
    int V;
    list<int>* adj;
    void sortUtil(int v,bool visited[],stack<int>& s);
  public:
    void topologicalSort();
    Graph(int V);
    void addEdge(int v,int w);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::sortUtil(int v, bool visited[], stack<int>& s)
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
      if(!visited[*i])
        sortUtil(*i,visited,s);
    s.push(v);
}
void Graph::topologicalSort()
{
    stack<int>s;
    bool * visited=new bool[V];
    for(int i=0;i<V;i++)
      visited[i]=false;
    for(int i=0;i<V;i++)
      if(visited[i]==false)
        sortUtil(i,visited,s);
    cout<<"\nTOPOLOGICAL SORT:";
    while(s.empty()==false)
    {
      cout<<s.top()<<" ";
      s.pop();
    }
}
int main()
{
    int v,e,j,k;
    cout<<"ENTER THE NO OF VERTICES:";
    cin>>v;
    Graph g(v);
    cout<<"ENTER THE NO OF EDGES:";
    cin>>e;
    cout<<"ENTER THE VERTICES OF THE EDGE CONNECTED:\n";
    for(int i=1;i<=e;i++)
    {
      cout<<"EDGE "<<i<<":";
      cin>>j>>k;
      g.addEdge(j,k);
    }
    g.topologicalSort();
    return 0;
}
