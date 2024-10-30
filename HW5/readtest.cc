// #include <iostream>
// #include <string>
// #include <vector> // use C++ STL vector with our struct
// #include <cmath>
// #include <random> // use this to generate random number
// #include <fstream>
// #include <sstream>

#include <iostream>
// #include <string>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

void reversePrint(ListNode* head){
    if(head == nullptr){
        return;
    }

    reversePrint(head->next);
    cout << head ->data << "->";

}

int main(){
    ListNode* head = new ListNode;
    ListNode* second = new ListNode;
    ListNode* third = new ListNode;
    ListNode* fourth = new ListNode;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = nullptr; // End of the list

    reversePrint(head);

    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;

    // Free the allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
