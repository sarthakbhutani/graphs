// surrounded regions dfs
// bfs
// gcc

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v)
    {
        this->v = v;
    }

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

const int n = 9;
// vector<vector<Edge*>> graph(n,vector<Edge*>());
vector<Edge *> graph[n];

void addEdge(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void display()
{
    for (int i = 0; i < 9; i++)
    {
        for (Edge *ele : graph[i])
        {
            cout << i << "->" << ele->v << " : " << ele->w << endl;
        }
    }
}

int searchVertex(int u, int v)
{
    int idx = -1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i]->v == v)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

void removeEdge(int u, int v)
{
    // graph.erase(graph[u][searchVertex(u,v)]);
    // graph.erase(graph[u][searchVertex(v,u)]);
    int vIdx = searchVertex(u, v);
    int uIdx = searchVertex(v, u);

    if (vIdx != -1)
    {
        graph[u].erase(graph[u].begin() + uIdx);
        graph[v].erase(graph[v].begin() + vIdx);
    }
}

void removeVertex(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        removeEdge(u, graph[u][i]->v);
    }
}

bool hasPath(int src, int dest, vector<bool> &vis, string ans)
{

    if (src == dest)
    {
        cout << ans << endl;
        return true;
    }
    bool res = false;
    vis[src] = true;
    for (int i = 0; i < graph[src].size(); i++)
    {
        int v = graph[src][i]->v;
        if (!vis[v])
            res = res || hasPath(v, dest, vis, ans + to_string(v));
    }
    return res;
}

//dfs allPaths
int allPath(int src, int dest, vector<bool> &vis, string ans)
{
    //bc
    if (src == dest)
    {
        cout << ans + to_string(dest) << endl;
        cout << "found" << endl;
        return 1;
    }
    int count = 0;
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!vis[v])
            count += allPath(v, dest, vis, ans + to_string(src) + " ");
    }
    vis[src] = false;
    return count;
}

void HamintonianPath(int osrc, int src, vector<bool> &vis, int count, string ans)
{
    if (count == n - 1)
    {
        if (searchVertex(osrc, src))
        {
            cout << "Hamintonian Cycle" << endl;
        }
        else
        {
            cout << "Hamintonian Path" << endl;
        }
        cout << ans + to_string(src) << endl;
        return;
    }
    vis[src] = true;
    for (Edge *ele : graph[src])
    {
        int v = ele->v;
        if (!vis[v])
        {
            HamintonianPath(osrc, v, vis, count + 1, ans + to_string(src) + " ");
        }
    }
    vis[src] = false;
}

//bfs
void bfs(int src, vector<bool> &vis)
{
    queue<int> que;
    que.push(src);
    int level = 0;

    while (que.size() != 0)
    {
        int size = que.size();
        if (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();
            if (vis[rvtx])
            {
                cout << "cycle found wrt" << to_string(src) << " at vertex " << to_string(rvtx) << endl;
                continue;
            }

            vis[rvtx] = true;
            for (Edge *ele : graph[rvtx])
            {
                if (!vis[ele->v])
                    que.push(ele->v);
            }
        }
        level++;
    }
}

int gcc()
{
    vector<bool> vis(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i, vis);
            count++;
        }
    }
    return count;
}

void solve()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

    addEdge(7, 8, 3);
    addEdge(2, 7, 3);
    addEdge(2, 8, 3);

    display();
    // cout << "hasPath?" << endl;
    vector<bool> vis(n, false);
    // bool hasPathVar = false;
    // hasPathVar = hasPath(0, 6, vis, "");
    // cout << hasPathVar<<endl;
    // cout << allPath(0, 6, vis, "");
    // bfs(0,vis);
    cout << gcc();
}

int main()
{
    solve();
    return 0;
}
