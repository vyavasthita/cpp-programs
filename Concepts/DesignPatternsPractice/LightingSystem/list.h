#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>


template <typename T> class List
{
    public:
        class Node
        {
            public:
                Node();
                ~Node();

                void setValue(T value);
                T getValue();

                void setNext();            // Set it to NULL
                void setNext(Node*& node);
                Node*& getNext();

            private:
                T value;
                Node* next;
        };

        List();
        ~List();

        Node* createNode(T value);

        Node* beginNode();
        Node* endNode();

        void pushBack(T value);
        void deleteNode(T value);
        void printItems();

        T& operator * ();
        void operator ++ ();

    private:
       Node* m_opHead;
       Node* m_opTail;

    public:
       typedef List<T>::Node* Iterator;
};


// Inner Class Node Members
template <typename T> List<T>::Node::Node() :
    value(0), next(NULL)
{
}

template <typename T> List<T>::Node::~Node()
{
}

template <typename T> void List<T>::Node::setValue(T value)
{
    this->value = value;
}

template <typename T> T List<T>::Node::getValue()
{
    return this->value;
}

template <typename T> void List<T>::Node::setNext()
{
    this->next = NULL;
}

template <typename T> void List<T>::Node::setNext(Node*& node)
{
    this->next = node;
}

template <typename T> typename List<T>::Node*& List<T>::Node::getNext()
{
    return this->next;
}

// List Class Members
template <typename T> List<T>::List(): m_opHead(NULL), m_opTail(NULL)
{
}

template <typename T> List<T>::~List()
{
    List<T>::Node* traverseNode = m_opHead;
    List<T>::Node* tmpNode = NULL;

    while(traverseNode)
    {
        tmpNode = traverseNode;
        tmpNode->setNext();     // Set to NULL

        delete tmpNode;
        tmpNode = NULL;

        traverseNode = traverseNode->getNext();
    }
}

template <typename T> typename List<T>::Node* List<T>::createNode(T value)
{
    List<T>::Node* newNode = new List<T>::Node();
    newNode->setValue(value);
    newNode->setNext();

    return newNode;
}

template <typename T> typename List<T>::Node* List<T>::beginNode()
{
    return m_opHead;
}

template <typename T> typename List<T>::Node* List<T>::endNode()
{
    return m_opTail;
}

template <typename T> void List<T>::pushBack(T value)
{
    if (m_opHead == NULL)
        m_opHead = m_opTail = createNode(value);
    else
    {
        m_opTail->getNext() = createNode(value);
        m_opTail = m_opTail->getNext();
    }
}
template <typename T> void List<T>::deleteNode(T value)
{
    List<T>::Node* traverseNode = m_opHead;
    List<T>::Node* tmpNode = NULL;

    while(traverseNode)
    {
        if(traverseNode->getValue() == value)   // Element is found
        {
            if (traverseNode == m_opHead)        // First node to be deleted
            {
                m_opHead = traverseNode->getNext();
                traverseNode->getNext() = NULL;
                delete traverseNode;
                traverseNode = NULL;
            }
            else if (traverseNode->getNext() == NULL)        // Last node to be deleted
            {
                tmpNode->getNext() = traverseNode->getNext();
                delete traverseNode;
                traverseNode = NULL;
                m_opTail = tmpNode;
            }
            else
            {
                tmpNode->getNext() = traverseNode->getNext();
                traverseNode->getNext() = NULL;
                delete traverseNode;
                traverseNode = NULL;
            }
            return;
        }
        tmpNode = traverseNode;
        traverseNode = traverseNode->getNext();
    }
}

template <typename T> void List<T>::printItems()
{
    List<T>::Node* traverseNode = m_opHead;

    while(traverseNode)
    {
        std::cout << traverseNode->getValue() << std::endl;
        traverseNode = traverseNode->getNext();
    }
}

template <typename T> T& List<T>::operator *()
{
    return this->getValue();
}

template <typename T> void List<T>::operator ++()
{

}

#endif // LIST_H_INCLUDED
