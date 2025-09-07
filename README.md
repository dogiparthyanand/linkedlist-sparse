This project is a little C++ program that demonstrates how a sparse matrix is stored in the Compressed Sparse Row (CSR) format.
It uses three arrays:
valArray → stores non-zero values
colPos → stores column positions
rowStart → at which stores begin each line.
I threw in a little helper function countNonZero() for practice as well.
How to Run
Save the files (main. cpp, sparse_matrix. cpp, and sparse_matrix. h) inside a folder.
Now open it in a terminal in that folder.
Compile using:

g++ -std=c++11 main.cpp -o linked_sparse


Run it:

./linked_sparse

Expected Output
Sparse Matrix (Linked List Form):
(0,2) -> 3
(1,0) -> 22
(2,1) -> 17
(2,3) -> 9
(3,3) -> 5
Total non-zero elements: 5