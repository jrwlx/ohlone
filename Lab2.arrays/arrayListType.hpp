//
//  arrayListType.hpp
//  Lab2
//
//  Created by Jarren Jose on 9/20/20.
//

#ifndef arrayListType_hpp
#define arrayListType_hpp

#include <stdio.h>
#include <stdint.h>
#include <iostream>

template <class elemType>
class arrayListType {
    
public:
    
    void removeAt(int location); //Lab 2, Question 1
    void removeAll(const elemType& removeItem); //Lab 2, Question 2
    const arrayListType<elemType>& operator = (const arrayListType<elemType>&);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType& item) const;
    void insertAt(int location, const elemType& insertItem);
    void insertEnd(const elemType& insertItem);
    void retrieveAt(int location, elemType& retItem) const;
    void replaceAt(int location, const elemType& repItem);
    void clearList();
    int seqSearch(const elemType& item) const;
    void insert(const elemType& insertItem);
    void remove(const elemType& removeItem);
    arrayListType(int size = 100); //constructor
    arrayListType(const arrayListType<elemType>& otherList); //copy constructor
    ~arrayListType(); //destructor
   
private:
    elemType *list; //array to hold the list elements
    int length; //to store the length of the list
    int maxSize; //to store the maximum size of the list
    
};

//Lab 2, Question 1
template<class elemType>
void arrayListType<elemType>::removeAt(int location) {
    if (location < 0 || location >= length) {
        std::cout << "Error" << std::endl;
    }
    else {
        int swap;
        swap = list[length-1];
        list[length-1] = list[location];
        list[location] = swap;
        length--;
    }
}

//Lab 2, Question 2
template<class elemType>
void arrayListType<elemType>::removeAll(const elemType& removeItem) {
    int loc;
    if (length == 0)
        std::cout << "Cannont delete from empty list" << std::endl;
    else {
        while ((loc = seqSearch(removeItem)) != -1)
            removeAt(loc);
    }
}


template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator= (const arrayListType<elemType>& otherList) {
    
    
    if (this != &otherList) {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        
        list = new elemType[ maxSize] ;
        assert(list != NULL);
        
    for (int i = 0; i < length; i++)
        list[i] = otherList.list[i];
    }
    return *this;
}

template <class elemType>
bool arrayListType<elemType>::isEmpty() const {
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const {
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const {
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const {
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const {
    for (int i = 0; i < length; i++) {
        std::cout << list[i] << " ";
        std::cout << std::endl;
    }
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const {
    return(list[location] == item);
}

template<class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem) {
    if (location < 0 || location >= maxSize) {
    std::cout << "The position of the item to be inserted is out of range" << std::endl;
    }
    else {
        if (length >= maxSize) {
            std::cout << "Cannot insert in a full list" << std::endl;
        }
        else {
            for (int i = length; i > location; i--)
            list[i] = list[i - 1];
            
            list[location] = insertItem;
    
            length++;
        }
    }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem) {
    if (length >= maxSize)
        std::cout << "Cannot insert in a full list" << std::endl;
    else {
        list[length] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType &retItem) const {
    if (location < 0 || location >= length)
        std::cout << "The location of item to be retrieved is out of range" << std::endl;
    else {
        retItem = list[location];
    }
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem) {
    if (location < 0 || location >= length)
        std::cout << "The location of item to be replaced is out of range" << std::endl;
    else {
        list[location] = repItem;
    }
}

template <class elemType>
void arrayListType<elemType>::clearList() {
    length = 0;
}
template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const {
    int loc;
    bool found = false;
    
    for (loc = 0; loc < length; loc++)
        if (list[loc] == item) {
            found = true;
            break;
    }
    if (found)
        return loc;
    else
        return -1;
    
}

template <class elemType>
void arrayListType <elemType>::insert(const elemType& insertItem) {
    int loc;
    if (length == 0)
        list[length++] = insertItem;
    else if (length == maxSize)
        std::cout << "Cannot insert in a full list" << std::endl;
    else {
        loc = seqSearch(insertItem);
        if (loc == -1)
            length++;
        else
            std::cout << "The item to be inserted is already in the list" << std::endl;
    }
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem) {
    int loc;
    if (length == 0)
        std::cout << "Cannont delete from empty list" << std::endl;
    else {
        loc = seqSearch(removeItem);
        if (loc != -1)
            removeAt(loc);
        else
            std::cout << "The item to be deleted is not in the list" << std::endl;
    }
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size) {
    if (size < 0) {
        std::cout << "The array size must be positive. Creating an array of size 100. " << std::endl;
        maxSize = 100;
    }
    else {
        maxSize = size;
    }
    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList) {
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    assert(list != NULL);
    for (int j = 0; j < length; j++)
        list[j] = otherList.list[j];
}

template <class elemType>
arrayListType<elemType>::~arrayListType() {
    delete [] list;
}

#endif /* arrayListType_hpp */
