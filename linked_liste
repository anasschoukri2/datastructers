#include <bits/stdc++.h>
using namespace std;
struct node {
    node* next;
    int data;
    node(int d, node* n = NULL)
    {
        next = n;
        data = d;
    }
};
class linked_list {
public:
    node* head;
    linked_list()
    {
        head = NULL;
    }
    void print()
    {
        node* walker = head;
        while (walker != NULL) {
            cout << walker->data << " ";
            walker = walker->next;
        }
        cout << endl;
    }
    void push_back(int x)
    {
        node* _new = new node(x);
        if (head == NULL) {
            head = _new;
            return;
        }
        node* walker = head;
        node* rear;
        while (walker != NULL) {
            rear = walker;
            walker = walker->next;
        }
        rear->next = _new;
    }
    void Delete(int id)
    {
        if (head == NULL)
            return;
        if (head->data == id) {
            head = head->next;
            return;
        }
        node* walker = head;
        node* rear;
        while (walker != NULL) {
            if (walker->data == id) {
                rear->next = walker->next;
                return;
            }
            rear = walker;
            walker = walker->next;
        }
    }

    void delete_dup()
    {
        node* walker = head;
        while (walker != NULL) {
            node* walker1 = walker->next;
            node* rear = walker;
            while (walker1 != NULL) {
                if (walker1->data == walker->data) {
                    rear->next = walker1->next;
                    walker1 = walker1->next;
                    continue;
                }
                rear = walker1;
                walker1 = walker1->next;
            }
            print();
            walker = walker->next;
        }
    }
};
linked_list add(linked_list a, linked_list b)
{
    node* walker1 = a.head;
    node* walker2 = b.head;
    linked_list result;
    int carry = 0;
    while (walker1 != NULL && walker2 != NULL) {
        int x = walker2->data + walker1->data + carry;
        result.push_back(x % 10);
        carry = x / 10;
        walker1 = walker1->next;
        walker2 = walker2->next;
    }
    while (walker1 != NULL) {
        int x = walker1->data + carry;
        result.push_back(x % 10);
        carry = x / 10;
        walker1 = walker1->next;
    }
    while (walker2 != NULL) {
        int x = walker2->data + carry;
        result.push_back(x % 10);
        carry = x / 10;
        walker2 = walker2->next;
    }
    return result;
}
bool palindrom()
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
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    linked_list r = add(a, b);
    r.print();
}
