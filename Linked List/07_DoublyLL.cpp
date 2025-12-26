#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
}; 

class LinkedList{
    Node *head;
    // Node *tail;

    public:
    LinkedList(){
        head = NULL;
    }

    void push_back(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }
    }

    void pop_front(){
    if(head == NULL){
        cout << "LL is Empty" << endl;
        return;
    }

    Node *temp = head;

    // single node
    if(head->next == NULL){
        head = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }

    delete temp;
}

     void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList L;

    L.push_back(10);
    L.push_back(20);
    L.push_back(30);

    L.display();   // 10 20 30

    L.pop_front();
    L.display();   // 20 30
}