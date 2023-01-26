#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int lld;

class Graph
{
    lld vertices, *distance;
    vector<pair<lld, lld>> *vec;

public:
    Graph(lld v)
    {
        this->vertices = v;
        vec = new vector<pair<lld, lld>>[v];

        distance = new lld[v];

        for (lld i = 0; i < v; i++)
        {
            this->distance[i] = -1;
        }
    }

    void addEdge(lld a, lld b, lld w)
    {
        // directed graph
        vec[a].push_back({b, w});
        vec[b].push_back({a, w});
    }

    void dijkstra(lld sourceNode)
    {
        priority_queue<pair<lld, lld>, vector<pair<lld, lld>>, greater<pair<lld, lld>>> pq;

        // {distance, node}
        pq.push({0, sourceNode});
        distance[sourceNode] = 0;

        while (!pq.empty())
        {
            for (auto val : vec[pq.top().second])
            {
                // vector got node it was connect with and the weight
                if ((distance[val.first] == -1) || distance[val.first] > (pq.top().first + val.second))
                {
                    distance[val.first] = pq.top().first + val.second;
                    pq.push({distance[val.first], val.first});
                }
            }
            pq.pop();
        }
    }

    void printAllDistance()
    {
        for (lld i = 0; i < this->vertices; i++)
        {
            cout << i << ":" << distance[i] << " ";
        }
        cout << endl;
    }

    void display()
    {
        for (lld i = 0; i < vertices; i++)
        {
            cout << i << " :";
            for (auto val : vec[i])
            {
                cout << " (" << val.first << "," << val.second << ")";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph *g = new Graph(5);

    g->addEdge(0, 1, 2);
    g->addEdge(0, 3, 1);
    g->addEdge(1, 2, 4);
    g->addEdge(1, 4, 5);
    g->addEdge(2, 3, 3);
    g->addEdge(2, 4, 1);

    g->display();
    cout << endl;

    g->dijkstra(0);

    g->printAllDistance();

    return 0;
}