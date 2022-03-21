#include "BST.h"
typedef int TKey;
typedef int TValue;
#include <utility>
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);

TValue BST::search(TKey elem)
{
    TValue returnez = NULL_TVALUE;
    Node *currentNode;
    currentNode = this->root;
    if (currentNode == nullptr)return returnez;
    bool found = false;
    while (currentNode->info.first != NULL_TVALUE && found == false) { //caut pana il gasesc sau nu mai am ce cauta
        if (currentNode->info.first == elem) //verific daca nodul curent e ceea ce caut
        {
            found = true; TValue returnez = currentNode->info.second; return returnez;
        }
        else if (currentNode->info.first < elem) //daca elemtul pe care il caut este mai mare decat nodul curent atunci ma duc in dreapta
            currentNode = currentNode->right;
        else currentNode = currentNode->left; //altfel ma duc in stanga
    }
    return returnez;
}

Node* BST::insertRec(Node *currentNode, TElem elem)
{
    Node* nou = new Node(elem);
    if (currentNode == nullptr)return nou;
    if (currentNode->info.first > elem.first)currentNode->left = insertRec(currentNode->left, elem);
    else currentNode->right = insertRec(currentNode->right, elem);
    return currentNode;
    
}

Node* BST::insert(TElem elem)
{
    return insertRec(this->root, elem);
}

TElem BST::getMinimum()
{
    Node* current = this->root;
    while (current->left != nullptr) {
			current = current->left;
		}
	return current->info;
}

BST::BST()
{
    this->root = nullptr;
}

TValue BST::removeRec(Node* root , TKey elem)
{
    TKey returnez = NULL_TVALUE;
    if (root == nullptr) {
        return returnez;
    }
    //daca elementul pe care il cautam este mai mic decat nodul curent mergem in stanga
    if (elem < root->info.first) {
        removeRec(root->left, elem);
    }
    //dreapta
    else if (elem > root->info.first) {
        removeRec(root->right, elem);
    }
    // tot mergem recursiv pana il gasim, daca il gasim intram in else-ul asta
    else {
        TKey returnez = root->info.second;
        // cazul 1: nodul nu are urmasi
        if (root->left == nullptr && root->right == nullptr)
        {
            // deallocate the memory and update root to null
            delete root;
            root = nullptr;
        }

        // cazul 2: nodul are doi urmasi 
        else if (root->left && root->right)
        {
            // find its inorder predecessor node
            Node* predecessor = findMaximumNode(root->left);

            // copy value of the predecessor to the current node
            root->info = predecessor->info;

            // recursively delete the predecessor. Note that the
            // predecessor will have at most one child (left child)
            removeRec(root->left, predecessor->info.first);
        }

        // cazul 3: nodul are doar un singur urmas
        else {
            // choose a child node
            Node* child = (root->left) ? root->left : root->right;
            Node* curr = root;

            root = child;

            // deallocate the memory
            delete curr;
        }
    }
    return returnez;

}

TValue BST::remove(TKey elem)
{
    return removeRec(this->root, elem);
    
    
}

Node* BST::findMaximumNode(Node* ptr)
{
    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }
    return ptr;
}
