
#include <iostream>
#include "DataStructureLibrary.cpp"  // Include your library directly
using namespace std;

// ================= STACK MENU =================
void StackMenu() {
    StackX<int> s;
    int choice, val;
    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Count\n0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; s.Push(val); break;
            case 2: 
                if(s.Count() > 0) cout << "Popped: " << s.Pop() << endl;
                else cout << "Stack is empty!\n"; 
                break;
            case 3: s.Display(); break;
            case 4: cout << "Count: " << s.Count() << endl; break;
        }
    } while(choice != 0);
}

// ================= QUEUE MENU =================
void QueueMenu() {
    QueueX<int> q;
    int choice, val;
    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Count\n0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; q.Enqueue(val); break;
            case 2:
                if(q.Count() > 0) cout << "Dequeued: " << q.Dequeue() << endl;
                else cout << "Queue is empty!\n"; 
                break;
            case 3: q.Display(); break;
            case 4: cout << "Count: " << q.Count() << endl; break;
        }
    } while(choice != 0);
}

// ================ SINGLY CIRCULAR LINKED LIST MENU ================
void SinglyCLLMenu() {
    SinglyCLL<int> scll;
    int choice, val, pos;
    do {
        cout << "\n--- SINGLY CIRCULAR LINKED LIST MENU ---\n";
        cout << "1. InsertFirst 2. InsertLast 3. InsertAtPos\n";
        cout << "4. DeleteFirst 5. DeleteLast 6. DeleteAtPos\n";
        cout << "7. Display 8. Count 0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; scll.InsertFirst(val); break;
            case 2: cout << "Enter value: "; cin >> val; scll.InsertLast(val); break;
            case 3: cout << "Enter value and position: "; cin >> val >> pos; scll.InsertAtPos(val,pos); break;
            case 4: scll.DeleteFirst(); break;
            case 5: scll.DeleteLast(); break;
            case 6: cout << "Enter position: "; cin >> pos; scll.DeleteAtPos(pos); break;
            case 7: scll.Display(); break;
            case 8: cout << "Count: " << scll.Count() << endl; break;
        }
    } while(choice != 0);
}

// ================= DOUBLY CIRCULAR LINKED LIST MENU =================
void DoublyCLLMenu() {
    DoublyCLL<int> dcll;
    int choice, val, pos;
    do {
        cout << "\n--- DOUBLY CIRCULAR LINKED LIST MENU ---\n";
        cout << "1. InsertFirst 2. InsertLast 3. InsertAtPos\n";
        cout << "4. DeleteFirst 5. DeleteLast 6. DeleteAtPos\n";
        cout << "7. Display 8. Count 0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; dcll.InsertFirst(val); break;
            case 2: cout << "Enter value: "; cin >> val; dcll.InsertLast(val); break;
            case 3: cout << "Enter value and position: "; cin >> val >> pos; dcll.InsertAtPos(val,pos); break;
            case 4: dcll.DeleteFirst(); break;
            case 5: dcll.DeleteLast(); break;
            case 6: cout << "Enter position: "; cin >> pos; dcll.DeleteAtPos(pos); break;
            case 7: dcll.Display(); break;
            case 8: cout << "Count: " << dcll.Count() << endl; break;
        }
    } while(choice != 0);
}

// ================= SINGLY GENERIC LINKED LIST MENU =================
void SinglyLGenMenu() {
    SinglyLGen<int> slg;
    int choice, val, pos;
    do {
        cout << "\n--- SINGLY GENERIC LINKED LIST MENU ---\n";
        cout << "1. InsertFirst 2. InsertLast 3. InsertAtPos\n";
        cout << "4. DeleteFirst 5. DeleteLast 6. DeleteAtPos\n";
        cout << "7. Display 8. Count 0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; slg.InsertFirst(val); break;
            case 2: cout << "Enter value: "; cin >> val; slg.InsertLast(val); break;
            case 3: cout << "Enter value and position: "; cin >> val >> pos; slg.InsertAtPos(val,pos); break;
            case 4: slg.DeleteFirst(); break;
            case 5: slg.DeleteLast(); break;
            case 6: cout << "Enter position: "; cin >> pos; slg.DeleteAtPos(pos); break;
            case 7: slg.Display(); break;
            case 8: cout << "Count: " << slg.Count() << endl; break;
        }
    } while(choice != 0);
}

