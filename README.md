# BFS-DFS-File-System
Data Science student at UKFCET with a passion for technology and innovation
File System Representation and Search Using BFS and DFS

Aim

To represent a file system as a graph using an adjacency matrix and search for a specified file using Breadth-First Search (BFS) and Depth-First Search (DFS).

Objectives

- Represent files and directories as graph nodes.
- Store connections using an adjacency matrix.
- Implement BFS and DFS traversal algorithms.
- Display traversal order and determine whether the target file is found.

Algorithm

BFS

1. Initialize a queue and mark all nodes as unvisited.
2. Insert the starting node into the queue.
3. Remove a node from the queue and display it.
4. Mark its unvisited adjacent nodes as visited and insert them into the queue.
5. Repeat until the queue is empty.
6. Report whether the target file was found.

DFS

1. Mark the starting node as visited and display it.
2. Check its adjacent nodes.
3. Recursively visit each unvisited adjacent node.
4. Continue until no unvisited adjacent nodes remain.
5. Report whether the target file was found.

Sample Input

Number of nodes: 5

Node names: Root, Documents, Pictures, Notes, Photo

Number of connections: 4

Connections:

- 0 1
- 0 2
- 1 3
- 2 4

Starting directory: Root

Target file: Photo

Sample Output

BFS Traversal: Root Documents Pictures Notes Photo

BFS Result: Target file found

DFS Traversal: Root Documents Notes Pictures Photo

DFS Result: Target file found

Result

The file system was represented using an adjacency matrix, and BFS and DFS were implemented successfully to traverse the graph and search for the target file.

Language

C

Source Code

See "main.c" in this repository.
