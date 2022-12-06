#include "Map.h"
#include <iostream>

Node* Map::nodeSetUp(string first1, vector<string> second)
{
    Node* node = new Node();
    node->first = first1;
    node->second = second;
    node->left = nullptr;
    node->right = nullptr;
    node->depth = 1;
    return(node);

}


Node* Map::insertFnct(Node* node, string &first, vector<string> &second)
{
    if (node == nullptr) {
        count++;
        return nodeSetUp(first, second);
    }
        int comparison = first.compare(node->first);
        if (comparison == 0) {
            return node;
        }
        if (comparison < 0) {
            node->left = insertFnct(node->left,first,second);
        }
        else if (comparison > 0) {
            node->right = insertFnct(node->right, first, second);
        }
        
        node->depth = 1 + getMax(getHeight(node->left), getHeight(node->right));

        if (getBalanceFactorHelper(node) > 1) {
            int comparison1 = first.compare(node->left->first);
            if (comparison1 < 0) {
                return rotateRightHelper(node);
            }
            else if (comparison1 > 0) {
                return rotateLeftRightHelper(node);
            }

        }
        
        else if (getBalanceFactorHelper(node) < -1) {
            int comparison1 = first.compare(node->right->first);
            if (comparison1 > 0) {
                return rotateLeftHelper(node);
            }
            else if (comparison1 < 0) {
                return rotateRightLeftHelper(node);
            }
        }

        return node;
}

void Map::insert1(string first, vector<string> second) {
    root = insertFnct(root, first,second);
}

int Map::getHeight(Node* node) {

    if (node == nullptr) {
        return 0;
    }

    else {
        return node->depth;
    }
}

int Map::getBalanceFactorHelper(Node*& node){
    int balanceFactor = (getHeight(node->left) - getHeight(node->right));
    return balanceFactor;
}


int Map::getMax(int leftHeight, int rightHeight)
{
    if (leftHeight > rightHeight) {
        return leftHeight;
    }
    else {
        return rightHeight;
    }
}


Node* Map::rotateLeftHelper(Node* node) {
    //places pointer of grandchild to the left of newParent
    Node* grandchild = node->right->left;
    //Sets the location of newParent as to the right of where the node passed in is 
    Node* newParent = node->right;
    //Place node to the left of newParent
    newParent->left = node;
    //Gets rid of dragging poiner 
    node->right = grandchild;
    //Updates height of node after rotation
    node->depth = 1 + getMax(getHeight(node->left), getHeight(node->right));
    //Updates the height of newParent after rotation
    newParent->depth = 1 + getMax(getHeight(newParent->left), getHeight(newParent->right));
    return newParent;
}

Node* Map::rotateRightHelper(Node* node) {
    //places pointer of grandchild to the right of newParent
    Node* grandchild = node->left->right;
    //Sets the location of newParent as to the left of where the node passed in is 
    Node* newParent = node->left;
    //Place node to the right of newParent
    newParent->right = node;
    //Gets rid of dragging poiner 
    node->left = grandchild;
    //Updates height of node after rotation
    node->depth = 1 + getMax(getHeight(node->left), getHeight(node->right));
    //Updates the height of newParent after rotation
    newParent->depth = 1 + getMax(getHeight(newParent->left), getHeight(newParent->right));
    return newParent;
}

Node* Map::rotateRightLeftHelper(Node *node)
{
    //sets newParent to the right of the node passed in, in order to set up 
    //right rotation
    Node* newParent1 = node->right;
    //sets node->right node to equal the node returned by rotateRight fnct once newParent is passed in 
    node->right = rotateRightHelper(newParent1);
    //pass in node to be rotated to the left, and return that node
    return rotateLeftHelper(node);
}

//Left Right Rotation
Node* Map::rotateLeftRightHelper(Node* node)
{
    //Sets newParent to the left of the node passed in, in order to set up 
    //left rotation 
    Node* newParent1 = node->left;
    //sets node->left node to equal the node returned by rotateLeft fnct once newParent is passed in 
    node->left = rotateLeftHelper(newParent1);
    //pass in node to be rotated to the left, and return that node
    return rotateRightHelper(node);
}

vector<string>& Map::operator[](string first)
{
    Node* temp = insertFnct(root, first,root->second);
    return temp->second;
}

void Map::choice1Helper(Node* head, string albumName)
{
    
    if (head == nullptr) {
        return;
    }
    if (head->left != nullptr) {
        choice1Helper(head->left, albumName);
    }
    for (int i = 0; i < head->second.size();i++) {
        if (head->second[i] == albumName) {
            check = true;
            cout << "Rank: " << head->second[i - 1] << endl;
            cout << "Artist: " << head->second[i + 1] << endl;
            cout << "Release Date: " << head->second[i + 2] << head->second[i + 3] << endl;
            cout << "Summary: " << head->second[i + 4] << endl;
            cout << "MetaScore: " << head->second[i + 5] << endl;
            cout << "UserScore: " << head->second[i + 6] << endl;
            cout << "Link: " << head->second[i + 7] << endl;
            cout << "Img_URL: " << head->second[i + 8] << endl;
            cout << endl; 
        }
    }
    if (head->right != nullptr) {
        choice1Helper(head->right, albumName);
    }
}

