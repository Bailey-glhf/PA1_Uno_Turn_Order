/*******************************************************************************
* CS210-16 – Fall 2026
* Project name: PA1_Uno_Turn_Order / List.h Class
* Developer: Emily Bailey
* 10/11/26
* Description: Abstract base class for ArrayList and LinkedList Data Structures
******************************************************************************/
#pragma once
#include <memory>

template <typename T>
class List {
public:
    virtual ~List() = default;

    virtual void addFront(T* value) = 0;
    virtual void addBack(T* value) = 0;
    virtual void addAnywhere(int position, T* value) = 0;       //New for UNO

    virtual void deleteFront() = 0;
    virtual void deleteBack() = 0;
    virtual void deleteAnywhere(int position) = 0;              //New for UNO

    virtual void reverse() = 0;                                 //New for UNO
    virtual void concat(List<T>* other) = 0;                    //New for UNO

    virtual T* getFront() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool search(T* value) const = 0;

    virtual void print() const = 0;
    virtual int size() const = 0;
};

#include "ArrayList.h"
#include "LinkedList.h"

template <typename T>
std::unique_ptr<List<T>> makeList() {
    return std::make_unique<LinkedList<T>>();
    // return std::make_unique<ArrayList<T>>();
}