# Character-Tree-Serialization
Write a program to create a custom tree data structure using linked list (tree of characters), serialize it and store it in a file and deserialize it and load it back to data structure. 

for running this program all the files should be in same directory 
let all files are on Desktop
Steps to be followed to run program:
a] This program contains two modules 'CREATE' and 'LOAD', so two times we have to run program
b] Firstly create an input file named input2.csv on desktop
c] Then an empty serialized.csv file to store serialized data of tree
d] Make program file as sadp.cpp
e] Then open terminal in same directory and run command g++ sadp.cpp
f] Then run command ./a.out create input2.csv serialised.csv
    this will create tree by taking data from input2.csv, prints the preorder of tree and then serialises data and stores in       serialised.csv
g] Then run command ./a.out load serialised.csv. 
    this command will deserialise data from file and prints tree in preorder.
    
    Now you can see that before serialization, after deserialization and data in serialised.csv file are in same order.
    Serialised.csv file contains data and . where there node is null. For more refer too screenshots
    
