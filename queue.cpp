#include <iostream>
#include <fstream>

using namespace std;
const int MAX = 1000;
struct Queue{
    int Q[MAX];
    int front;
    int rear;
    int count;
};

void initialization(Queue &queue){
    queue.front = 0;
    queue.rear = -1;
    queue.count = 0;
}

bool isEmpty(Queue queue){
    if (queue.count == 0) return true;
    return false;
}

bool isFull(Queue queue){
    if (queue.count == MAX) return true;
    return false;
}

bool enqueue(Queue &queue, int value){
    if (isFull(queue)) return false;
    queue.rear = (queue.rear + 1) % MAX;
    queue.Q[queue.rear] = value;
    queue.count += 1;
    return true;
}

bool dequeue(Queue &queue, int &result){
    if (isEmpty(queue)) return false;
    result = queue.Q[queue.front];
    queue.front = (queue.front + 1) % MAX;
    queue.count -= 1;
    return true;
}

bool get_top(Queue queue, int &result){
    if (isEmpty(queue)) return false;
    result = queue.Q[queue.front];
    return true;
}

void print(Queue queue){
    int result;
    while(!isEmpty(queue)){
        dequeue(queue, result);
        cout << result << " ";
    }
    cout << endl;
}

int main(){
    Queue queue;
    // Init
    initialization(queue);
    ifstream infile("input.txt");
    int n, value;
    infile >> n;
    for(int i=0; i < n; i++){
        infile >> value;
        enqueue(queue, value);
    }
    infile.close();
    // Get top
    get_top(queue, value);
    cout << "Get top value: " << value << endl;
    // Print
    print(queue);
    return 0;
}