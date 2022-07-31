#include <bits/stdc++.h>

const int MaxElementsCount = 10;

class Stack
{
public:
    void push(int value)
    {
        if (size == MaxElementsCount) return;

        topElementIndex++;
        elements[topElementIndex] = value;
        size++;
    }

    int top()
    {
        return elements[topElementIndex];
    }

    void pop()
    {
        if (size == 0) return;

        elements[topElementIndex] = 0;
        topElementIndex--;
        size--;
    }

private:
    int elements[MaxElementsCount] = {0};
    int topElementIndex = 0;
    int size = 0;

};

int main()
{
    Stack st;
    st.push(3);
    st.push(2);
    std::cout << st.top() << std::endl;
    st.push(8);
    st.push(5);
    st.push(9);
    std::cout << st.top() << std::endl;
    st.pop();
    std::cout << st.top() << std::endl;
    st.pop();
    std::cout << st.top() << std::endl;

    return 0;
}