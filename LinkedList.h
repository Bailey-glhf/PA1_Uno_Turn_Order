/*******************************************************************************
* CS210-16 – Fall 2026
* Project name: PA1_Uno_Turn_Order / LinkedList.h Class
* Developer: Emily Bailey
* 10/11/26
* Description: Linked List will be able to perform the following functions :
* addFront, addBack, addAnywhere, deleteFront, deleteBack, deleteAnywhere
* reverse, concat, getFront, isEmpty, size, print. Code will be capable of
* completing functions both with and without a tail pointer. Without tail
* pointer is set default, with tail pointer complete functions commented out.
******************************************************************************/

#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}
    //LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}        => WITH TAIL

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        /********************* WITH TAIL *********************
        if (tail_ == nullptr) {
            tail_ = fresh;          // if this is first item in list both head and tail = fresh
        }
        ********************** WITH TAIL *********************/
        ++size_;
    }

    void addBack(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        if (head_ == nullptr) {
            head_ = fresh;
        }
        else {
            Node<T>* current = head_;
            while (current->next != nullptr) {  // walks to end of the list
                current = current->next;
            }
            current->next = fresh;
        }
        ++size_;
        /********************* WITH TAIL *********************
        Node<T>* fresh = new Node<T>(value);
        if (tail_ == nullptr) {
            head_ = fresh;
            tail_ = fresh;
        } else {
            tail_->next = fresh;
            tail_ = fresh;
        }
        ++size_;
        ********************** WITH TAIL *********************/
    }

    void addAnywhere (int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 0)
            addFront(value);
        else if (position == size_)
            addBack(value);
        else {
            Node<T>* current = head_;
            Node<T>* fresh = new Node<T>(value);
            for (int i = 0; i < position - 1; ++i) { // for loop finds the node before desired position
                current = current->next;
            }
            fresh->next = current->next;            // directs fresh's next pointer to where ever current's next pointer is directed
            current->next = fresh;                  // directs current's next pointer to fresh node
                                                    // this puts the order to current -> fresh -> next node that current was originally pointed to
            size_++;
        }
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = doomed->next;
        /********************* WITH TAIL *********************
        if (head_ == nullptr) {
            tail_ = nullptr;            // list is empty again
        }
        ********************** WITH TAIL *********************/
        delete doomed->data;
        delete doomed;
        --size_;
    }

    void deleteBack() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        if (head_->next == nullptr) {
            deleteFront();
            return;
        }
        Node<T>* doomed = head_;
        while (doomed->next->next != nullptr) {
            doomed = doomed->next;
        }
        delete doomed->next->data;
        delete doomed->next;
        doomed->next = nullptr;
        --size_;

        /********************* WITH TAIL *********************
         *replace entire function with the following =>
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        if (head_ == tail_) {
            deleteFront();
            return;
        }

        Node<T>* doomed = head_;
        while (doomed -> next != tail_) {
            doomed = doomed->next;
        }

        delete doomed->next->data;
        delete doomed->next;

        tail_ = doomed;
        tail_->next = nullptr;
        --size_;
        ********************** WITH TAIL *********************/
    }

    void deleteAnywhere (int position) override {
        if (position < 0 || position > (size_- 1)) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 0) {
            deleteFront();
        }
        else if (position == (size_ - 1)) {
            deleteBack();
        }
        else {
            Node<T>* current = head_;
            for (int i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            Node<T>* doomed = current->next;
            current->next = current->next->next;
            delete doomed->data;
            delete doomed;
            --size_;
        }
    }

    void reverse() override {
        if (size_ <= 1) {
            return;
        }
        Node<T>* previousOne = nullptr;
        Node<T>* current = head_;
        Node<T>* nextOne = nullptr;

        //tail_ = head_;                            => WITH TAIL
        while (current != nullptr) {
            nextOne = current->next;
            current->next = previousOne;
            previousOne = current;
            current = nextOne;
        }
        head_ = previousOne;

    }

    void concat (List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>* >(other);
        if ( otherList == nullptr ) {
            std::cout << "Incompatible List Types." << std::endl;
            return;
        }
        if ( otherList->isEmpty() ) {
            return;
        }
        if ( isEmpty() ) {
            head_ = otherList->head_;
            // tail_ = otherList->tail_;            => WITH TAIL
        }
        else {
            Node<T>* current = head_;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = otherList->head_;
        }
        /********************* WITH TAIL *********************
        *replace previous else with this one =>
        else {
            tail_->next = otherList->head_;
            tail_ = otherList->tail_;
        }
        ********************** WITH TAIL *********************/
        size_ += otherList->size_;

        otherList->size_ = 0;           // avoids dangling pointers
        otherList->head_ = nullptr;
        //otherList->tail_ = nullptr;               => WITH TAIL
    }

    T* getFront() const override {
        if (head_ == nullptr) {
            return nullptr;
        }
        return head_->data;
    }

    bool isEmpty() const override {
        return head_ == nullptr;
    }

    int size() const override {
        return size_;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
    //Node<T>* tail_;                               => WITH TAIL
    int size_;
};