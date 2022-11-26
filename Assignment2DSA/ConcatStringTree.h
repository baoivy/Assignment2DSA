#ifndef __CONCAT_STRING_TREE_H__
#define __CONCAT_STRING_TREE_H__

#include "main.h"

class ReducedConcatStringTree; //forward declaration
class LitStringHash;
int keyGenerator();

class ConcatStringTree {
public: 
    class BSTNode; //forward declaration
    class ParentsTree; //forward declaration
protected:
    BSTNode* root;
    int size; //Capacity

    //Method for BST Tree
    void preOrderString(BSTNode* root, string& ) const;
    void inOrdertoString(BSTNode* root, string& ) const;
    BSTNode* inOrderReverse(BSTNode* root) const;
    BSTNode* preOrderSubString(BSTNode* root, int from, int to) const;
    void updateLeftL(BSTNode* root) const;
    void clearParents(BSTNode* root);
    bool checkLeaf(BSTNode* root);

public:
    ConcatStringTree(const char* s);
    ConcatStringTree(BSTNode* root, int size) : root(root), size(size){}
    ConcatStringTree(){} //Copy Construtor
    int length() const;
    char get(int index);
    int indexOf(char c);
    string toStringPreOrder() const;
    string toString() const;
    ConcatStringTree concat(const ConcatStringTree & otherS) const;
    ConcatStringTree subString(int from, int to) const;
    ConcatStringTree reverse() const;
    ~ConcatStringTree();

    int getParTreeSize(const string & query) const;
    string getParTreeStringPreOrder(const string & query) const;

    class ParentsTree {
    public:
        class AVLNode; //forward declaration
    private:
        AVLNode* root;
        int count;
        //Implementation for AVL Tree
        int height(AVLNode* node);
        int getBalance(AVLNode* node);
        AVLNode* rightRotate(AVLNode* node);
        AVLNode* leftRotate(AVLNode* node);
        AVLNode* maxValue(AVLNode* node);
        void PreOrderTraversal(AVLNode* root, string&) const;
        void clear(AVLNode* root);
        AVLNode* insert(AVLNode* root, ConcatStringTree::BSTNode* node);
        AVLNode* remove(AVLNode* root, ConcatStringTree::BSTNode* node, bool &canDelete);

    public:
        ParentsTree() : root(nullptr), count(0) {}
        int size() const;
        string toStringPreOrder() const;
        void insertNode(ConcatStringTree::BSTNode* node);
        void deleteNode(ConcatStringTree::BSTNode* node);
        ~ParentsTree();

        class AVLNode {
        private:
            ConcatStringTree::BSTNode* node;
            int key; //Left length string
            AVLNode* left;
            AVLNode* right;
            int height;
            friend class ParentsTree;

        public:
            AVLNode(ConcatStringTree::BSTNode* node) : node(node), key(node->key), height(1), left(nullptr), right(nullptr) {}
        };
    };

    class BSTNode {
    protected:
        int key;
        int leftLength; //Left length string
        int lengthStr;
        int numRef;
        bool RCST;
        string data;
        BSTNode* left;
        BSTNode* right;
        ParentsTree *parent_node;
        friend class ConcatStringTree;
        friend class ParentsTree;
        friend class LitStringHash;
        friend class ReducedConcatStringTree;
    public:
        BSTNode() : data(""), left(nullptr), right(nullptr), numRef(0), RCST(false), key(keyGenerator()) {
            this->parent_node = new ParentsTree();
        }
        BSTNode(string data, int leftLength) : leftLength(leftLength), key(keyGenerator()), left(nullptr), right(nullptr)
        ,RCST(false), data(data), numRef(0) {
            this->lengthStr = (int)data.length();
            this->parent_node = new ParentsTree();
        }
        BSTNode(string data, int leftLength, BSTNode* left, BSTNode* right) : leftLength(leftLength), key(keyGenerator()), left(left), right(right)
        ,RCST(false), data(data), numRef(0) {
            this->lengthStr = (int)data.length();
            this->parent_node = new ParentsTree();
        }
        ~BSTNode() {
            delete this->parent_node;
            this->parent_node = nullptr;
        }
    };
};

class ReducedConcatStringTree; // forward declaration

class HashConfig {
private:
    int p;
    double c1, c2;
    double lambda;
    double alpha;
    int initSize;

    friend class LitStringHash;

public:
    HashConfig() {}
    HashConfig(int p, double c1, double c2, double lambda, double alpha, int initSize) : p(p), c1(c1), c2(c2)
    ,lambda(lambda), alpha(alpha), initSize(initSize){}
};

class LitStringHash {
private:
    class HashItem; //forward declaration
    HashItem* arr;
    HashConfig config;
    int size;
    int capacity;
    int idx_last;
    bool isDeleted;

    int hashFunc(string s, int, int);
    void reHash();
    ConcatStringTree::BSTNode* insertHash(string s);
    ConcatStringTree::BSTNode* searchHash(string s);
    void deleteHash(ConcatStringTree::BSTNode* node);
    friend class ReducedConcatStringTree;

public:
    LitStringHash(const HashConfig& hashConfig);
    int getLastInsertedIndex() const;
    string toString() const;
    ~LitStringHash();

private:
    class HashItem {
    private:
        ConcatStringTree::BSTNode* node;
        bool isEmpty;
        friend class LitStringHash;
    public:
        HashItem() : node(nullptr), isEmpty(true){}
    };
};

class ReducedConcatStringTree : public ConcatStringTree {
public:
    LitStringHash* litStringHash;
    ReducedConcatStringTree(BSTNode* root, int size, LitStringHash*& litStringHash) {
        this->root = root;
        this->size = size;
        this->litStringHash = litStringHash;
    }
    ReducedConcatStringTree(const char* s, LitStringHash*& litStringHash);
    ReducedConcatStringTree concat(ReducedConcatStringTree& otherS);
    //ReducedConcatStringTree reverse();
    //ReducedConcatStringTree subString(int from, int to);
    ~ReducedConcatStringTree();
};

#endif // __CONCAT_STRING_TREE_H_