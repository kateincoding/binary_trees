# Binary trees
![binary_trees](https://upload.wikimedia.org/wikipedia/commons/f/fd/AVL_Tree_Example.gif)

 Binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

## Resources
Read or watch:

Binary tree (note the first line: Not to be confused with B-tree.)
Data Structure and Algorithms - Tree
Tree Traversal
Binary Search Tree
Data structures: Binary Tree

## Learning Objectives

What is a binary tree
What is the difference between a binary tree and a Binary Search Tree
What is the possible gain in terms of time complexity compared to linked lists
What are the depth, the height, the size of a binary tree
What are the different traversal methods to go through a binary tree
What is a complete, a full, a perfect, a balanced binary tree

## Data structures

### Basic Binary Tree
```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Binary Search Tree
```
typedef struct binary_tree_s bst_t;
```

### AVL Tree
```
typedef struct binary_tree_s avl_t;
```

### Max Binary Heap
```
typedef struct binary_tree_s heap_t;
```

## Print function
[print_function](https://github.com/holbertonschool/0x1C.c)

```
                           .----------------------(006)-------.
                      .--(001)-------.                   .--(008)--.
                 .--(-02)       .--(003)-------.       (007)     (009)
       .-------(-06)          (002)       .--(005)
  .--(-08)--.                           (004)
(-09)     (-07)
```

## Tasks

##|File|Description
---|---|---
0|[New Node](0-binary_tree_node.c)|Write a function that creates a binary tree node
1|[Insert left](1-binary_tree_insert_left.c)|Write a function that inserts a node as the left-child of another node

## Authors:
* Katherine Soto | <img alt="GitHub" width="26px" src="https://raw.githubusercontent.com/github/explore/78df643247d429f6cc873026c0622819ad797942/topics/github/github.png" />[GitHub](https://github.com/kateincoding)
* Renato León |   <img alt="GitHub" width="26px" src="https://raw.githubusercontent.com/github/explore/78df643247d429f6cc873026c0622819ad797942/topics/github/github.png" /> [GitHub](https://github.com/rennleon)
