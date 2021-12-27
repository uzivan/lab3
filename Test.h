#pragma once
#include "Graph.h"
bool TestConstructor()
{
    Sequence<Sequence<int>*>* data = new ArraySequence<Sequence<int>*>(30);
    for(int i = 0; i < data->GetLength(); i++)
    {
        data->Get(i) = new ArraySequence<int>(30);
    }
    for(int i = 0; i < data->GetLength(); i++)
    {
        for(int j = 0; j < data->GetLength(); j++)
        {
            data->Get(i)->Set(i+j*2,j);
        }
    }
    Graph<int> graph = Graph<int>(data);
    bool check = true;
    for(int i = 0 ; i < graph.GetSize(); i++)
    {
        for(int j = 0; j <graph.GetSize(); j++)
        {
            if(graph.Get(i, j) != data->Get(i)->Get(j))
                check = false;
        }
    }
    return check;
}
bool TestFindShortest()
{
    Sequence<Sequence<int>*>* data = new ArraySequence<Sequence<int>*>(30);
    for(int i = 0; i < data->GetLength(); i++)
    {
        data->Get(i) = new ArraySequence<int>(30);
    }
    for(int i = 0; i < data->GetLength(); i++)
    {
        for(int j = 0; j < data->GetLength(); j++)
        {
            if(i == j)
            {
                data->Get(i)->Set(0,j);
                continue;
            }
            data->Get(i)->Set(1,j);
        }
    }
    Graph<int> graph = Graph<int>(data);
    int st = 1;
    bool visited[graph.GetSize()];
    int D[graph.GetSize()];
    for(int i = 0; i < graph.GetSize(); i++)
    {
        D[i] = graph.Get(st, i);
        visited[i] = false;
    }
    D[st] = 0;
    int index = 0;
    int u = 0;
    for (int i = 0; i < graph.GetSize(); i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < graph.GetSize(); j++)
        {
            if (!visited[j] && D[j] < min)
            {
                min=D[j];
                index=j;
            }
        }
        u = index;
        visited[u] = true;
        for(int j = 0; j < graph.GetSize(); j++)
        {
            if (!visited[j] && graph.Get(u, j) != INT_MAX && D[u]!= INT_MAX && (D[u] + graph.Get(u, j) < D[j]))
            {
                D[j] = D[u] + graph.Get(u, j);
            }
        }
    }
    bool check = true;
    for(int i = 0; i < graph.GetSize(); i++)
    {
        if(D[i] != 1 && i != st)
            check = false;
    }
    return check;
}
void Tests()
{
    if(TestFindShortest() && TestConstructor())
        cout << "TESTS PASSED"<< endl;
    else cout << "TESTS LOSED" << endl;
}