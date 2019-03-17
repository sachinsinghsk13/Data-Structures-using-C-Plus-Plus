#include "arrayqueue.h"
/**
 * @Author Sachin Singh
 * Date : 17-Mar-2019
*/
ArrayQueue::ArrayQueue(int c) : capacity((c >= 2) ? c : 10)
{
    queue = new int[capacity];
    rear = front = -1;
    length = 0;
}

bool ArrayQueue::isFull()
{
    return rear == capacity - 1;
}

bool ArrayQueue::isEmpty()
{
    return front == -1;
}

bool ArrayQueue::enQueue(int item)
{
    if (!isFull())
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        length++;
        return true;
    }
    return false;
}

int ArrayQueue::deQueue() {
    if (!isEmpty()) {
        int item = queue[front];
        if (front >= rear)
            front = rear = -1;
        else
            front++;
        length--;
        return item;
    }
    return -1;
}

int ArrayQueue::peek() {
    if (!isEmpty())
        return queue[front];
    return -1;
}

int ArrayQueue::size() {
    return length;
}