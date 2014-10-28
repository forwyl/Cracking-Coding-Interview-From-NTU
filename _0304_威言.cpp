#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
/**
3.4 In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different
sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending
order of size from top to bottom (e.g., each disk sits on top of an even larger one).
You have the following constraints: (A) Only one disk can be moved at a time. (B) A disk
is slid off the top of one rod onto the next rod. © A disk can only be placed on top of a
larger disk. Write a program to move the disks from the first rod to the last using Stacks.
**/

template<class T>
class Stack{

    private:
        vector<T> vs;

    public:
        void push(T s){
            vs.push_back(s);
        }

        T pop(){
            T data = vs.back();
            vs.pop_back();
            return data;
        }

        void show_all(){
            for(int i=0; i<vs.size(); i++){
                cout << vs[i] << endl;
            }
        }

};

void tower_of_Hanoi_algo(int disks, Stack<int>* source, Stack<int>* spare, Stack<int>* dest){
    if(disks==1){
        int data = source->pop();
        dest->push(data);
    }else{
        tower_of_Hanoi_algo(disks-1, source, dest, spare);
        tower_of_Hanoi_algo(1, source, spare, dest);
        tower_of_Hanoi_algo(disks-1, spare, source, dest);
    }
}

int main(){

    int disks;
    cout << "Enter the number of disks:";
    cin >> disks;
    Stack<int> *source = new Stack<int>();
    for(int i=disks; i>0; i--){
        source->push(i);
    }
    source->show_all();

    Stack<int> *spare = new Stack<int>();
    Stack<int> *dest = new Stack<int>();
    tower_of_Hanoi_algo(disks, source, spare, dest);

    cout << "---Print result---" <<endl;
    dest->show_all();

}
