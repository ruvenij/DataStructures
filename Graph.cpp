#include <bits/stdc++.h>

class Graph
{
public:
    Graph(int count)
    {
        vertexCount = count;
        elements.resize(count);
    }
    
    void insertElement(int sourceNode, int destinationNode)
    {
        if (vertexCount < (sourceNode + 1))
        {
            vertexCount = sourceNode + 1;
            elements.resize(vertexCount);
        }

        elements[sourceNode].push_back(destinationNode);
    }

    bool path(int source, int destination)
    {
        std::cout << source << " -> ";
        for (int i = 0; i < elements[source].size(); i++)
        {
            if (elements[source][i] == destination)
            {
                std::cout << elements[source][i] << " -> ";
                return true;
            }

            if (path(elements[source][i], destination))
            {
                return true;
            }
        }

        return false;
    }

    void findPath(int source, int destination)
    {
        if ((vertexCount < (source + 1)) or (vertexCount < (destination + 1)))
            return;

        if (source == destination)
            return;

        path(source, destination);
    }

    bool DFS(int root, int destination)
    {
        std::cout << root << " -> ";

        for (int i = 0; i < elements[root].size(); i++)
        {
            if (visited[elements[root][i]])
                continue;

            if (elements[root][i] == destination)
            {
                std::cout << elements[root][i] << " -> ";
                return true;
            }

            visited[elements[root][i]] = true;

            if (DFS(elements[root][i], destination))
            {
                return true;
            }
        }

        return false;
    }

    bool BFS(int root, int destination)
    {
        reset();
        pendingNodes.push_back(root);

        while(pendingNodes.size() != 0)
        {
            int value = pendingNodes.front();
            pendingNodes.pop_front();

            if (visited[value])
            {
                continue;
            }

            visited[value] = true;

            std::cout << value << " -> ";

            if (value == destination)
            {
                return true;
            }

            for (int i = 0; i < elements[value].size(); i++)
            {
                pendingNodes.push_back(elements[value][i]);
            }
        }

        return false;
    }

    void reset()
    {
        visited.clear();
        pendingNodes.clear();
        visited.resize(vertexCount);
    }

private:
    std::vector<std::vector<int>> elements;
    int vertexCount = 0;
    std::vector<bool> visited;
    std::list<int> pendingNodes;

};

int main()
{
    Graph* graph = new Graph(6);
    graph->insertElement(0, 1);
    graph->insertElement(0, 2);
    graph->insertElement(0, 3);
    graph->insertElement(1, 2);
    graph->insertElement(2, 5);
    graph->insertElement(3, 4);
    graph->insertElement(4, 5);

    std::cout << "Element : 5 -> " << std::endl;
    graph->BFS(0, 5);
    std::cout << std::endl;

    std::cout << "Element : 7 -> " << std::endl;
    graph->BFS(0, 7);
    std::cout << std::endl;

    graph->reset();

    std::cout << "Element : 5 -> " << std::endl;
    graph->DFS(0, 5);
    std::cout << std::endl;

    graph->reset();

    std::cout << "Element : 7 -> " << std::endl;
    graph->DFS(0, 7);
    std::cout << std::endl;

    graph->reset();
    std::cout << "Element : 1 -> 4 " << std::endl;
    graph->findPath(1, 5);
    std::cout << std::endl;

    return 0;
}

/*
Graph Operations
-------------------
Check if the element is present in the graph
Graph Traversal
Add elements(vertex, edges) to graph
Finding the path from one vertex to another
*/