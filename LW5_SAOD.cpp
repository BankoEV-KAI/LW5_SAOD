// ЛР 5 по САОДу задание 1.3.3 - линейный список на базе массива с указателями-индексами
//
#include "list.h"
#include "menu.h"
#include <iostream>


//вообще готова, но было бы неплохо бахнуть рандом заполнение всего массива 

int main()
{
    setlocale(LC_ALL, "ru");
    IndexedList intList;
    int data{ 0 }, operation{ 0 }, index{ 0 };
    while (true) {
        printMenu(1);
        enteringNumber(0, 5, operation);
        switch (operation)
        {
        case 0:
            return 0;
        case 1:
            std::cout << (intList.isEmpty() ? "Список пуст." : "Список не пуст.") << std::endl;
            break;
        case 2:
            enteringNumber(1, 100, data);
            intList.addItem(data);
            intList.printDataList();
            break;
        case 3:
            printMenu(2);
            enteringNumber(0, 2, operation);
            switch (operation)
            {
            case 0:
                break;
            case 1:
                std::cout << "Ввод индекса элемента для удаления: " << std::endl;
                enteringNumber(0, intList.countItems - 1, index);
                intList.deleteItemByIndex(index);
                break;
            case 2:
                std::cout << "Ввод значения элемента для удаления: " << std::endl;
                enteringNumber(1, 100, data);
                intList.deleteItemByData(data);
                break;
            default:
                break;
            }
            intList.printDataList();
            break;
        case 4:
            printMenu(3);
            enteringNumber(0, 2, operation);
            switch (operation)
            {
            case 0:
                break;
            case 1:
                intList.printDataList();
                std::cout << "Ввод индекса элемента для поиска: " << std::endl;
                int index;
                enteringNumber(0, SIZE - 1, index);
                std::cout << "Значение элемента по заданному индексу: " << 10 << std::endl;
                break;
            case 2:
                intList.printDataList();
                std::cout << "Ввод значения элемента для поиска: " << std::endl;
                enteringNumber(1, 100, data);
                index = intList.searchItemIndex(data);
                (index != -1 && index != -2) ? std::cout << "Элемент найден на позиции: " << index << std::endl : std::cout << "Искомый элемент отсутствует в списке." << std::endl;
                break;
            default:
                break;
            }
            break;
        case 5:
            intList.printDataList();
            break;

        default:
            break;
        }
    }

    
    return 0;
}

