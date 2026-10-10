#pragma once
#include <iostream>
#include "List.h"

// Solution file. Lab 3's ArrayList plus addBack, getFront, isEmpty, size.

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList() : size_(0) {}

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void addBack(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        data_[size_] = value;       // no shifting needed at the back
        ++size_;
    }

    void addAnywhere (int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == CAPACITY || size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        if (position == 0)
            addFront(value);
        else if (position == size_)
            addBack(value);
        else {
            for ( int i = size_; i > position; i--) {   // shifts all list values to the right of position over
                data_[i] = data_[i - 1];
            }
            data_[position] = value;                    // inserts value into position without overwriting
            ++size_;
        }
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void deleteBack() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[size_ - 1];
        --size_;
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
            delete data_[position];
            for (int i = (position); i < size_ - 1; ++i) {
                data_[i] = data_[i + 1];
            }
            --size_;
        }
    }

    void reverse() override {
        if (size_ <= 1) {
            return;
        }

        for (int i = 0; i < size_/2; ++i) {
            T* temp = data_[i];
            data_[i] = data_[size_ - 1 - i];
            data_[size_ - 1 - i] = temp;
        }
    }

    void concat (List<T>* other) override {
        ArrayList<T>* otherList = dynamic_cast<ArrayList<T>* >(other);
        if ( otherList == nullptr ) {
            std::cout << "Incompatible List Types." << std::endl;
            return;
        }

        if (size_ +otherList->size_ > CAPACITY) {
            std::cout << "Not enough room to merge lists." << std::endl;
            return;
        }

        for (int i = 0; i < otherList->size_; ++i) {
            data_[size_+ i] = otherList->data_[i];
        }
        size_ += otherList->size_;
        otherList->size_ = 0;
    }

    T* getFront() const override {
        if (size_ == 0) {
            return nullptr;
        }
        return data_[0];
    }

    bool isEmpty() const override {
        return size_ == 0;
    }

    int size() const override {
        return size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) {
                return true;
            }
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
