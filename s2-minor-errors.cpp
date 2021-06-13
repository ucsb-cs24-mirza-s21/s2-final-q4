#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class smartQueue {
    private:
        queue<int> keys;
        vector<int> max_;
        vector<int> min_;

    public:
        void push(int key);
        void pop();
        int front();
        bool empty();
        int min();
        int max();
};

void smartQueue::push(int key) {
    keys.push(key);
    if (max_.size() == 0 || max_.back() <= key)
        max_.push_back(key);
    if (min_.size() == 0 || min_.back() >= key)
        min_.push_back(key);
}

void smartQueue::pop() {
    int popped = keys.front();
    keys.pop();
    if (popped == max_.back())
        max_.pop_back();
    if (popped == min_.back())
        min_.pop_back();
}

int smartQueue::front() {
    return keys.front();
}

bool smartQueue::empty() {
    if (keys.size() == 0)
        return true;
    return false;
}

int smartQueue::min() {
    return min_.back();
}

int smartQueue::max() {
    return max_.back();
}

int main() {
    smartQueue sQ;
    // push 3, 7, 2, 9, 8, 4
    // pop() 
    sQ.push(3);
    cout<<"Push 3:"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 3, "<<sQ.max()<<endl;
   
    sQ.push(7);
    cout<<"Push 7"<<endl;
     cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 7, "<<sQ.max()<<endl;
    sQ.push(2);
    cout<<"Push 2"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 7, "<<sQ.max()<<endl;
    sQ.push(9);
    cout<<"Push 9"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<"front: 3, "<<sQ.front()<<endl;;
    cout<<"  min: 2, "<<sQ.min()<<endl;
    cout<<"  max: 9, "<<sQ.max()<<endl;
    sQ.push(8);
    cout<<"Push 8"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.push(4);
    cout<<"Push 4"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;

    cout<<endl<<"Start popping"<<endl<<endl;
    // elements in smartQueue: 3, 7, 2, 9, 8, 4
    sQ.pop();
    cout<<"Popped 3"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 7, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 7"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 2, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 2"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 9, "<<sQ.front()<<endl;
    cout<<"   min: 4, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 9"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 8, "<<sQ.front()<<endl;
    cout<<"   min: 4, "<<sQ.min()<<endl;
    cout<<"   max: 8, "<<sQ.max()<<endl;
    cout<<"Print rest of the queue: ";
    sQ.push(3);
    cout<<"Pushed 3"<<endl;
    // queue has 8, 4, 3
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 8, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 8, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 8"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 4, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 4, "<<sQ.max()<<endl;
    cout<<"Print rest of the queue: ";
   // print_queue(sQ);
    return 0;
}
