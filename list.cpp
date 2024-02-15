#include "list.h"

#include <iostream>



IndexedList::IndexedList()
{
    headIndex = 0; countItems = 0;
    for (int i = 1; i <= SIZE; ++i) {
        array[i].index = -1;
    }
}

IndexedList::~IndexedList()
{
}

void IndexedList::printDataList() {
    printReverse(headIndex);
    std::cout << std::endl;
}

void IndexedList::printReverse(int current) {
    if (current != 0) {
        printReverse(array[current].index);
        std::cout << array[current].data << " ";
    }
}

void IndexedList::addItem(int data)
{
    int newIndex = searchFreeIndex();
    array[newIndex].index = headIndex;
    array[newIndex].data = data;
    headIndex = newIndex;
    countItems++;
}

void IndexedList::deleteItemByIndex(int index)
{
    if (index < 0 || index >= SIZE) {
        std::cerr << "Invalid index." << std::endl;
        return;
    }

    int current = headIndex;
    int prev = 0;

    while (current != 0 && current != index + 1) {
        prev = current;
        current = array[current].index;
    }

    if (current != 0) {
        if (prev != 0) {
            array[prev].index = array[current].index;
        }
        else {
            headIndex = array[current].index;
        }

        array[current].index = -1;
        countItems--;
    }
}


void IndexedList::deleteItemByData(int data)
{
    int current = headIndex;
    int prev = 0;

    while (current != 0 && array[current].data != data) {
        prev = current;
        current = array[current].index;
    }

    if (current != 0) {
        // Element found, remove it
        if (prev != 0) {
            array[prev].index = array[current].index;
        }
        else {
            // Removing the head element
            headIndex = array[current].index;
        }

        // Mark the removed element as free
        array[current].index = -1;
        countItems--;

    }
}

bool IndexedList::isEmpty()
{
    return headIndex == 0;
}

bool IndexedList::isFull()
{
    return searchFreeIndex() == -1;
}

int IndexedList::searchFreeIndex()
{
    for (int i = 0; i <= SIZE; ++i) {
        if (array[i].index == -1) {
            return i;
        }
    }
    return -1;
}

int IndexedList::searchItemIndex(int value)
{
    int current = headIndex;

    while (current != 0) {
        if (array[current].data == value) {
            return current;
        }
        current = array[current].index;
    }

    return -1;
}

