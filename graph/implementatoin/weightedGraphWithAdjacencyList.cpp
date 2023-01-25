#include <iostream>
#include <vector>

using namespace std;

typedef long long int lld;

class Graph
{
    lld vertices;
    vector<pair<lld, lld>> *vec;

public:
    Graph(lld v)
    {
        this->vertices = v;
        vec = new vector<pair<lld, lld>>[v];
    }

    void addEdge(lld a, lld b, lld w)
    {
        // two edges and then weight
        vec[a].push_back({b, w});
        vec[b].push_back({a, w});
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
    // Graph *g = new Graph(5);
    // g->addEdge(0, 2, 3);
    // g->addEdge(1, 2, 2);
    // g->addEdge(2, 3, 5);
    // g->addEdge(3, 4, 4);

    // g->display();

    return 0;
}