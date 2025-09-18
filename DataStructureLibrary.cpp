#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description :   Generic implementation of Queue using singly linked list
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;                          // Data stored in the node
    struct Queuenode<T>* next;       // Pointer to next node
};

template <class T>
class QueueX
{
    private:
        struct Queuenode<T>* first;  // Pointer to front node of the queue
        int iCount;                  // Number of elements in the queue

    public:
        QueueX();                    // Constructor
        void Enqueue(T);             // Insert element at the rear
        T Dequeue();                 // Remove element from the front
        void Display();              // Display all elements
        int Count();                 // Get the number of elements
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   QueueX<T>::QueueX (Constructor)
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Initializes the queue. Sets the 'first' pointer to NULL and 
//      initializes the element count to zero.
//
//  Returns:
//      None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
QueueX<T>::QueueX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   QueueX<T>::Enqueue
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be inserted at the end of the queue.
//
//  Description:
//      Creates a new node with the given value and inserts it at the 
//      rear (end) of the queue. If the queue is empty, the new node 
//      becomes the first node.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void QueueX<T>::Enqueue(T no)
{
    struct Queuenode<T>* temp = NULL;
    struct Queuenode<T>* newn = new Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   QueueX<T>::Dequeue
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Removes the first element (front) of the queue and returns its value.
//      If the queue is empty, a message is displayed and NULL is returned.
//
//  Returns:
//      T
//      The value of the dequeued element. If the queue is empty, 
//      returns NULL.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T QueueX<T>::Dequeue()
{
    struct Queuenode<T>* temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first->next;
        delete temp;

        iCount--;
        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   QueueX<T>::Display
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Displays the elements of the queue in FIFO order. If the queue 
//      is empty, nothing is displayed.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void QueueX<T>::Display()
{
    struct Queuenode<T>* temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   QueueX<T>::Count
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Returns the number of elements currently present in the queue.
//
//  Returns:
//      int
//      The total number of nodes in the queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int QueueX<T>::Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description :   Generic implementation of Stack using singly linked list
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;                          // Data stored in the node
    struct Stacknode<T>* next;       // Pointer to next node
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T>* first;  // Pointer to top node of the stack
        int iCount;                  // Number of elements in the stack

    public:
        StackX();                    // Constructor
        void Push(T);                // Push element onto the stack
        T Pop();                     // Pop element from the stack
        void Display();              // Display all elements
        int Count();                 // Get number of elements
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   StackX<T>::StackX (Constructor)
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Initializes an empty stack. Sets the 'first' pointer to NULL and 
//      element count to zero.
//
//  Returns:
//      None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
StackX<T>::StackX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   StackX<T>::Push
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be pushed onto the stack.
//
//  Description:
//      Creates a new node and inserts it at the beginning of the linked 
//      list (top of stack). This ensures LIFO order.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T>::Push(T no)
{
    struct Stacknode<T>* newn = new Stacknode<T>;

    newn->data = no;
    newn->next = first;

    first = newn;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   StackX<T>::Pop
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Removes the top element from the stack and returns its value.
//      If the stack is empty, a message is displayed and NULL is returned.
//
//  Returns:
//      T
//      Value of the popped element, or NULL if the stack is empty.
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T StackX<T>::Pop()
{
    struct Stacknode<T>* temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first->next;
        delete temp;

        iCount--;
        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   StackX<T>::Display
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Displays all the elements of the stack from top to bottom.
//      If the stack is empty, nothing is displayed.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T>::Display()
{
    struct Stacknode<T>* temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   StackX<T>::Count
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Returns the number of elements currently present in the stack.
//
//  Returns:
//      int
//      Total number of elements in the stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int StackX<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCLL
//  Description :   Generic implementation of Singly Circular Linked List
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;                                 // Data stored in the node
    struct SinglyCLLnode<T>* next;          // Pointer to next node
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T>* first;     // Pointer to first node
        struct SinglyCLLnode<T>* last;      // Pointer to last node
        int iCount;                         // Number of elements in the list

    public:
        SinglyCLL();                        // Constructor

        void InsertFirst(T no);             // Insert element at beginning
        void InsertLast(T no);              // Insert element at end
        void InsertAtPos(T no, int pos);    // Insert element at position

        void DeleteFirst();                 // Delete first element
        void DeleteLast();                  // Delete last element
        void DeleteAtPos(int pos);          // Delete element at position

        void Display();                     // Display list
        int Count();                        // Return element count
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::SinglyCLL (Constructor)
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Initializes an empty singly circular linked list.
//      Sets first and last pointers to NULL and count to zero.
//
//  Returns:
//      None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLL<T>::SinglyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::InsertFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be inserted at the beginning.
//
//  Description:
//      Creates a new node and inserts it at the start of the list.
//      If the list is empty, first and last both point to the new node.
//      Maintains circular link between last and first.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(
                                    T no
        )
{
    struct SinglyCLLnode<T>* newn = new SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // Empty list
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::InsertLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be inserted at the end.
//
//  Description:
//      Creates a new node and inserts it at the end of the list.
//      If the list is empty, first and last both point to the new node.
//      Maintains circular link between last and first.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(
                                T no
        )
{
    struct SinglyCLLnode<T>* newn = new SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // Empty list
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::DeleteFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the first node of the list. Updates the first pointer
//      and maintains the circular connection. If the list is empty,
//      no operation is performed.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)   // Empty list
    {
        return;
    }
    else if(first == last)              // Single node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else                                // Multiple nodes
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::DeleteLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the last node of the list. Updates the last pointer
//      and maintains circular link. If list is empty, no operation.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T>* temp = NULL;

    if(first == NULL && last == NULL)   // Empty list
    {
        return;
    }
    else if(first == last)              // Single node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else                                // Multiple nodes
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::Display
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Displays all nodes of the singly circular linked list starting
//      from first and traversing until last->next.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T>* temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    } while(temp != last->next);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::Count
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Returns the number of nodes currently in the list.
//
//  Returns:
//      int
//      The count of nodes in the list.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::DeleteAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] int pos
//          Position of the node to be deleted (1-based).
//
//  Description:
//      Deletes a node from a specific position. Validates the position.
//      If pos = 1, deletes the first node. If pos = iCount, deletes last.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(
                                    int pos                                
    )
{
    struct SinglyCLLnode<T>* temp = NULL;
    struct SinglyCLLnode<T>* target = NULL;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyCLL<T>::InsertAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be inserted.
//      [IN] int pos
//          Position at which new node should be inserted.
//
//  Description:
//      Inserts a new node at the specified position. Validates the
//      position. If pos = 1, calls InsertFirst. If pos = iCount+1,
//      calls InsertLast.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(
                                    T no
                                    ,int pos
        )
{
    struct SinglyCLLnode<T>* temp = NULL;
    struct SinglyCLLnode<T>* newn = NULL;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = first;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description :   Generic implementation of Doubly Circular Linked List
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;                                   // Data stored in node
    struct DoublyCLLnode<T>* next;            // Pointer to next node
    struct DoublyCLLnode<T>* prev;            // Pointer to previous node
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T>* first;       // Pointer to first node
        struct DoublyCLLnode<T>* last;        // Pointer to last node
        int iCount;                           // Number of nodes

    public:
        DoublyCLL();                          // Constructor

        void InsertFirst(T);                  // Insert node at beginning
        void InsertLast(T);                   // Insert node at end
        void InsertAtPos(T, int);             // Insert node at position

        void DeleteFirst();                   // Delete first node
        void DeleteLast();                    // Delete last node
        void DeleteAtPos(int);                // Delete node at position

        void Display();                       // Display list
        int Count();                          // Return count of nodes
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::DoublyCLL (Constructor)
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Initializes an empty doubly circular linked list by setting
//      first and last pointers to NULL and count to zero.
//
//  Returns:
//      None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::InsertFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be inserted at beginning.
//
//  Description:
//      Creates a new node and inserts it at the start of the list.
//      Updates both first and last pointers and maintains circular
//      connections between them.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(     
                                    T no
        )
{
    struct DoublyCLLnode<T>* newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)       // Empty list
    {
        first = newn;
        last = newn;
    }
    else                                    // At least one node
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::InsertLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be inserted at end.
//
//  Description:
//      Creates a new node and appends it at the end of the list.
//      Updates last pointer and circular links accordingly.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(      
                                    T no
)
{
    struct DoublyCLLnode<T>* newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)       // Empty list
    {
        first = newn;
        last = newn;
    }
    else                                    // At least one node
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::Display
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Displays the entire list in forward direction starting from 'first'.
//      If the list is empty, displays an appropriate message.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
    struct DoublyCLLnode<T>* temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    } while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::Count
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Returns the total number of nodes currently in the list.
//
//  Returns:
//      int
//      Count of nodes
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::DeleteFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the first node from the list. Adjusts the first pointer
//      and maintains circular doubly links.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)        // Empty list
    {
        return;
    }
    else if(first == last)                   // Single node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else                                     // Multiple nodes
    {
        first = first->next;
        delete first->prev;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::DeleteLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the last node from the list. Adjusts the last pointer
//      and maintains circular doubly links.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)        // Empty list
    {
        return;
    }
    else if(first == last)                   // Single node
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else                                     // Multiple nodes
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::InsertAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T no
//          Value to be inserted
//      [IN] int pos
//          Position at which node should be inserted
//
//  Description:
//      Inserts a new node at the given position. Validates the position.
//      Calls InsertFirst if pos = 1 and InsertLast if pos = iCount+1.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(
                                    T no, 
                                    int pos
        )
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct DoublyCLLnode<T>* temp = first;
        struct DoublyCLLnode<T>* newn = new DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyCLL<T>::DeleteAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] int pos
//          Position of node to be deleted
//
//  Description:
//      Deletes a node from the specified position. Validates the position.
//      Calls DeleteFirst if pos = 1 and DeleteLast if pos = iCount.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteAtPos(         
                                        int pos
)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct DoublyCLLnode<T>* temp = first;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLGen
//  Description :   Generic implementation of Singly Linear Linked List
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;                   // Data stored in node
    struct node<T>* next;     // Pointer to next node
};

template<class T>
class SinglyLGen
{
    private:
        struct node<T>* first;   // Pointer to first node
        int iCount;              // Number of nodes in list

