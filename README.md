# Alejandro Parana

# Date: 3/20/2016

# Implementing Word Count in Perl, Java, and C++

Date: 3/20/2016

Programming Language Structures Project

Description: Implementation of a word count program in C++, Java, and Perl.

For C++, a custom HashMap data structure implementation is written.

```
int h = 0;
for(int i = 0; i < k.length(); i++)
      h = 29 * h + k[i];
h %= tblSize; 
if(h < 0)            
     h += tblSize;
```
The tableSize is a prime number 227 so that keys can be distributed evenly.  The hash function loops through every character of the String key, using Horner’s rule to compute h(String), the ASCII value of every character in the key is added to the current hash value times the prime number 29

# Comparison Between Languages

Perl’s built in hashes are by far the simplest to use, when declaring a hash you just have to know about the context of the variable you’re working with. For example, using the % symbol, and when adding a value to a hash you use the scalar symbol $ and the key inside {} and assign it a value. You can also increment the value inside a certain key using the ++ operator, which gives great readability and writability when working with associative arrays.

Implementing associative arrays in Java is also fairly simple if you know how the HashMap class works after reading the documentation and what operations you can perform. Using the HashMap class may have some restrictions, but many of the things you have to do in C++ yourself are already done for you in Java automatically.

Implementing associative arrays in C++ is a little more complicated because youneed to understand how pointers are assigned and dereferenced, you may need to know to create a pointer to a pointer, there is no garbage collection, and you have to ensure you clean up any unused variables so you don’t have problems like dangling pointers.
