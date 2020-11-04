#include <bits/stdc++.h>
using namespace std;
struct node {
    node* next;
    node* previous;
    int data;
    node(int d, node* n = NULL,node *p=NULL)
    {
        next = n;
        previous=p;
        data = d;
    }
};
class linked_list {
public:
    node* head,*tail;
    linked_list()
    {
        head = NULL;
        tail=NULL;
    }
    void print()
    {
        node* walker = head;
        while (walker != NULL) {
            cout << walker->data << " ";
            walker = walker->next;
        }
        cout << endl;
        walker = tail;
        while (walker != NULL) {
            cout << walker->data << " ";
            walker = walker->previous;
        }
        cout << endl;
        
    }
    void push_back(int x){
        node* _new= new node(x);
        if(head==NULL){
            head=_new;
            tail=_new;
            return ;
        }
        node* walker=head,*rear;
        while(walker!=NULL){
            rear=walker;
            walker=walker->next;
        }
        rear->next=_new;
        _new->previous=rear;
        tail=_new;
    }
    void Delete(int id){
        if(head==NULL)return;
        if(head->data==id){
            head=head->next;
            if(head!=NULL)
                head->previous=NULL;
            else{
                tail=NULL;
            }
            return;
        }
        node*  walker=head;
        node* rear=NULL;
        while(walker!=NULL){
            if(walker->data==id){
                rear->next=walker->next;
                if((walker->next)!=NULL)
                    (walker->next)->previous=rear;
                else {
                    tail=rear;
                }
                return ;
            }
            rear=walker;
            walker=walker->next;
        }
        tail=rear;
    }
};
bool palindrome(linked_list a){
    node * walker=a.head;
    node * walker1=a.tail;
    while(walker!=NULL){
        if(walker->data!=walker1->data){
            return false;
        }
        walker=walker->next;
        walker1=walker1->previous;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    linked_list a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout<<palindrome(a);
    
    
}
