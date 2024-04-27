#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

class Graph
{
    private:

        int V;
        vector<vector<int>> adj;

    public:

        Graph(int V)
        {
            this->V=V;
            adj.resize(V);
        }

        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void Bfs(int source)
        {
            vector<bool> vis(V,false);
            queue<int> q;
            vis[source]=true;
            q.push(source);

            while(!q.empty())
            {
                int v=q.front();
                q.pop();
                cout<<v<<" ";
                #pragma omp parallel for
                for(int i=0;i<adj[v].size();++i)
                {
                    if(!vis[adj[v][i]])
                    {
                        vis[adj[v][i]]=true;
                        q.push(adj[v][i]);
                    }
                }

            }


        }

        void Dfs(int source)
        {
            vector<bool> vis(V,false);
            DfsUtil(source,vis);
        }

        void DfsUtil(int source,vector<bool> &vis)
        {
            vis[source]=true;
            cout<<source<<" ";
            #pragma omp parallel for 
            for(int i=0;i<adj[source].size();++i)
            {
                int n=adj[source][i];
                if(!vis[n])
                {
                    DfsUtil(n,vis);

                }
            }

        }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.Bfs(0);
    cout<<endl;
    g.Dfs(0);

}