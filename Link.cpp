#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#include<unistd.h>
using namespace std;

#define OK 1
#define ERROR 0

typedef int status;

#define INCREASE 10
#define MAX_SIZE 100

struct List{
    int *data;
    int length;
    int size;
};


// 初始化
// list 初始化的列表对象
status InitList(List &list){
    list.data = new int[MAX_SIZE];
    list.size = MAX_SIZE;
    list.length=0;
    return OK;
}

// 随机生成
status CreateList(List &list, int len = 10){
    srand(time(0));
    InitList(list);
    list.length=len;
    for(int i = 0; i < len; i++){
        list.data[i] = rand()%100;
    }
    return OK;
}

// 清空
status ClearList(List &list){
    list.length=0;
    return OK;
}

// 是否为空
status ListEmpty(List list){
    return list.length==0;
}

// 长度
int ListLength(List list){
    return list.length;
}

// 获取第index个元素
status GetElem(List list, int index, int &elem){
    if(index <= 0 || index > list.length) return ERROR;
    elem = list.data[index-1];
    return OK;
}

// 获取指定元素的前一个元素
status PriorElem(List list, int cur, int &elem){
    for(int i = 0; i < list.length; i++){
        if(list.data[i] == cur){
            if(i== 0) return ERROR;
            elem = list.data[i-1];
            return OK;
        }
    }
    return ERROR;
}

// 获取指定元素的后一个元素
status NextElem(List list, int cur, int &elem){
    for(int i = 0; i < list.length; i++){
        if(list.data[i] == cur){
            if(i== list.length-1) return ERROR;
            elem = list.data[i+1];
            return OK;
        }
    }
    return ERROR;
}

// 在第index位插入
status ListInsert(List &list, int index, int elem){
    if(index <= 0 || index > list.length+1) return ERROR;
    if(list.length + 1 > list.size){
        int *newDate = new int[list.length + INCREASE];
        newDate = list.data;
        list.data = newDate;
        list.size += INCREASE;
    }
    for(int i = list.length; i >= index; i--){
        list.data[i] = list.data[i-1];
    }
    list.data[index-1] = elem;
    list.length++;
    return OK;

}

// 删除第index位元素
status ListDelete(List &list, int index, int &elem){
    if(index <= 0 || index > list.length) return ERROR;
    elem = list.data[index-1];
    for(int i = index; i < list.length; i++){
        list.data[i-1] = list.data[i];
    }
    list.length--;
    return OK;
}

// 对每一个元素调用func（）函数
void ListTraverse(List list, void (*func)(int elem)){
    for(int i = 0; i < list.length; i++){
        func(list.data[i]);
    }
}

// 展示list元素
void display(List list){
    cout<<"list has " << list.length << " elems"<<endl;
    for(int i = 0; i < list.length; i++){
        cout<<list.data[i]<<"\t";
        if(i % 20 == 0 && i != 0) cout<<endl;
    }
    cout<<endl;
}

// test function
// int main(){
//     List list;
//     int elem;
//     InitList(list);
//     CreateList(list);
//     display(list);
//     ListInsert(list, 2, 10);
//     display(list);
//     ListInsert(list, 12, 110);
//     display(list);
//     ListDelete(list, 10, elem);
//     cout<<"the elem deleted is "<<elem<<endl;
//     display(list);
//     return 0;
// }