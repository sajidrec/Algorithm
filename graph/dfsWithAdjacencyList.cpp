#include <iostream>
#include <vector>

using namespace std;

typedef long long int lld;

class Graph
{
    lld vertices;
    vector<bool> visited;
    vector<lld> *vec;

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

    void dfs(lld vertex)
    {
        cout << vertex << " ";
        visited[vertex] = true;
        for (auto val : vec[vertex])
        {
            if (!visited[val])
            {
                dfs(val);
            }
        }
    }
};

int main()
{
    // lld vertices, edges;

    // cin >> vertices >> edges;

    // Graph *g = new Graph(vertices);

    // for (lld i = 0; i < edges; i++)
    // {
    //     lld a, b;
    //     cin >> a >> b;
    //     g->addEdge(a, b);
    // }

    // g->display();
    // g->dfs(0); // put source vertex

    return 0;
}