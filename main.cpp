#include <iostream>
#include <limits.h>
#include "Graph.h"
#include "Test.h"
int main() {
    Tests();
    int size;
    cout << "Enter size" << endl;
    cin >> size;
    Graph<int> graph = Graph<int>(size);
    graph.NewGraphFromKeyboard(size);
    for(int i = 0; i < graph.GetSize(); i++)
    {
        for(int j = 0; j < graph.GetSize(); j++)
        {
            if(graph.Get(i,j) == INT_MAX)
            {
                cout << "X" << " ";
                continue;
            }
            cout << graph.Get(i,j)<< " ";
        }
        cout << endl;
    }
    cout << "Enter start dot" << endl;
    int start;
    cin >> start;
    start--;
    graph.FindShortest(start);

    return 0;
}
