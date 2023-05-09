#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node{
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

struct Stack{
    Node* top;
    int index;
    int size;
    
    Stack(int s){
        top = NULL;
        index = -1;
        size = s;
    }
    
    void Push(int val){
        if (index >= size - 1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        Node* n = new Node(val);
        n->next = top;
        top = n;
        index++;
    }
    
    int Pop(){
        if (index < 0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        index--;
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    
    int StackTop(){
        if (top == NULL){
            cout<<"Empty Stack"<<endl;
            return -1;
        }
        return top->data;
    }
    
    bool isFull(){
        if (index >= size - 1){
            return true;
        }
        return false;
    }
    
    bool isEmpty(){
        if (index < 0){
            return true;
        }
        return false;
    }
    
    void Display(){
        if (index < 0){
            cout<<"Empty Stack"<<endl;
            return;
        }
        Node* temp = top;
        cout<<"[";
        while (temp != NULL) {
            cout<<temp->data;
            temp = temp->next;
            if (temp != NULL){
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }
};

int StackFromLinkedList()
{
    int stack_size;
    cout<<"Size of the stack : ";
    cin>>stack_size;
    
    auto startTime = high_resolution_clock::now();
    
    Stack s(stack_size);
    
    for (int i = 0; i < stack_size; i++) {
        s.Push(rand() % 100);
    }
    
    s.Display();
    
    for (int i = 0; i < stack_size/2; i++) {
        s.Pop();
    }
    
    s.Display();
    
    for (int i = 0; i < stack_size/2 - 1; i++) {
        s.Push(rand() % 100);
    }
    
    s.Display();
    
    auto endTime = high_resolution_clock::now();
    
    double time_taken = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    
    cout<<"Execution time : "<< time_taken << " microseconds." << endl;

    return 0;
}
