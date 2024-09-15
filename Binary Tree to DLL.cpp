// Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
// Note: h is the tree's height, and this space is used implicitly for the recursion stack.


// Examples:
// Input:
//       1
//     /  \
//    3    2
// Output:
// 3 1 2 
// 2 1 3
// Explanation: DLL would be 3<=>1<=>2

// Input:
//        10
//       /   \
//      20   30
//    /   \
//   40   60
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40


// Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
// Expected Time Complexity: O(no. of nodes)
// Expected Space Complexity: O(height of the tree)


// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 0 ≤ Data of a node ≤ 105

//   Solution:=>

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node(val);
    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Function to print nodes in a given doubly linked list */
void printList(Node* node) {
    Node* prev = NULL;
    while (node != NULL) {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev != NULL) {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}
/* Structure for tree and linked list
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
class Solution {
  public:
    void inorder(Node* root, vector<Node*> &v) {
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    Node* bToDLL(Node* root) {
        vector<Node*> v;
        inorder(root, v);
        if(v.size() == 1) return root;
        for(int i = 0; i < v.size(); i++) {
            if(i == 0) {
                v[i]->left = NULL;
                v[i]->right = v[i+1];
            } else if(i == v.size()-1) {
                v[i]->left = v[i-1];
                v[i]->right = NULL;
            } else {
                v[i]->left = v[i-1];
                v[i]->right = v[i+1];
            }
        }
        return v[0];
    }
};

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        Node* head = ob.bToDLL(root);
        printList(head);
    }
    return 0;
}
