#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next=NULL;
    }
};

class CircularList{
    Node *head;
    Node *tail;

    public:
    CircularList(){
        head=tail=NULL;
    }

    void push_back(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            tail->next = head;  
        }
        else{
            newNode->next = tail->next;
            tail->next = newNode;
            tail=newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"Empty Circular List "<<endl;
            return;
        }
        Node *temp = head;
        if(head == tail){
            head = tail = NULL;
        }
        else{
            
            head = head->next;
          tail->next = head;
        }
        delete(temp);

    }

    void display(){
    if(head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
}

};

int main(){
    CircularList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.pop_front();
    l.display();
    return 0;
}