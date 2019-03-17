#include "circulararrayqueue.h"
/**
 * @Author Sachin Singh
 * Date : 17-Mar-2019
*/
CircularArrayQueue::CircularArrayQueue(int c) : capacity((c >= 2) ? c : 10)
{
    queue = new int[capacity];
    rear = front = -1;
    length = 0;
}

bool CircularArrayQueue::isFull()
{
    if (front == 0 && rear == capacity - 1)
        return true;
    else if (front == rear + 1)
        return true;

    return false;
}

bool CircularArrayQueue::isEmpty()
{
    return front == -1;
}

bool CircularArrayQueue::enQueue(int item)
{
    if (!isFull())
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        length++;
        return true;
    }
    return false;
}

int CircularArrayQueue::deQueue() {
    if (!isEmpty()) {
        int item = queue[front];
        if (front >= rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        length--;
        return item;
    }
    return -1;
}

int CircularArrayQueue::peek() {
    if (!isEmpty())
        return queue[front];
    return -1;
}

int CircularArrayQueue::size() {
    return length;
}