// ================= DOUBLY GENERIC LINKED LIST MENU =================
void DoublyLGenMenu() {
    DoublyLGen<int> dlg;
    int choice, val, pos;
    do {
        cout << "\n--- DOUBLY GENERIC LINKED LIST MENU ---\n";
        cout << "1. InsertFirst 2. InsertLast 3. InsertAtPos\n";
        cout << "4. DeleteFirst 5. DeleteLast 6. DeleteAtPos\n";
        cout << "7. Display 8. Count 0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; dlg.InsertFirst(val); break;
            case 2: cout << "Enter value: "; cin >> val; dlg.InsertLast(val); break;
            case 3: cout << "Enter value and position: "; cin >> val >> pos; dlg.InsertAtPos(val,pos); break;
            case 4: dlg.DeleteFirst(); break;
            case 5: dlg.DeleteLast(); break;
            case 6: cout << "Enter position: "; cin >> pos; dlg.DeleteAtPos(pos); break;
            case 7: dlg.Display(); break;
            case 8: cout << "Count: " << dlg.Count() << endl; break;
        }
    } while(choice != 0);
}

// ================= BST MENU =================
void BSTMenu() {
    BST<int> bst;
    int choice, val;
    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert 2. Delete 3. Search\n4. Inorder 5. Preorder 6. Postorder 0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; bst.Insert(val); break;
            case 2: cout << "Enter value to delete: "; cin >> val; bst.Delete(val); break;
            case 3: cout << "Enter value to search: "; cin >> val; cout << (bst.Search(val) ? "Found\n" : "Not Found\n"); break;
            case 4: bst.Inorder(); cout << endl; break;
            case 5: bst.Preorder(); cout << endl; break;
            case 6: bst.Postorder(); cout << endl; break;
        }
    } while(choice != 0);
}

// ================= SORTING MENU =================
void SortingMenu() {
    int arr[100], n, choice;
    cout << "Enter number of elements: "; cin >> n;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    Sorting<int> sorter;
    do {
        cout << "\n--- SORTING MENU ---\n1. BubbleSort 2. SelectionSort 0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: sorter.BubbleSort(arr,n); break;
            case 2: sorter.SelectionSort(arr,n); break;
        }
        cout << "Array: ";
        for(int i=0;i<n;i++) cout << arr[i] << " ";
        cout << endl;
    } while(choice != 0);
}

// ================= SEARCHING MENU =================
void SearchingMenu() {
    int arr[100], n, choice, key;
    cout << "Enter number of elements: "; cin >> n;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    Searching<int> searcher;
    do {
        cout << "\n--- SEARCHING MENU ---\n1. LinearSearch 2. BinarySearch 0. Back\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: 
                cout << "Enter key: "; cin >> key; 
                {
                    int idx = searcher.LinearSearch(arr,n,key);
                    if(idx!=-1) cout << "Found at index " << idx << endl;
                    else cout << "Not Found\n";
                } break;
            case 2:
                cout << "Enter key: "; cin >> key;
                {
                    int idx = searcher.BinarySearch(arr,n,key);
                    if(idx!=-1) cout << "Found at index " << idx << endl;
                    else cout << "Not Found\n";
                } break;
        }
    } while(choice != 0);
}

// ================= MAIN MENU =================
int main() {
    int choice;
    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Stack\n2. Queue\n3. SinglyCLL\n4. DoublyCLL\n";
        cout << "5. BST\n6. Sorting\n7. Searching\n";
        cout << "8. SinglyLGen\n9. DoublyLGen\n0. Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1: StackMenu(); break;
            case 2: QueueMenu(); break;
            case 3: SinglyCLLMenu(); break;
            case 4: DoublyCLLMenu(); break;
            case 5: BSTMenu(); break;
            case 6: SortingMenu(); break;
            case 7: SearchingMenu(); break;
            case 8: SinglyLGenMenu(); break;
            case 9: DoublyLGenMenu(); break;
        }
    } while(choice != 0);

    cout << "Exiting program....\nThank you for using Application 😊\n";
    return 0;
}
