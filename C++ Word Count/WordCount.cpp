// Author: Alejandro Parana
// Date: 3/20/2016
// WordCount C++

using namespace std;
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h> 
const int tblSize = 227;

class ListNode {
    private: ListNode *next;
    private: std::string k;
    private: int v;
    
    public: ListNode(std::string k, int v) {
        this -> next = NULL;
        this -> k = k;
        this -> v = v;   
    }
    
    public: ListNode *getNext() {
        return next;
    }
    public: void setNext(ListNode *next) {
        this -> next = next;
    }
    public: std::string getK() {
        return k;
    }
    public: int getV() {
        return v;
    }
    public: void setV(int v) {
        this -> v = v;
    }
};

class HashMap {
    private: ListNode **n;
    
    public: HashMap() {
        n = new ListNode*[tblSize];
    }
    
    public: void put(std::string k, int v) {
        int h = 0;
        for(int i = 0; i < k.length(); i++) 
            h = 29 * h + k[i];
        h %= tblSize;
        if(h < 0)
            h += tblSize;
        
        if (n[h] == NULL) {
            n[h] = new ListNode(k, v);
        }
        else {
            ListNode *node = n[h];
            while (node -> getNext() != NULL) {
                node = node -> getNext();
            }
            if (node -> getK() == k) {
                node -> setV(v);
            }
            else {
                node -> setNext(new ListNode(k, v));
            }
        }
    }
    public: int get(std::string k) {
        int h = 0;
        for(int i = 0; i < k.length(); i++) 
            h = 29 * h + k[i];
        h %= tblSize; 
        if(h < 0)
            h += tblSize;
    
        if (n[h] == NULL) {
            return -1;
        }
        else {
            ListNode *node = n[h];
            while (node -> getK() != k && node != NULL) {
                node = node -> getNext();
            }
            if (node == NULL) {
                return -1;
            }
            else {
            	int result = node -> getV();
                return result;
            }
        }
    }
};

void toUpperCase(char* lo) {
  while (*lo = std::toupper(*lo))
    ++lo;
}

int main() {
    const char* FILE_NAME = "words.txt";

    HashMap map;
    std::string line;
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "File not found";
        return -1;
    }
    while(getline(file, line)) {
        char *str = new char[line.size() + 1];
        str[line.size()] = 0;
        memcpy(str, line.c_str(), line.size());
        toUpperCase(str);
        char * t;
        t = strtok (str, " .");
        while(t != NULL) {
            if (map.get(t) != -1) {
                int o = map.get(t);
                o++;
                map.put(t, o);
            }
            else {
                map.put(t, 1);
            }
            t = strtok (NULL, " .");
        }
    }
    file.close();
    
    cout << "========RESULTS===========\n";
    ifstream file2(FILE_NAME);
    if (!file2) {
        cout << "File not found";
        return -1;
   }
   while(getline(file2, line)) {
        char *str = new char[line.size() + 1];
        str[line.size()] = 0;
        memcpy(str, line.c_str(), line.size());
        toUpperCase(str);
        char * t;
        t = strtok (str, " ."); 
        // Print unique results
        while(t != NULL) {
            if (map.get(t) != -1) {
              cout << t << " is used " << map.get(t) << " times.\n";
              map.put(t, -1);
            }
            t = strtok (NULL, " .");
        }
    }
    file2.close();
    cout << "==========================";
}

