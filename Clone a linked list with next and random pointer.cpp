// You are given a special linked list where each node has a next pointer pointing to its next node. You are also given some random pointers, where you will be given some pairs denoting two nodes a and b i.e. a->random = b (random is a pointer to a random node).
// Construct a copy of the given list. The copy should consist of the same number of new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the original and copied list pointers represent the same list state. None of the pointers in the new list should point to nodes in the original list.
// For example, if there are two nodes x and y in the original list, where x->random = y, then for the corresponding two nodes xnew and ynew in the copied list, xnew->random = ynew.
// Return the head of the copied linked list.


// NOTE : 
// 1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
// 2. Don't make any changes to the original linked list.

// ArbitLinked List1
// Note: The diagram isn't part of any example, it just depicts an example of how the linked list may look.


// Examples:
// Input: LinkedList: 1->2->3->4 , pairs = [{1,2},{2,4}]
// Output: true
// Explanation: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbitrary pointer set, rest two nodes have arbitrary pointer as NULL. Second line tells us the value of four nodes. The third line gives the information about arbitrary pointers. The first node arbitrary pointer is set to node 2.  The second node arbitrary pointer is set to node 4.

// Input: LinkedList: 1->3->5->9 , pairs[] = [{1,1},{3,4}]
// Output: true
// Explanation: In the given testcase, applying the method as stated in the above example, the output will be 1.


// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(1)


// Constraints:
// 1 <= numbers of random pointer <= number of nodes <= 100
// 0 <= node->data <= 1000
// 1 <= a, b <= 100

//   Solution:=>

#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->random == NULL)
            k = -1;
        else
            k = temp->random->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}
void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data)
            return false;
        if ((temp1->random == NULL && temp2->random != NULL) ||
            (temp1->random != NULL && temp2->random == NULL) ||
            (temp1->random != NULL && temp2->random != NULL &&
             temp1->random->data != temp2->random->data))
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/
class Solution {
  public:
    Node *copyList(Node *head) {
        //STEP 1 input list ki nodes ke beech me op list ki node hume rkhni hai mapping create
        if(head==NULL) return head;
        Node * temp=head;
        while(temp){
            Node *n=new Node(temp->data);
            n->next=temp->next;
            temp->next=n;
            temp=n->next;
        }
        //STEP 2 random pointer assing krde clone ll me
        temp=head;
        Node *head2=temp->next;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        //STEP 3 op list return krde
        temp = head;
        while(temp!=NULL){
            Node * temp2=temp->next;
            temp->next=temp2->next;
            if(temp2->next)
            temp2->next=temp2->next->next;
            temp=temp->next;
        }
        return head2;
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after T
    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = NULL, *tail = NULL;
        for (int i = 0; i < arr.size(); ++i) {
            append(&head, &tail, arr[i]);
        }
        getline(cin, input);
        stringstream ss2(input);
        vector<int> arr2;
        while (ss2 >> number) {
            arr2.push_back(number);
        }
        Node *temp = head;
        for (int i = 0; i < arr2.size(); i += 2) {
            int a = arr2[i];
            int b = arr2[i + 1];

            Node *tempA = head;
            Node *tempB = head;
            for (int j = 1; j < a; ++j) {
                tempA = tempA->next;
            }
            for (int j = 1; j < b; ++j) {
                tempB = tempB->next;
            }
            tempA->random = tempB;
        }
        Solution ob;
        Node *res = ob.copyList(head);
        if (validation(head, res)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