    public:
        SinglyLGen();            // Constructor

        void InsertFirst(T);     // Insert node at beginning
        void InsertLast(T);      // Insert node at end
        void InsertAtPos(T, int);// Insert node at position

        void DeleteFirst();      // Delete first node
        void DeleteLast();       // Delete last node
        void DeleteAtPos(int);   // Delete node at position

        void Display();          // Display all nodes
        int Count();             // Return node count
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::SinglyLGen (Constructor)
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Initializes an empty singly linear linked list. Sets first pointer
//      to NULL and element count to zero.
//
//  Returns:
//      None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyLGen<T>::SinglyLGen()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::InsertFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T No
//          Value to be inserted at beginning.
//
//  Description:
//      Creates a new node and inserts it at the start of the list.
//      Updates the first pointer to the new node.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLGen<T>::InsertFirst(
                                    T No
                )

{
    struct node<T>* newn = new node<T>;
    newn->data = No;
    newn->next = first;

    first = newn;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::InsertLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T No
//          Value to be inserted at end.
//
//  Description:
//      Creates a new node and appends it at the end of the list.
//      Traverses the list until the last node is found.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLGen<T>::InsertLast( 
                                    T No
                                    )
{
    struct node<T>* newn = new node<T>;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL)    // Empty list
    {
        first = newn;
    }
    else                 // Traverse to last
    {
        struct node<T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::InsertAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T No
//          Value to be inserted
//      [IN] int Pos
//          Position at which new node is to be inserted
//
//  Description:
//      Inserts a new node at the given position. Validates the position.
//      Calls InsertFirst if pos = 1 and InsertLast if pos = iCount+1.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLGen<T>::InsertAtPos(    
                                        
                                        T No, 
                                        int Pos
)
{
    if(Pos < 1 || Pos > iCount+1)
    {
        cout << "Invalid Position....\n";
        return;
    }
    if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T>* newn = new node<T>;
        newn->data = No;
        newn->next = NULL;

        struct node<T>* temp = first;
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::DeleteFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the first node from the list. Updates the first pointer.
//      If the list is empty, no operation is performed.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLGen<T>::DeleteFirst()
{
    if(first == NULL)        // Empty list
    {
        return;
    }
    else
    {
        struct node<T>* temp = first;
        first = first->next;
        delete temp;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::DeleteLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the last node of the list. Traverses until the
//      second-last node and updates its next pointer to NULL.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLGen<T>::DeleteLast()
{
    if(first == NULL)                     // Empty list
    {
        return;
    }
    else if(first->next == NULL)          // Single node
    {
        delete first;
        first = NULL;
        iCount--;
    }
    else                                  // Multiple nodes
    {
        struct node<T>* temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::DeleteAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] int Pos
//          Position of node to be deleted
//
//  Description:
//      Deletes the node from the given position. Validates the position.
//      Calls DeleteFirst if pos = 1 and DeleteLast if pos = iCount.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLGen<T>::DeleteAtPos(
                                    int Pos
                
                )
{
    if(Pos < 1 || Pos > iCount)
    {
        cout << "Invalid Position....\n";
        return;
    }
    if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct node<T>* temp = first;
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }

        struct node<T>* target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::Display
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Displays all elements of the singly linked list in linear order.
//      Traverses until NULL and prints each node.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLGen<T>::Display()
{
    struct node<T>* temp = first;
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SinglyLGen<T>::Count
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Returns the number of nodes currently present in the list.
//
//  Returns:
//      int
//      Count of nodes
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLGen<T>::Count()
{
    return iCount;
}



////////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLGen 
//  Description :   Generic implementation of Doubly Linear Linked List
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct dnode
{
    T data;                   // Data stored in node
    struct dnode<T>* next;    // Pointer to next node
    struct dnode<T>* prev;    // Pointer to previous node
};

template<class T>
class DoublyLGen
{
    private:
        struct dnode<T>* first;   // Pointer to first node
        int iCount;               // Number of nodes in list

    public:
        DoublyLGen();             // Constructor

        void InsertFirst(T);      // Insert node at beginning
        void InsertLast(T);       // Insert node at end
        void InsertAtPos(T, int); // Insert node at position

        void DeleteFirst();       // Delete first node
        void DeleteLast();        // Delete last node
        void DeleteAtPos(int);    // Delete node at position

        void Display();           // Display all nodes
        int Count();              // Return node count
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::DoublyLGen (Constructor)
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Initializes an empty doubly linear linked list. Sets first pointer
//      to NULL and element count to zero.
//
//  Returns:
//      None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLGen<T>::DoublyLGen()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::InsertFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T No
//          Value to be inserted at beginning.
//
//  Description:
//      Creates a new node and inserts it at the start of the list.
//      Updates previous pointer of old first node.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLGen<T>::InsertFirst(
                                    T No
                                    
                            )
{
    struct dnode<T>* newn = new dnode<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)               // Empty list
    {
        first = newn;
    }
    else                            // At least one node
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::InsertLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T No
//          Value to be inserted at end.
//
//  Description:
//      Creates a new node and appends it at the end of the list.
//      Traverses until last node and updates pointers.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLGen<T>::InsertLast(
                            
                                    T No
                            
                            )
{
    struct dnode<T>* newn = new dnode<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)                // Empty list
    {
        first = newn;
    }
    else                             // Traverse to last
    {
        struct dnode<T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::InsertAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T No
//          Value to be inserted
//      [IN] int Pos
//          Position where node is to be inserted
//
//  Description:
//      Inserts a new node at the given position. Validates the position.
//      Calls InsertFirst if pos = 1 and InsertLast if pos = iCount+1.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLGen<T>::InsertAtPos(
                    
                                    T No, 
                                    int Pos
                                    
                                )
{
    if(Pos < 1 || Pos > iCount+1)
    {
        cout<<"Invalid Position....\n";
        return;
    }

    if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct dnode<T>* temp = first;
        struct dnode<T>* newn = new dnode<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < Pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::DeleteFirst
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the first node of the list. Updates first pointer.
//      If list is empty, no operation performed.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLGen<T>::DeleteFirst()
{
    if(first == NULL)                // Empty list
    {
        return;
    }
    else if(first->next == NULL)     // Single node
    {
        delete first;
        first = NULL;
    }
    else                             // Multiple nodes
    {
        struct dnode<T>* temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::DeleteLast
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Deletes the last node of the list. Traverses until last node.
//      Updates second-last node's next pointer to NULL.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLGen<T>::DeleteLast()
{
    if(first == NULL)                // Empty list
    {
        return;
    }
    else if(first->next == NULL)     // Single node
    {
        delete first;
        first = NULL;
    }
    else                             // Multiple nodes
    {
        struct dnode<T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::DeleteAtPos
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] int Pos
//          Position of node to be deleted
//
//  Description:
//      Deletes a node at given position. Validates position.
//      Calls DeleteFirst if pos = 1 and DeleteLast if pos = iCount.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLGen<T>::DeleteAtPos(
                                        int Pos
                                        
                            )
{
    if(Pos < 1 || Pos > iCount)
    {
        cout<<"Invalid Position....\n";
        return;
    }

    if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct dnode<T>* temp = first;
        for(int iCnt = 1; iCnt < Pos-1; iCnt++)
        {
            temp = temp->next;
        }

        struct dnode<T>* target = temp->next;
        temp->next = target->next;
        if(target->next != NULL)
        {
            target->next->prev = temp;
        }
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::Display
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Displays all nodes of the doubly linked list in forward direction.
//      Traverses until NULL.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLGen<T>::Display()
{
    struct dnode<T>* temp = first;
    cout << "NULL <=> ";
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DoublyLGen<T>::Count
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Returns the number of nodes currently present in the list.
//
//  Returns:
//      int
//      Count of nodes
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLGen<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         BST
//  Description :   Generic implementation of Binary Search Tree (BST)
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct bstnode
{
    T data;                      // Data stored in node
    struct bstnode<T>* lchild;   // Pointer to left child
    struct bstnode<T>* rchild;   // Pointer to right child
};

template<class T>
class BST
{
    private:
        struct bstnode<T>* root;  // Root of BST

    public:
        BST();                    // Constructor
        void Insert(T);           // Insert node
        bool Search(T);           // Search for node
        void Inorder();           // Display inorder (LNR)
        void Preorder();          // Display preorder (NLR)
        void Postorder();         // Display postorder (LRN)
        void Delete(T);           // Delete node

    private:
        void InorderR(struct bstnode<T>*);
        void PreorderR(struct bstnode<T>*);
        void PostorderR(struct bstnode<T>*);
        struct bstnode<T>* DeleteR(struct bstnode<T>*, T);
        struct bstnode<T>* FindMin(struct bstnode<T>*);
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::BST (Constructor)
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Initializes an empty BST with root pointer set to NULL.
//
//  Returns:
//      None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
BST<T>::BST()
{
    root = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::Insert
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T value
//          Value to be inserted in BST.
//
//  Description:
//      Inserts a node into BST maintaining its sorted property.
//      Smaller values go to left subtree, larger to right.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Insert(    
                            T value
                            
                        )
{
    struct bstnode<T>* newn = new bstnode<T>;
    newn->data = value;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(root == NULL)
    {
        root = newn;
    }
    else
    {
        struct bstnode<T>* temp = root;
        struct bstnode<T>* parent = NULL;

        while(temp != NULL)
        {
            parent = temp;
            if(value < temp->data)
            {
                temp = temp->lchild;
            }
            else if(value > temp->data)
            {
                temp = temp->rchild;
            }
            else
            {
                delete newn; // Duplicate not allowed
                return;
            }
        }

        if(value < parent->data)
            parent->lchild = newn;
        else
            parent->rchild = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::Search
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T value
//          Value to be searched.
//
//  Description:
//      Searches the BST for a given value. Traverses left or right subtree
//      depending on comparison with current node.
//
//  Returns:
//      bool
//      TRUE if value found, FALSE otherwise.
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool BST<T>::Search(            
                                T value
)
{
    struct bstnode<T>* temp = root;
    while(temp != NULL)
    {
        if(value == temp->data)
            return true;
        else if(value < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::InorderR
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] struct bstnode<T>* node
//          Pointer to current node
//
//  Description:
//      Recursive helper for inorder traversal (LNR).
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::InorderR(  
    
                            struct bstnode<T>* node
                )
{
    if(node != NULL)
    {
        InorderR(node->lchild);
        cout << node->data << " ";
        InorderR(node->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::PreorderR
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] struct bstnode<T>* node
//          Pointer to current node
//
//  Description:
//      Recursive helper for preorder traversal (NLR).
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::PreorderR( 
                        
                                struct bstnode<T>* node
                        
                        )
{
    if(node != NULL)
    {
        cout << node->data << " ";
        PreorderR(node->lchild);
        PreorderR(node->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::PostorderR
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] struct bstnode<T>* node
//          Pointer to current node
//
//  Description:
//      Recursive helper for postorder traversal (LRN).
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::PostorderR(    
    
                                    struct bstnode<T>* node
                                    
                        )
{
    if(node != NULL)
    {
        PostorderR(node->lchild);
        PostorderR(node->rchild);
        cout << node->data << " ";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::Inorder
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Public function to display BST nodes in inorder sequence.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Inorder()
{
    InorderR(root);
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::Preorder
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Public function to display BST nodes in preorder sequence.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Preorder()
{
    PreorderR(root);
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::Postorder
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      None
//
//  Description:
//      Public function to display BST nodes in postorder sequence.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Postorder()
{
    PostorderR(root);
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::FindMin
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] struct bstnode<T>* node
//          Subtree root
//
//  Description:
//      Finds the node with minimum value in the given subtree.
//
//  Returns:
//      struct bstnode<T>*
//      Pointer to node with minimum value
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
struct bstnode<T>* BST<T>::FindMin(
                                        struct bstnode<T>* node
                                        
                                    )
{
    while(node->lchild != NULL)
    {
        node = node->lchild;
    }
    return node;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::DeleteR
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] struct bstnode<T>* root
//          Current subtree root
//      [IN] T value
//          Value to be deleted
//
//  Description:
//      Recursive helper for deletion in BST.
//      Handles three cases: no child, one child, two children.
//
//  Returns:
//      struct bstnode<T>*
//      Updated subtree root after deletion
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
struct bstnode<T>* BST<T>::DeleteR( 
                                    struct bstnode<T>* root, T value
                                    )
{
    if(root == NULL)
        return root;

    if(value < root->data)
    {
        root->lchild = DeleteR(root->lchild, value);
    }
    else if(value > root->data)
    {
        root->rchild = DeleteR(root->rchild, value);
    }
    else
    {
        // Case 1: No child
        if(root->lchild == NULL && root->rchild == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if(root->lchild == NULL)
        {
            struct bstnode<T>* temp = root->rchild;
            delete root;
            return temp;
        }
        else if(root->rchild == NULL)
        {
            struct bstnode<T>* temp = root->lchild;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else
        {
            struct bstnode<T>* temp = FindMin(root->rchild);
            root->data = temp->data;
            root->rchild = DeleteR(root->rchild, temp->data);
        }
    }
    return root;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   BST<T>::Delete
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T value
//          Value to be deleted
//
//  Description:
//      Deletes a node from the BST. Uses recursive helper function DeleteR.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Delete(        
                            T value 
                    )
{
    root = DeleteR(root, value);
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting
//  Description :   Generic implementation of Sorting algorithms
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template<class T>
class Sorting
{
    public:
        void BubbleSort(T arr[], int n);     // Bubble Sort
        void InsertionSort(T arr[], int n);  // Insertion Sort
        void SelectionSort(T arr[], int n);  // Selection Sort
        void QuickSort(T arr[], int low, int high); // Quick Sort
        void MergeSort(T arr[], int low, int high); // Merge Sort

    private:
        int Partition(T arr[], int low, int high);  // QuickSort helper
        void Merge(T arr[], int low, int mid, int high); // MergeSort helper
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Sorting<T>::BubbleSort
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN/OUT] T arr[] - Array to be sorted
//      [IN] int n - Number of elements
//
//  Description:
//      Performs Bubble Sort. Repeatedly swaps adjacent elements
//      if they are in wrong order.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Sorting<T>::BubbleSort(    
                                
                                    T arr[], int n
                                
                                )
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Sorting<T>::InsertionSort
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN/OUT] T arr[] - Array to be sorted
//      [IN] int n - Number of elements
//
//  Description:
//      Performs Insertion Sort. Inserts each element into its proper
//      place in the sorted portion of the array.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Sorting<T>::InsertionSort(     
                                    T arr[], 
                                    int n
                                
                                )
{
    for(int i = 1; i < n; i++)
    {
        T key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Sorting<T>::SelectionSort
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN/OUT] T arr[] - Array to be sorted
//      [IN] int n - Number of elements
//
//  Description:
//      Performs Selection Sort. Finds the minimum element from unsorted
//      portion and places it at the beginning.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Sorting<T>::SelectionSort( 
                                    
                                    T arr[],
                                     int n
                                     
                                    )
{
    for(int i = 0; i < n-1; i++)
    {
        int minIdx = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Sorting<T>::Partition
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN/OUT] T arr[] - Array to be partitioned
//      [IN] int low - Start index
//      [IN] int high - End index
//
//  Description:
//      Helper for QuickSort. Chooses pivot and partitions the array
//      into two halves: values <= pivot and values > pivot.
//
//  Returns:
//      int
//      Partition index
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Sorting<T>::Partition(  

                            T arr[], 
                            int low, 
                            int high
            )
                        


{
    T pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Sorting<T>::QuickSort
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN/OUT] T arr[] - Array to be sorted
//      [IN] int low - Start index
//      [IN] int high - End index
//
//  Description:
//      Performs Quick Sort using divide-and-conquer technique.
//      Recursively sorts left and right partitions.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Sorting<T>::QuickSort(
                                
                                T arr[], 
                                int low, 
                                int high
            )
{
    if(low < high)
    {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Sorting<T>::Merge
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN/OUT] T arr[] - Array to be merged
//      [IN] int low - Start index
//      [IN] int mid - Middle index
//      [IN] int high - End index
//
//  Description:
//      Helper for MergeSort. Merges two sorted subarrays into one.
//      Left subarray: arr[low..mid], Right subarray: arr[mid+1..high].
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Sorting<T>::Merge(
                            T arr[], 
                            int low, 
                            int mid, 
                            int high
    
    )
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[low+i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid+1+j];

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Sorting<T>::MergeSort
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN/OUT] T arr[] - Array to be sorted
//      [IN] int low - Start index
//      [IN] int high - End index
//
//  Description:
//      Performs Merge Sort using divide-and-conquer technique.
//      Recursively divides array and merges sorted halves.
//
//  Returns:
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Sorting<T>::MergeSort( 
                        
                        T arr[], 
                        int low, 
                        int high
                        
                        )
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         Searching
//  Description :   Generic implementation of Searching algorithms
//  Author :        Kartik Anilrao Dahale
//  Date   :        16/09/2025
//
///////////////////////////////////////////////////////////////////////

template<class T>
class Searching
{
    public:
        int LinearSearch(
                            
                        T arr[],
                        int n, T key
                    );     // Linear Search
        int BinarySearch(
                        
                        T arr[], 
                        int n, 
                        T key
                        
                        );     // Binary Search
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Searching<T>::LinearSearch
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T arr[] - Array to be searched
//      [IN] int n   - Number of elements
//      [IN] T key   - Value to search for
//
//  Description:
//      Performs Linear Search on the array. Scans each element sequentially
//      until the key is found or end of array is reached.
//
//  Returns:
//      int
//      Index of the key if found (0-based index).
//      -1 if the key is not present.
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Searching<T>::LinearSearch(
                                    T arr[], 
                                    int n, 
                                    T key
                                    
                                    )
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Searching<T>::BinarySearch
//  Function Date   :   16/09/2025
//  Function Author :   Kartik Anilrao Dahale
//
//  Parameters:
//      [IN] T arr[] - Sorted array to be searched
//      [IN] int n   - Number of elements
//      [IN] T key   - Value to search for
//
//  Description:
//      Performs Binary Search on a sorted array. Repeatedly divides
//      the array in half until the key is found or the search space is empty.
//
//  Returns:
//      int
//      Index of the key if found (0-based index).
//      -1 if the key is not present.
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Searching<T>::BinarySearch(
                                    T arr[],
                                    int n, 
                                    T key
                                    
                                )
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    
    
    return 0;
}