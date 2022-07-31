#include <bits/stdc++.h>
#include <vector>

class Graph
{
public:
    Graph(int count) : verticesCount(count)
    {
        if (elements.size() < (count + 1))
            elements.resize(count + 1);
    };
    ~Graph(){};

    void insert(int vertex, int edge)
    {
        if (elements.size() < (vertex + 1))
            elements.resize(vertex + 1);

        elements[vertex].push_back(edge);
    }

    bool BFS(int source, int destination)
    {
        std::list<int> pending;
        std::vector<bool> visited;
        visited.resize(verticesCount, false);

        pending.push_back(source);

        while(not pending.empty())
        {
            int currentValue = pending.front();
            pending.pop_front();

            if (visited[currentValue])
                continue;

            visited[currentValue] = true;

            if (currentValue == destination)
                return true;

            for (int i = 0; i < elements[currentValue].size(); i++)
            {
                pending.push_back(elements[currentValue][i]);
            }
        }

        return false;
    }


private:
    std::vector<std::vector<int>> elements;
    int verticesCount = 0;

};

int main()
{
    Graph g(5);
    g.insert(0, 1);
    g.insert(0, 2);
    g.insert(1, 3);
    g.insert(1, 4);

    std::cout << "Element : 4 -> " << g.BFS(0, 4) << std::endl;
    std::cout << "Element : 7 -> " << g.BFS(0, 7) << std::endl;

    return 0;
}