# DSA-CPP

A beginner-friendly collection of **Data Structures and Algorithms (DSA)** implementations in C++.

The repository is organized topic-by-topic, with three programs for each major topic. Programs progress from fundamentals to classic and more advanced algorithmic applications.

## Repository Structure

```text
DSA-CPP/
├── 01_Array/
├── 02_Linked_List/
├── 03_Stack/
├── 04_Queue/
├── 05_Recursion/
├── 06_Searching/
├── 07_Sorting/
├── 08_Hashing/
├── 09_Tree/
├── 10_BST/
├── 11_Heap/
├── 12_Graph/
├── 13_Greedy/
├── 14_Dynamic_Programming/
├── 15_Backtracking/
├── 16_Trie/
├── 17_Advanced_Graph/
├── 18_Advanced_DP/
├── 19_Segment_Tree/
└── README.md
```

## Topics and Programs

### 01. Array
- Basic array operations
- Search and update
- Sorting and statistics

### 02. Linked List
- Create and display
- Insert and delete
- Search, reverse and middle element

### 03. Stack
- Stack using array
- Stack operations
- Stack applications

### 04. Queue
- Queue using array
- Circular queue
- Deque

### 05. Recursion
- Factorial and sum
- Fibonacci and power
- Recursive binary search and Tower of Hanoi

### 06. Searching
- Linear search
- Binary search
- First and last occurrence

### 07. Sorting
- Bubble sort
- Selection and insertion sort
- Merge sort and quick sort

### 08. Hashing
- Hash table with linear probing
- Hash table with chaining
- Frequency counting

### 09. Tree
- Binary tree traversal
- Tree height and node count
- Level-order traversal

### 10. Binary Search Tree
- Insert and search
- Minimum, maximum and delete
- Predecessor and successor

### 11. Heap
- Max heap
- Min heap
- Heap sort

### 12. Graph
- Graph representation
- BFS and DFS
- Dijkstra shortest path

### 13. Greedy Algorithms
- Activity selection
- Fractional knapsack
- Job sequencing with deadlines

### 14. Dynamic Programming
- Fibonacci using DP
- 0/1 Knapsack
- Longest Common Subsequence (LCS)

### 15. Backtracking
- N-Queens
- Sudoku solver
- Subset sum

### 16. Trie
- Trie insert and search
- Prefix search
- Trie deletion

### 17. Advanced Graph
- Topological sorting
- Floyd-Warshall all-pairs shortest path
- Kruskal Minimum Spanning Tree

### 18. Advanced Dynamic Programming
- Coin change
- Longest Increasing Subsequence (LIS)
- Matrix chain multiplication

### 19. Segment Tree
- Range sum query
- Range minimum query
- Range sum query with point update

## Learning Path

Recommended order:

1. Array
2. Linked List
3. Stack
4. Queue
5. Recursion
6. Searching
7. Sorting
8. Hashing
9. Tree
10. Binary Search Tree
11. Heap
12. Graph
13. Greedy Algorithms
14. Dynamic Programming
15. Backtracking
16. Trie
17. Advanced Graph
18. Advanced Dynamic Programming
19. Segment Tree

## How to Compile

Using g++:

```bash
g++ filename.cpp -o program
./program
```

On Windows:

```bash
g++ filename.cpp -o program.exe
program.exe
```

Example:

```bash
g++ 17_Advanced_Graph/03_kruskal_mst.cpp -o kruskal
./kruskal
```

## Notes

- All programs use standard C++.
- Each source file is independently executable.
- Programs are written clearly for learning and GitHub practice.
- Graph programs generally use zero-based vertex numbering.
- Trie examples expect lowercase English letters.
- Segment Tree examples use zero-based array indices.

## Future Topics

Possible future additions include:

- Prim's MST
- Bellman-Ford
- Strongly Connected Components
- Disjoint Set Union
- Advanced Trie applications
- Fenwick Tree / Binary Indexed Tree
- Sparse Table
- String algorithms
- KMP
- Rabin-Karp
- Advanced graph problems
- Advanced dynamic programming
- Competitive programming patterns