void Map::choice2Helper(Node* head, string artistName)
{
    if (head == nullptr) {
        return;
    }
    if (head->left != nullptr) {
        choice2Helper(head->left, artistName);
    }
    for (int i = 0; i < head->second.size();i++) {
        if (head->second[i] == artistName) {
            check = true;
            cout << "Album Title: " << head->second[i - 1] << endl;
            cout << "Rank: " << head->second[i - 2] << endl;
            cout << "Release Date: " << head->second[i + 1] << head->second[i + 2] << endl;
            cout << "Summary: " << head->second[i + 3] << endl;
            cout << "MetaScore: " << head->second[i + 4] << endl;
            cout << "UserScore: " << head->second[i + 5] << endl;
            cout << "Link: " << head->second[i + 6] << endl;
            cout << "Img_URL: " << head->second[i + 7] << endl;
            cout << endl;
        }
    }
    if (head->right != nullptr) {
        choice2Helper(head->right, artistName);
    }
}

void Map::choice3Helper(Node* head, string year)
{
    string rating = "0";
    if (head == nullptr) {
        return;
    }
    if (head->left != nullptr) {
        choice3Helper(head->left, year);
    }
    for (int i = 0; i < head->second.size();i++){
        if (head->second[i].substr(0, head->second[i].size() - 1) == year) {
            if (i + 2 < head->second.size()) {
                 rating = (head->second[i + 2]);
            }
            if (stoi(rating) > 87) {
                check = true;
                cout << "Album Title: " << head->second[i - 3] << endl;
                cout << "Artist: " << head->second[i - 2] << endl;
                cout << "Rank: " << head->second[i - 4] << endl;
                cout << "Release Date: " << head->second[i - 1] << head->second[i] << endl;
                cout << "Summary: " << head->second[i + 1] << endl;
                cout << "MetaScore: " << head->second[i + 2] << endl;
                cout << "UserScore: " << head->second[i + 3] << endl;
                cout << "Link: " << head->second[i + 4] << endl;
                cout << "Img_URL: " << head->second[i + 5] << endl;
                cout << endl; 
            }
        }

    }
    if (head->right != nullptr) {
        choice3Helper(head->right, year);
    }
}

void Map::choice4Helper(Node* head, string year)
{
    string rating = "0.0";
    if (head == nullptr) {
        return;
    }
    if (head->left != nullptr) {
        choice4Helper(head->left, year);
    }
    for (int i = 0; i < head->second.size();i++) {
        if (head->second[i].substr(0, head->second[i].size() - 1) == year) {
            if (i + 3 < head->second.size()) {
                 rating = (head->second[i + 3]);
            }
             if (stof(rating) > 8.7) {
                check = true;
                cout << "Album Title: " << head->second[i - 3] << endl;
                cout << "Artist: " << head->second[i - 2] << endl;
                cout << "Rank: " << head->second[i - 4] << endl;
                cout << "Release Date: " << head->second[i - 1] << head->second[i] << endl;
                cout << "Summary: " << head->second[i + 1] << endl;
                cout << "MetaScore: " << head->second[i + 2] << endl;
                cout << "UserScore: " << head->second[i + 3] << endl;
                cout << "Link: " << head->second[i + 4] << endl;
                cout << "Img_URL: " << head->second[i + 5] << endl;
                cout << endl;
           
           }
           
        }
        
    }
    if (head->right != nullptr) {
        choice4Helper(head->right, year);
    }
}

void Map::choice5Helper(Node* head, string genre)
{
    string rating = "0.0";
    int index; 
    if (head == nullptr) {
        return;
    }
    if (head->left != nullptr) {
        choice5Helper(head->left, genre);
    }
    for (int i = 0; i < head->second.size();i++) {
        int pos = 0;
        while ((index = head->second[i].find(genre, pos)) != string::npos) {
            pos = index + 1;
            if (i + 1 < head->second.size()) {
                rating = head->second[i + 1];
            }
        }

        if (stoi(rating) > 87) {
            rating = "0";
            cout << "Album Title: " << head->second[i - 4] << endl;
            cout << "Rank: " << head->second[i - 5] << endl;
            cout << "Artist: " << head->second[i - 3] << endl;
            cout << "Release Date: " << head->second[i - 2] << head->second[i - 1] << endl;
            cout << "Summary: " << head->second[i] << endl;
            cout << "MetaScore: " << head->second[i + 1] << endl;
            cout << "UserScore: " << head->second[i + 2] << endl;
            cout << "Link: " << head->second[i + 3] << endl;
            cout << "Img_URL: " << head->second[i + 4] << endl;
            cout << endl;
        }
    }
    if (head->right != nullptr) {
        choice5Helper(head->right, genre);
    }
}

void Map::iterate(Node* head)
{
    
    if (head == nullptr)
        return;
    if (head->left != nullptr) {
        iterate(head->left);
    }
    for (int i = 0; i < head->second.size();i++) {
        cout << head->second[i] << endl; 
    }
    cout << endl; 
    if (head->right != nullptr) {
        iterate(head->right);
    }
}
void Map::choice1(string albumName)
{
    choice1Helper(root, albumName);
    if (check == true) {
        check = false;
    }
    else if (check == false) {
        cout << "Sorry, we could not find that album" << endl;
    }
}
void Map::choice2(string artistName)
{
    choice2Helper(root, artistName);
    if (check == true) {
        check = false;
    }
    else if (check == false) {
        cout << "Sorry, we could not find that artist" << endl;
    }
}
void Map::choice3(string year)
{
    choice3Helper(root, year);
    if (check == true) {
        check = false;
    }
    else if (check == false) {
        cout << "Sorry, we could not find data on that year please try 1999-2021" << endl;
    }
}
void Map::choice4(string year)
{
    choice4Helper(root, year);
    if (check == true) {
        check = false;
    }
    else if (check == false) {
        cout << "Sorry, we could not find data on that year please try 1999-2021" << endl;
    }
}
void Map::choice5(string genre)
{
    choice5Helper(root, genre);
}
void Map::iteratePublic() {
    iterate(root);
}

