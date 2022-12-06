#pragma once
#include <string>
#include <vector>
using namespace std; 

struct Node
{
    string first;
    vector <string> second;
    int depth;
    Node* left;
    Node* right;
    
};

class Map
{
public:
        
  
        // First is key, second is value
        // and depth is height of the subtree
        // for the given node
        
        void insert1(string first, vector<string> second);
        void choice1(string albumName);
        void choice2(string artistName);
        void choice3(string year);
        void choice4(string year);
        void choice5(string genre);
        void iteratePublic();
        vector<string>& operator[](string first);

private:
    int count;
    Node* root = nullptr;
    bool check = false;
    void choice1Helper(Node* head, string albumName);
    void choice2Helper(Node* head, string artistName);
    void choice3Helper(Node* head, string year);
    void choice4Helper(Node* head, string year);
    void choice5Helper(Node* head, string genre);
    Node* insertFnct(Node* node, string &first, vector <string> &second);
    void iterate(Node* head);
    Node* nodeSetUp(string first, vector<string>);
    void insert(string first, vector<string> second);
    Node* balanceBST(Node* node);
    int getHeight(Node* node);
    int getBalanceFactorHelper(Node*& node);
    int getMax(int leftHeight, int rightHeight);
    Node* rotateLeftHelper(Node* node);
    Node* rotateRightHelper(Node* node);
    Node* rotateRightLeftHelper(Node* node);
    Node* rotateLeftRightHelper(Node* node);
    void update(string first, vector <string> second);
    
};

