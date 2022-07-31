#include <bits/stdc++.h>

void display(std::vector<int>& heap)
{
    for (int currentElement : heap)
        std::cout << currentElement << " ";

    std::cout << std::endl;
}

void swap(std::vector<int>& heap, int firstElement, int secondElement)
{
    int temp = heap[firstElement];
    heap[firstElement] = heap[secondElement];
    heap[secondElement] = temp;
}

void heapify(std::vector<int>& heap, int index)
{
    int leftNodeIndex = (2 * index) + 1;
    int rightNodeIndex = (2 * index) + 2;

    int largest = heap[index];
    bool swapRequired = false;
    int largestIndex = index;

    if ((leftNodeIndex < heap.size()) and (largest < heap[leftNodeIndex]))
    {
        swapRequired = true;
        largestIndex = leftNodeIndex;
    }

    if ((rightNodeIndex < heap.size()) and (largest < heap[rightNodeIndex]))
    {
        swapRequired = true;
        largestIndex = rightNodeIndex;
    }

    if (swapRequired)
        swap(heap, index, largestIndex);
}

void insertNode(std::vector<int>& heap, int newValue)
{
    heap.push_back(newValue);
    
    if (heap.size() == 0)
        return;

    for (int i = ((heap.size() / 2) - 1); i >= 0; i--)
        heapify(heap, i);
}

void deleteNode(std::vector<int>& heap, int valueToBeDeleted)
{
    int i = -1;
    for (i = 0; i < heap.size(); i++)
    {
        if (heap[i] == valueToBeDeleted)
            break;
    }

    swap(heap, heap[i], heap[heap.size() - 1]); 

    heap.pop_back();

    for (int j = ((heap.size()) / 2 - 1); j >= 0; j--)
        heapify(heap, j);
}

int main()
{
    std::vector<int> heapTree;

    insertNode(heapTree, 3);
    insertNode(heapTree, 4);
    insertNode(heapTree, 9);
    insertNode(heapTree, 5);
    insertNode(heapTree, 2);

    display(heapTree);

    deleteNode(heapTree, 4);

    display(heapTree);

    return 0;
}