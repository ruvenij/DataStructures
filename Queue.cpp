#include <bits/stdc++.h>

const int MaxElementCount = 5;

class Queue
{
public:
    bool isFull()
    {
        if (tailIndex == (MaxElementCount - 1))
            return true;
        
        return false;
    }

    bool isEmpty()
    {
        if (frontIndex == -1)
            return true;

        return false;
    }
    
    void enqueue(int value)
    {
        if (isFull())
            return;

        if (frontIndex == -1)
            frontIndex = 0;
        
        tailIndex++;
        elements[tailIndex] = value;
    }

    void dequeue()
    {
        if (isEmpty())
            return;

        elements[frontIndex] = -1;
        frontIndex++;

        if (frontIndex == MaxElementCount)
            frontIndex = -1;
    }

    int peek()
    {
        if (isEmpty()) return -1;

        return elements[frontIndex];
    }

private:
    int elements[MaxElementCount] = {-1};
    int frontIndex = -1;
    int tailIndex = -1;
};

int main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    std::cout << q.peek() << std::endl;
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(2);
    std::cout << q.peek() << std::endl;
    q.dequeue();
    std::cout << q.peek() << std::endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    std::cout << q.peek() << std::endl;

    return 0;
}