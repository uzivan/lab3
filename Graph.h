#pragma once
#include "ArraySequence.h"
//#include <limits.h>
template<class T>
class Graph
{
private:
    Sequence<Sequence<T>*>* data;
    int size;
public:
    Graph()
    {
        this->data = new ArraySequence<Sequence<T>*>();
        this->size = 0;
    }
    Graph(int size)
    {
        this->size = size;
        this->data = new ArraySequence<Sequence<T>*>(size);
        for(int i = 0; i < size; i++)
        {
            this->data->Get(i) = new ArraySequence<T>(size);
        }
    }
    Graph(Sequence<Sequence<T>*>* data)
    {
        this->data = data;
        this->size = data->GetLength();
    }
    int GetSize()
    {
        return this->size;
    }
    int Get(int i, int j)
    {
        return this->data->Get(i)->Get(j);
    }
    void NewGraphFromKeyboard(int size)
    {
        Sequence<Sequence<T>*>* data = new ArraySequence<Sequence<T>*>(size);
        for(int i = 0; i < size; i++)
            data->Get(i) = new ArraySequence<T>(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = i; j < size; j++)
            {
                if(i == j)
                {
                    data->Get(i)->Set(INT_MAX,j);
                    continue;
                }
                T item;
                cout << "from dot " << i + 1 << " to dot " << j + 1 << endl;
                cin >> item;
                if(item == 0)
                {
                    data->Get(i)->Set(INT_MAX,j);
                    data->Get(j)->Set(INT_MAX,i);
                    continue;
                }
                data->Get(i)->Set(item,j);
                data->Get(j)->Set(item,i);
            }
        }
        this->data = data;
        this->size = size;
    }
    void FindShortest(int st)
    {
        bool visited[this->size];
        int d[this->size];
        for(int i = 0; i<this->size; i++)
        {
            d[i] = this->Get(st, i);
            visited[i] = false;
        }
        d[st] = 0;
        int index = 0;
        int u = 0;
        for (int i = 0; i < this->size; i++)
        {
            int min = INT_MAX;
            for (int j = 0; j < this->size; j++)
            {
                if (!visited[j] && d[j] < min)
                {
                    min = d[j];
                    index = j;
                }
            }
            u = index;
            visited[u] = true;
            for(int j = 0; j < this->size; j++)
            {
                if (!visited[j] && this->Get(u, j) != INT_MAX && (d[u] + this->Get(u, j) < d[j]))
                {
                    d[j] = d[u] + this->Get(u, j);
                }
            }
        }
        for (int i = 0; i < this->size; i++)
        {
            if (d[i] != INT_MAX)
                cout << st + 1 << " -> " << i+1 << " = " << d[i] << endl;
            else
                cout << st+1 << " -> " << i+1 << " = " << "No way" << endl;
        }
    }
};