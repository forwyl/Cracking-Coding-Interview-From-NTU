#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
/**
3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack
exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
SetOfStacks should be composed of several stacks, and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
behave identically to a single stack (that is, pop() should return the same values
as it would if there were just a single stack). FOLLOW UP Implement a function
popAt(int index) which performs a pop operation on a specific sub-stack.
**/
int stack_size, data_size, stack_num;

template<class T>
class MultiStacks{

    private:
        int cap;
        int top;
        vector<T> vs;

    public:
        MultiStacks(){

        }

        MultiStacks(int size){
            cap = size;
            top = -1;
        }

        void push(T s){
            if(full()){
                cout<< "Stack full!" << endl;
                exit(1);
            }
            vs.push_back(s);
            ++top;
        }

        T pop(){
            if(empty()){
                cout << "Stack empty!" <<endl;
                exit(1);
            }
            cout << "POP top value:" << top <<endl;
            return vs[top--];
        }

        T show(int index){
            return vs[index];
        }

        bool empty(){
            if(top == -1)
                return true;
            else
                return false;
        }

        bool full(){
            if (top+1 == cap)
                return true;
            else
                return false;
        }

};

vector< MultiStacks<string>* > input_push(int stack_num){

    int data_counter = 0;
    string data;
    vector< MultiStacks<string>* > vs;

    for(int i=0; i<stack_num; i++){
        MultiStacks<string> *ms = new MultiStacks<string>(stack_size);
        while(data_counter<data_size && !ms->full()){
            cout << "Push data:";
            cin >> data;
            ms->push(data);
            data_counter++;
        }
        vs.push_back(ms);
    }

    return vs;
}

int output_pop(int stack_index, vector< MultiStacks<string>* > vs){

    MultiStacks<string> *ms = vs[stack_index];
    while(ms->empty()){
        ms = vs[--stack_index];
    }

    cout<< "POP Data:" << ms->pop() << ", in stack no." << stack_index+1 <<endl;

    return stack_index;
}

void pop(vector< MultiStacks<string>* > vs){

    string isPop = "";
    int counter = 0;
    int stack_index = vs.size()-1;
    while(isPop != "N"){
        cout << "Wanna POP? (Y/N):";
        cin >> isPop;
        if(isPop=="N" | counter>=data_size){
            cout << "STOP!" << endl;
            break;
        }else if(isPop=="Y"){
            counter++;
            stack_index = output_pop(stack_index, vs);
        }
    }
}

void pop_at(int index, vector< MultiStacks<string>* > vs){

    int stack_index = --index; // 0-based mode

    MultiStacks<string> *ms = vs[stack_index];
    while(!ms->empty()){
        cout<< "POP Data:" << ms->pop() << ", in stack no." << stack_index+1 <<endl;
    }

    cout << "Pop All in stack no."<< index+1 <<endl;
}

int main(){

    cout << "Enter stack size: ";
    cin >> stack_size;
    cout << "Enter data size: ";
    cin >> data_size;
    if(data_size%stack_size==0){
       stack_num = data_size/stack_size;
    }else{
       stack_num = (data_size/stack_size)+1;
    }

    int index;
    vector< MultiStacks<string>* > vs = input_push(stack_num);


    //pop_at scenario
    cout << "Enter stack index (1-based): ";
    cin >> index;
    pop_at(index, vs);


    /**
    //pop scenario
    pop(vs)
    **/

    return 0;
}
