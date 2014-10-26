#include <iostream>
#include <string>
using namespace std;

/*
Describe how you could use a single array to implement three stacks.
*/
string *stack_ary;
int first_size, second_size, third_size;
int first_index, second_index, third_index;

void push(int index){
    cout << "Enter data: ";
    cin >> stack_ary[index];
}

string pop(int index){
    cout << stack_ary[index] << endl;
    return stack_ary[index];
}

void input(){

    cout << "Enter first stack size: ";
    cin >> first_size;
    cout << "Enter second stack size: ";
    cin >> second_size;
    cout << "Enter third stack size: ";
    cin >> third_size;
    stack_ary = new string[first_size+second_size+third_size];
    first_index = -1;
    second_index = first_index+first_size;
    third_index = second_index+second_size;

    cout << "---Push first stack data---" << endl;
    do{
       push(++first_index);
    }while(first_index < first_size-1);

    cout << "---Push second stack data---" << endl;
    do{
       push(++second_index);
    }while(second_index < first_size+second_size-1);

    cout << "---Push third stack data---" << endl;
    do{
       push(++third_index);
    }while(third_index < first_size+second_size+third_size-1);

}

void display(){

    cout << "---Pop first stack data---" << endl;
    do{
       pop(first_index--);
    }while(first_index > -1);

    cout << "---Pop second stack data---" << endl;
    do{
       pop(second_index--);
    }while(second_index > first_size-1);

    cout << "---Pop third stack data---" << endl;
    do{
       pop(third_index--);
    }while(third_index < first_size+second_size-1);

}

int main() {

    input();
    display();
    return 0;

}
