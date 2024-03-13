#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

const int DEFAULT_CAPACITY = 5;

template <typename T>
struct List {
    T* elements;
    int size;
    int capacity;

    List() {
        size = 0;
        capacity = DEFAULT_CAPACITY;
        elements = new T[capacity];
    }

    void add(T& element) {
        if(size == capacity){
            int newCapacity = capacity * 2;
            T* newArray = new T[newCapacity];
        
            for (int i = 0; i < size; i++) {
                newArray[i] = elements[i];
            }
        delete[] elements;

        elements = newArray;
        capacity = newCapacity;
        }

        elements[size] = element;
        size++;
    }

    bool remove(int index) {

        if (index < 0 || index >= size || elements == nullptr) {
            return false;
        }

        for (int i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;

        if (size < capacity / 2 && capacity / 2 > DEFAULT_CAPACITY) {
        int newCapacity = capacity / 2;
        T* newElements = new T[newCapacity];

        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }

        delete[] elements;

        elements = newElements;
        capacity = newCapacity;
    }
        return true;
    }

    T get(int index) {
        return elements[index];
    }

    T* getAddressOf(int index) {
        return &elements[index];
    }

    T set(int index, T& element) {
        T oldElement = elements[index];
        elements[index] = element;
        return oldElement;
    }

    bool contains(T& element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        delete[] elements;
        elements = nullptr;
        size = 0;
        capacity = 0;
    }

    List<T> copy() {
        List<T> newList;

        for (int i = 0; i < size; i++) {
            newList.add(elements[i]);
        }

        return newList;
    }

    string toString() {
        string result = "[";
        for (int i = 0; i < size; i++) {
            result += elements[i];
            if (i < size - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    bool operator==(List<T>& other) {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }

        return true;
    }
};

#endif /* MYHEADER_H */