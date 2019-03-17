#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_
/**
 * @Author Sachin Singh
 * Date : 17-Mar-2019
*/
class ArrayQueue
{
  private:
    const int capacity;
    int *queue;
    int rear;
    int front;
    int length;

  public:
    ArrayQueue(int capacity = 10);
    bool enQueue(int item);
    int deQueue();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
};

#endif