#pragma once

const int SIZE{ 10 };

struct ListNode {
    int index;
    int data;
};

struct IndexedList {
    ListNode array[SIZE +1];  
    int headIndex;
    int countItems;

    IndexedList();
    ~IndexedList();

    void printDataList();
    void addItem(int data);
    void deleteItemByIndex(int index);
    void deleteItemByData(int data);
    bool isEmpty();
    bool isFull();
    int searchFreeIndex();
    int searchItemIndex(int value);
    void printReverse(int current);

};


