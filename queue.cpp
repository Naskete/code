#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int status;

#define INCREASE 10
#define INIT_SIZE 10 

struct Queue{
    int *date;
    int size;
    int length;
};

status InitQueue(Queue &queue){
    queue.date = new int[INIT_SIZE];
    queue.size = INIT_SIZE;
    queue.length = 0;
    return OK;
}

bool IsEmpty(Queue queue){
    return queue.length == 0;
}

status Enqueue(Queue &queue, int elem){
    int index = queue.length;
    if(index >= queue.size){
        int *temp = new int[queue.length+INCREASE];
        queue.size+=INCREASE;
        temp = queue.date;
        queue.date = temp;
    }
    queue.date[index] = elem;
    queue.length+=1;
    return OK;
}

status Dequeue(Queue &queue, int &elem){
    if(IsEmpty(queue)) return ERROR;
    elem = queue.date[0];
    for(int i = 0; i < queue.length; i++){
        queue.date[i] = queue.date[i+1];
    }
    queue.length--;
    return OK;
}

void Display(Queue queue){
    for(int i = 0; i < queue.length; i++){
        cout<<"--";
    }
    cout<<endl;
    for(int i = 0; i < queue.length; i++){
        cout<<queue.date[i]<<"|";
    }
    cout<<endl;
    for(int i = 0; i < queue.length; i++){
        cout<<"--";
    }
    cout<<endl;
}

// int main(){
//     Queue queue;
//     int elem = 101;
//     InitQueue(queue);
//     for(int i = 0; i < 10; i++){
//         Enqueue(queue, i);
//     }
//     Display(queue);
//     Dequeue(queue, elem);
//     cout<<elem<<endl;
//     Display(queue);
//     Enqueue(queue,12);
//     Display(queue);
// }
