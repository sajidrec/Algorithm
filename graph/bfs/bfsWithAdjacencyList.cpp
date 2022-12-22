#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int lld;

class Graph
{
    lld vertices;
    vector<bool> visited;
    vector<lld> *vec;
    queue<lld> q;

public:
    Graph(lld v)
    {
        this->vertices = v;
        visited.assign(v, false);
        vec = new vector<lld>[v];
    }

    void addEdge(lld a, lld b)
    {
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    void display()
    {
        for (lld i = 0; i < vertices; i++)
        {
            cout << i << " :";
            for (auto val : vec[i])
            {
                cout << " " << val;
            }
            cout << endl;
        }
    }

    void bfs(lld startingVertex)
    {
        q.push(startingVertex);
        visited[startingVertex] = true;

        while (!q.empty())
        {
            lld curVer = q.front();
            cout << curVer << " ";
            q.pop();

            for (auto i = vec[curVer].begin(); i != vec[curVer].end(); i++)
            {
                lld adjVer = *i;
                if (!visited[adjVer])
                {
                    visited[adjVer] = true;
                    q.push(adjVer);
                }
            }
        }
    }
};

int main()
{
    lld vertices, edges;

    cin >> vertices >> edges;

    Graph *g = new Graph(vertices);

    for (lld i = 0; i < edges; i++)
    {
        lld a, b;
        cin >> a >> b;
        g->addEdge(a, b);
    }

    g->bfs(1);
    cout << endl;

    return 0;
}