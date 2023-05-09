#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Stack{
    int top;
    int size;
    int* data;
    
    Stack(int s){
        top = -1;
        size = s;
        data = new int[size];
    }
    
    void Push(int val){
        if (top >= size - 1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        data[top] = val;
    }
    
    int Pop(){
        if (top < 0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        top--;
        return data[top + 1];
    }
    
    int StackTop(){
        if (top < 0){
            cout<<"Empty Stack"<<endl;
            return -1;
        }
        return data[top];
    }
    
    bool isFull(){
        if (top >= size - 1){
            return true;
        }
        return false;
    }
    
    bool isEmpty(){
        if (top < 0){
            return true;
        }
        return false;
    }
    
    void Display(){
        if (top < 0){
            cout<<"Empty Stack"<<endl;
            return;
        }
        cout<<"[";
        for (int i = 0; i <= top; i++) {
            cout<<data[i];
            if (i != top){
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }
};

int main()
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
    
    cout<<"Using Array - Execution time : "<<setprecision(5)<< time_taken << " microseconds." << endl;

    
    return 0;
}
