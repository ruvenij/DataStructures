#include <bits/stdc++.h>

const int MaxSize = 5;

class CircularQueue
{
public:
    bool isFull()
    {
        if (front == 0 and rear == (MaxSize - 1))
            return true;

        if (front == (rear + 1))
            return true;

        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;

        return false;
    }

    void enqueue(int value)
    {
        if (isFull())
            return;

        if (isEmpty()) 
            front++;

        rear++;
        rear %= MaxSize;
        elements[rear] = value;   
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;

        int removedValue = elements[front];
        elements[front] = -1;
        front++;
        front %= MaxSize;

        if (front == rear)
            front = -1;

        return removedValue;
    }

    void display()
    {
        std::cout << "Front : " << front << ", Back : " << rear << std::endl;

        for(int i = 0; i < MaxSize; i++)
        {
            std::cout << elements[i] << " ";
        }

        std::cout << std::endl;
    }

private:
    int elements[MaxSize] = {-1};
    int front = -1;
    int rear = -1;
};

int main()
{
    CircularQueue q;

    // Fails because front = -1
    q.dequeue();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enqueue(6);

    q.display();

    int elem = q.dequeue();

    if (elem != -1)
        std::cout << "Deleted Element is " << elem << std::endl;

    q.display();

    q.enqueue(7);

    q.display();

    // Fails to enqueue because front == rear + 1
    q.enqueue(8);
    return 0;
}