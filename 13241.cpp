#include "iostream"
using namespace std;

class stack{
    public:
    stack();
    void push(int el);
    int Top();
    int pop();
    bool IsEmpty();
    bool IsFull();

    private:
    int top;
    int arr[10];
};

class queue{
    public:
    queue();
    void push(int el);
    int pop();
    bool IsEmpty();
    bool IsFull();

    private:
    int rear;
    int arr[10];
};

stack::stack(){
    top = 0;
}

bool stack::IsFull(){
    return top == 10;
}

bool stack::IsEmpty(){
    return top == 0;
}

void stack::push(int el){
    if(IsFull()) return;
    arr[top++]=el;
}

int stack::Top(){
    return arr[top-1];    
}

int stack::pop(){
    if(IsEmpty()) return -1;
    return arr[--top];
}

queue::queue(){
    rear = 0;
}

bool queue::IsFull(){
    return rear == 10;
}

bool queue::IsEmpty(){
    return rear = 0;
}

void queue::push(int el){
    if(IsFull()) return;
    arr[rear++] = el;
}

int queue::pop(){
    if(IsEmpty()) return -1;
    int el = arr[0];
    rear--;
    for(int i = 0; i<rear; i++){
        arr[i] = arr[i+1];
    }
    cout << el;
}

int main(){

}