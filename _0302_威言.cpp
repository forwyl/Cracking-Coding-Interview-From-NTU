#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
3.2 How would you design a stack which, in addition to push and pop, also has a function min which returns
 the minimum element? Push, pop and min should all operate in O(1) time.
*/

template<class T>
class StackMin{

    private:
        int cap;
        int top;
        int min;
        int min_index;
        int* items;

    public:
        StackMin(int size){
            cap = size;
            top = -1;
            min_index = 0;
            items = new int[cap];
        }

        ~StackMin(){
            delete [] items;
        }

        void push(int c){

            if(top==0){
                min = items[top];
            }
            if(full()){
                cout<< "Stack full!" << endl;
                exit(1);
            }
            if(c < min){
                min = c;
                min_index = top+1;
            }
            items[++top] = c;
        }

        int pop(){
            if(empty()){
                cout << "Stack empty!" << endl;
                exit(1);
            }
            return items[top--];
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

        int show_min(){
            return min;
        }

};

int main() {

    int cap, data, i;
    cout << "Enter stack size: ";
    cin >> cap;
    StackMin<int> s(cap);

    for(i=0; i<cap; i++){
        cout << "Push decimal data:";
        cin >> data;
        s.push(data);
    }

    cout<< "----------[Output]----------" << endl;
    cout<< " Min element in O(1): ";
    cout<< s.show_min() << endl;
    for(i=0; i<cap; i++){
        cout<< " Pop element in O(1): ";
        cout<< s.pop() << endl;
    }

    return 0;

}


