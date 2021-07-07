#include<iostream>
#include<ctime>
using namespace std;

#define OK 1
#define ERROR 0
typedef int status;

typedef struct Node{
    int elem;
    struct Node *next;
}Node, *Linklist;

// 初始化
status InitLinklist(Linklist &list){
    list = (Linklist) new Node;
    list->next = NULL;
    return OK;
}

// 随机生成
status CreateLinklist(Linklist &list){
    srand(time(0));
    InitLinklist(list);
    // 逆序
    for(int i = 0; i < 10; i++){
        Node *p = new Node;
        p->elem = i+1;
        // p->elem = rand()%100+10;
        p->next = list->next;
        list->next = p;
    }

    // 顺序
    // Linklist p = list;
    // for(int i = 0; i < 10; i++){
    //     Node *q = new Node;
    //     q->elem = rand()%100+10;
    //     q->next = NULL;
    //     p->next = q;
    //     p = p->next;
    // }
    return OK;
}

// 清空
status ClearLinklist(Linklist &list){
    list->next = NULL;
    return OK;
}

// 空判断
bool LinklistEmpty(Linklist list){
    return list->next == NULL; 
}

// 链表长度
int LinklistLength(Linklist list){
    Linklist p = list;
    int length = 0;
    while(p->next){
        p = p->next;
        length++;
    }
    return length;
}

// 获取第index个元素
status GetElem(Linklist list, int index, int &elem){
    int length = LinklistLength(list);
    if(index <= 0 || index > length) return ERROR;
    int i = 0;
    Linklist p = list->next;
    while(++i){
        if(i == index) {
            elem = p->elem;
            break;
        }
        p = p->next;
    }
    return OK;
}

// 获取cur的前一个元素
status Prior(Linklist list, int cur, int &elem){
    Linklist q=list->next,p = q->next;
    while(p){
        if(p->elem==cur){
            elem=q->elem;
            return OK;
        }
        p=p->next;
        q=q->next;
    }
    return ERROR;
}

// 获取cur的下一个元素
status Next(Linklist list, int cur, int &elem){
    Linklist p = list->next;
    while (p->next){
        if(p->elem==cur){
            elem = p->next->elem;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

// 在第index个位置插入elem
status Insert(Linklist &list, int index, int elem){
    int len = LinklistLength(list);
    if(index <= 0 || index > len + 1) return ERROR;
    int i = 0;
    Linklist p = list;
    while(p->next){
        p = p->next;
        if(i == index - 1){
            Node *q = new Node;
            q->elem = elem;
            q->next = p->next;
            p->next = q;
            return OK;
        }
        i++;
    }
    return ERROR;
}

// 删除第index个元素
status Delete(Linklist &list, int index, int &elem){
    if(index <= 0 || index > LinklistLength(list)) return ERROR;
    int i = 0;
    Linklist p = list;
    while(p->next){
        i++;
        if(i==index){
            elem = p->next->elem;
            p->next = p->next->next;
            return OK;
        }
        p=p->next;
    }
    return ERROR;
}

// 打印链表
void Display(Linklist list){
    int i = 0,len = LinklistLength(list);
    Linklist p = list;
    while(p->next&&++i){
        p=p->next;
        cout<<p->elem;
        if(i!=len) cout<<"->";
    }
    cout<<endl;
}

// 链表翻转
void Reverse(Linklist &list){
    Linklist p = list->next;
    list->next = NULL;
    while(p){
        Node *q = new Node;
        q->elem = p->elem;
        q->next = list->next;
        list->next = q;
        p=p->next;
    }
}