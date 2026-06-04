#include <iostream>
#include <string>
using namespace std;

/*
PATIENT STRUCT
*/
struct Patient {
    int id;
    string name;
    int age;
    int priority; // 1 = Critical, 2 = Normal
    Patient* next;
};

/*
PRIORITY QUEUE USING LINKED LIST (NO OOP)
*/
Patient* queueHead = nullptr;

// Insert patient based on priority
void enqueue(Patient* p) {

    if (!queueHead || p->priority < queueHead->priority) {
        p->next = queueHead;
        queueHead = p;
        return;
    }

    Patient* temp = queueHead;

    while (temp->next && temp->next->priority <= p->priority) {
        temp = temp->next;
    }

    p->next = temp->next;
    temp->next = p;
}

// Remove next patient
Patient* dequeue() {

    if (!queueHead)
        return nullptr;

    Patient* temp = queueHead;
    queueHead = queueHead->next;
    temp->next = nullptr;
    return temp;
}

// Display queue
void displayQueue() {

    if (!queueHead) {
        cout << "Queue is empty.\n";
        return;
    }

    Patient* temp = queueHead;

    while (temp) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Age: " << temp->age
             << " | Priority: "
             << (temp->priority == 1 ? "Critical" : "Normal")
             << endl;
        temp = temp->next;
    }
}

// BINARY SEARCH TREE 
struct BSTNode {
    long long id;
    Patient* patient;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* bstRoot = nullptr;

// Insert node
BSTNode* insertBST(BSTNode* node, Patient* p) {

    if (!node)
        return new BSTNode{p->id, p, nullptr, nullptr};

    if (p->id < node->id)
        node->left = insertBST(node->left, p);
    else
        node->right = insertBST(node->right, p);

    return node;
}

// Wrapper insert
void insertPatientBST(Patient* p) {
    bstRoot = insertBST(bstRoot, p);
}

// Search by ID
Patient* searchBST(long long id) {

    BSTNode* temp = bstRoot;

    while (temp) {
        if (id == temp->id)
            return temp->patient;
        else if (id < temp->id)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return nullptr;
}

// Inorder traversal
void inorderBST(BSTNode* node) {

    if (!node)
        return;

    inorderBST(node->left);

    cout << "ID: " << node->patient->id
         << " | Name: " << node->patient->name
         << " | Age: " << node->patient->age << endl;

    inorderBST(node->right);
}

// Display sorted by ID
void displaySortedByID() {

    if (!bstRoot) {
        cout << "No patients in system.\n";
        return;
    }

    inorderBST(bstRoot);
}

// MERGE SORT (BY AGE)
void merge(Patient* arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    Patient* L[n1];
    Patient* R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i]->age <= R[j]->age)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Patient* arr[], int left, int right) {

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// MAIN FUNCTION

int main() {

    Patient* patientArray[200];
    int count = 0;
    int choice;

    do {
        cout << "\n===== HOSPITAL PATIENT SYSTEM =====\n";
        cout << "1. Add Patient(s)\n";
        cout << "2. Call Next Patient\n";
        cout << "3. Display Patient Queue\n";
        cout << "4. Search Patient by ID\n";
        cout << "5. Display Patients Sorted by Age\n";
        cout << "6. Display Patients Sorted by ID (BST)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int k;
            cout << "How many patients do you want to add? ";
            cin >> k;

            for (int i = 0; i < k; i++) {

                Patient* p = new Patient();

                cout << "\nPatient " << i + 1 << " ID: ";
                cin >> p->id;

                cout << "Name: ";
                cin >> p->name;

                cout << "Age: ";
                cin >> p->age;

                cout << "Priority (1 = Critical, 2 = Normal): ";
                cin >> p->priority;

                p->next = nullptr;

                enqueue(p);
                insertPatientBST(p);
                patientArray[count++] = p;
            }

            cout << "Patient(s) added successfully.\n";
            break;
        }

        case 2: {
            Patient* p = dequeue();
            if (!p)
                cout << "No patient waiting.\n";
            else
                cout << "Doctor is now treating: " << p->name << endl;
            break;
        }

        case 3:
            displayQueue();
            break;

        case 4: {
            long long id;
            cout << "Enter patient ID to search: ";
            cin >> id;

            Patient* found = searchBST(id);
            if (found)
                cout << "Found: " << found->name << ", Age: " << found->age << endl;
            else
                cout << "Patient not found.\n";
            break;
        }

        case 5:
            if (count == 0) {
                cout << "No patients to sort.\n";
                break;
            }

            mergeSort(patientArray, 0, count - 1);
            cout << "--- Patients Sorted by Age ---\n";
            for (int i = 0; i < count; i++)
                cout << patientArray[i]->name
                     << " | Age: " << patientArray[i]->age << endl;
            break;

        case 6:
            cout << "--- Patients Sorted by ID ---\n";
            displaySortedByID();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
