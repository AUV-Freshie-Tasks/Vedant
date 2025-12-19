#include "matrixDec.h"
#include <iostream>
#include <vector>
class LRUCache {
public:
    class node {
    public:
        matrix key;
        node* next;
        node* prev;
    };
    matrix placholder(1);
    unordered_map<int,matrix> cacheVal;
    unordered_map<int,node*> cacheOrd;
    int maxSize,currentSize =0;
    node* head;
    node* tail;
    LRUCache(int capacity) {
        maxSize=capacity;
        head = new node{placeholder,nullptr,nullptr}; 
        tail = new node{placeholder,nullptr,head};
        head->next=tail;
    }
    int get(matrix key) {
        if(cacheVal.find(key)!=cacheVal.end()){
            cacheOrd[key]->prev->next=cacheOrd[key]->next;
            cacheOrd[key]->next->prev=cacheOrd[key]->prev;
            cacheOrd[key]->prev=head;
            cacheOrd[key]->next=head->next;
            head->next=cacheOrd[key];
            cacheOrd[key]->next->prev=cacheOrd[key];
            return cacheVal[key];
        }
        return -1;
        //activate
    }
    
    void put(matrix key, int value) {
        if(cacheVal.find(key)==cacheVal.end()){
            if(currentSize==maxSize){
                cacheVal.erase(tail->prev->key);
                cacheOrd.erase(tail->prev->key);
                node* temp=tail->prev->prev;
                tail->prev=temp;
                temp->next=tail;
            }
            cacheVal[key]=value;
            node* element=new node{key,head->next,head};
            head->next->prev = element;
            head->next=element;
            cacheOrd[key]=element;
            if(currentSize!=maxSize){currentSize++;}
        }
        else{
            cacheVal[key]=value;
            cacheOrd[key]->prev->next=cacheOrd[key]->next;
            cacheOrd[key]->next->prev=cacheOrd[key]->prev;
            cacheOrd[key]->prev=head;
            cacheOrd[key]->next=head->next;
            head->next=cacheOrd[key];
            cacheOrd[key]->next->prev=cacheOrd[key];
        }
    }
};
