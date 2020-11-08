#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstdio>
#include <iostream>
#include <limits>

template <typename T>
class LinkedList
{
  public:
    LinkedList()
    {
    }

    LinkedList(const LinkedList<T>& other)
    {
        clone(other);
    }

    LinkedList& operator=(const LinkedList<T>& other)
    {
        if (&other == this) {
            return *this;
        }

        clear();
        clone(other);
        return *this;
    }

    T& operator[](size_t index)
    {
        if (index >= nodeCount) {
            //erro (lançar exceção)
        }

        Node* current = first;
        size_t currentIndex = 0;

        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        return current->value;
    }

    ~LinkedList()
    {
        clear();
    }

    void insert(T value)
    {
        if (first != nullptr) {
            Node* last = first;

            while (last->next != nullptr) {
                last = last->next;
            }

            Node* other = new Node();
            other->value = value;
            last->next = other;

            ++nodeCount;
        } else {
            first = new Node();
            first->value = value;
            ++nodeCount;
        }
    }

    void print()
    {
        if (size() == 0) {
            return;
        }

        Node* current = first;

        do {
            std::cout << current->value << std::endl;
            current = current->next;
        } while (current != nullptr);
    }

    void insertAt(size_t position, T value);

    //retorna a posição do elemento
    //ou infinito(std::numeric_limits<size_t>::infinity()) se não encontrar
    size_t search(T value);

    void removeAt(size_t position)
    {
        // 1.verificar se a posição é válida
        if (position >= size()) {
            return;
        }

        // 2.ir até o elemento
        size_t currentPosition = 0;
        Node* previousNode = nullptr;
        Node* currentNode = first;

        while (currentPosition < position) {
            previousNode = currentNode;
            currentNode = currentNode->next;

            currentPosition++;
        }

        if (position == 0) {
            first = currentNode->next;
            delete currentNode;
            --nodeCount;
        } else {
            previousNode->next = currentNode->next;
            delete currentNode;
            --nodeCount;
        }
    }

    size_t size()
    {
        return nodeCount;
    }

    void clear()
    {
        if (nodeCount == 0) {
            return;
        }

        Node* current = first;

        while (current != nullptr) {
            Node* tmp = current->next;
            delete current;
            current = tmp;
        }

        nodeCount = 0;
        first = nullptr;
    }

  private:
    struct Node
    {
        T value;
        Node* next;
        Node* prev;
    };

    void clone(const LinkedList& other)
    {
        if (other.nodeCount == 0) {
            return;
        }

        Node* current = other.first;

        while (current != nullptr) {
            insert(current->value);
            current = current->next;
        }
    }

    Node* first = nullptr;
    Node* last = nullptr;
    size_t nodeCount = 0;
};
#endif
