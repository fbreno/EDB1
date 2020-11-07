#pragma once
#include <cstdio>
#include <iostream>
#include <limits>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node *next;
    };

    Node *first = nullptr;
    size_t nodeCount = 0;

    void clear()
    {
        if (nodeCount == 0)
        {
            return;
        }

        Node *current = first;

        while (current != nullptr)
        {
            Node *tmp = current->next;
            delete current;
            current = tmp;
        }
    }

public:
    LinkedList()
    {
    }

    ~LinkedList()
    {
        clear();
    }

    LinkedList(const LinkedList &other)
    {
        clone(other);
    }

    void clone(const LinkedList<T> &other)
    {
        if (other.nodeCount == 0)
        {
            return;
        }

        Node *current = other.first;

        while (current != nullptr)
        {
            insert(current->value);
            current = current->next;
        }
    }

    LinkedList &operator=(const LinkedList<T> &other)
    {
        if (&other == this)
        {
            return *this;
        }

        clear();
        clone(other);
        return *this;
    }

    T operator[](size_t index) 
    {
        if (index>=nodeCount)
        {
            //erro
        }
        Node* current = first;
        size_t currentIndex=0;

        while (currentIndex<index)
        {
            current=current->next;
            currentIndex++;
        }
        
        return *current;
        
    }

    void insert(T value)
    {
        if (first != nullptr)
        {
            Node *last = first;

            while (last->next != nullptr)
            {
                last = last->next;
            }

            Node *other = new Node();
            other->value = value;
            last->next = other;

            ++nodeCount;
        }
        else
        {
            first = new Node();
            first->value = value;
            ++nodeCount;
        }
    }

    void print()
    {
        if (size() == 0)
        {
            return;
        }

        Node *current = first;

        do
        {
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
        if (position >= size())
        {
            return;
        }

        // 2.ir até o elemento
        size_t currentPosition = 0;
        Node *previousNode = nullptr;
        Node *currentNode = first;

        while (currentPosition < position)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;

            currentPosition++;
        }

        if (position == 0)
        {
            first = currentNode->next;
            delete currentNode;
            --nodeCount;
        }
        else
        {
            previousNode->next = currentNode->next;
            delete currentNode;
            --nodeCount;
        }
    }

    size_t size()
    {
        return nodeCount;
    }
};