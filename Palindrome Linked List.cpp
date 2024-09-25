// Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.


// Examples:
// Input: LinkedList: 1->2->1->1->2->1
// Output: true
// Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

// Input: LinkedList: 1->2->3->4
// Output: false
// Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.


// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1) 


// Note: You should not use the recursive stack space as well


// Constraints:
// 1 <= number of nodes <= 105
// 1 ≤ node->data ≤ 103

//   Solution:=>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        //step 1 middle element
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow=middle element
        //step2 reverse middle element ke baad;
        Node* prev = NULL,*curr = slow;
        while(curr){
            Node *NextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NextNode;
        }
        //step 3 compare
        Node* first = head,*second = prev;
        while(second){
            if(first->data != second->data) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}
