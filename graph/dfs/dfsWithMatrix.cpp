#include <iostream>
#include <vector>

using namespace std;

typedef long long int lld;

class Graph
{
    vector<bool> *g;
    vector<bool> visited;
    lld totalVertices;

public:
    Graph(lld vertices)
    {
        g = new vector<bool>[vertices];

        for (lld i = 0; i < vertices; i++)
        {
            g[i].assign(vertices, {});
        }

        this->totalVertices = vertices;
        this->visited.assign(vertices, false);
    }

    void addEdge(lld a, lld b)
    {
        g[a][b] = true;
        g[b][a] = true;
    }

    void display()
    {
        for (lld i = 0; i < totalVertices; i++)
        {
            for (lld j = 0; j < totalVertices; j++)
            {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(lld vertex)
    {
        cout << vertex << endl;
        visited[vertex] = true;
        for (lld i = 0; i < totalVertices; i++)
        {
            if (i == vertex)
            {
                continue;
            }
            if (g[vertex][i] == 1)
            {
                if (visited[i])
                {
                    continue;
                }
                dfs(i);
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

    // g->display();
    // g->dfs(0);

    return 0;
}