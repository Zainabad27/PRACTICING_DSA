#include <iostream>
#include <vector>
using namespace std;

// undirected graph
class graphs
{
    int numEdges = 6;

    vector<int> nodes[5+1];

public:
    void AddNode(int data, vector<int> connectedNodes)
    {

        for (int i = 0; i < numEdges; i++)
        {
            int j;
            int k;
            cin >> j >> k;
            nodes[j].push_back(k);
            nodes[k].push_back(j);
        }
    }
};

int main()
{
    int d1 = 1;

    vector<int> itsconnections = {2, 4, 6, 1, 8};
    graphs g1;
    g1.AddNode(d1, itsconnections);
    // g1.display();

    return 0;
}