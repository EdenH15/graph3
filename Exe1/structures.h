//
// Created by edenh15 on 3/24/25.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

namespace graph {

    class Queue {
    private:
        static const int MAX_SIZE = 100;
        int data[MAX_SIZE]{};
        int front, rear;
    public:
        Queue();
        void enqueue(int value);
        int dequeue();
        bool isEmpty() const;
    };

    class Stack{
      private:
        static const int MAX_SIZE = 100;
        int data[MAX_SIZE]{};
        int top;
        public:
          Stack();
          void push(int value);
          int pop();
          bool isEmpty() const;
          };

    struct edge {
        int srcV;
        int dstV;
        int weight;
    };

    class minHeap {
        private:
        static const int MAX_SIZE = 100;
        edge data[MAX_SIZE]{};
        int size;
        public:
        minHeap();
        void insert(int src,int dst,int weight);
        edge extractMin();
        bool isEmpty() const;
    };

}

#endif // QUEUE_H
