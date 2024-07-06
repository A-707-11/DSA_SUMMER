#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
} Product;

typedef struct NodeType {
    Product item;
    struct NodeType *left, *right;
} NodeType, *NodePtr;

typedef struct QueueNode {
    NodePtr treeNode;
    struct QueueNode *next;
} QueueNode, *QueueNodePtr;

typedef struct {
    QueueNodePtr front, rear;
} QueueType;

// Queue functions
void initQueue();
int isEmpty();
void enqueue();
NodePtr dequeue();
// BST functions
void addElement();
void deleteElement();
void travBFS();
void prefixDFS();
void postfixDFS();
void infixDFS();

#endif
