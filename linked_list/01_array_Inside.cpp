// just instead of a single data. I decided to add a vector inside it for fun.
// Like you can use a vector inside a linked list for storing row elements or maybe column elements. 
// many more things just for fun

// Blueprint:
// 1. Create a struct to hold student data: name, ID (USN), and marks.
// 2. Use a linked list to store multiple student records.
// 3. Implement a function `add_data` to add new student data to the linked list.
// 4. Implement a function `display` to print all student data in the linked list.


#include <iostream>
#include <vector>
#include <string>
using namespace std;


using str = string; 


struct node {
    str name;                     // Student's name
    int usn;                      // Student's unique ID
    vector<int> marks;            // List of marks for different subjects
    int no_of_subject;            // Number of subjects
    node* next;                   // Pointer to the next node in the linked list
};

using Node = struct node; // Alias for the struct for convenience

// Function to add a new node (student data) to the linked list
void add_data(Node*& head, const str& name, int usn, const vector<int>& marks) {
    // Step 1: Create a new node
    Node* curr = new Node;
    curr->name = name;                 // Set the student's name
    curr->usn = usn;                   // Set the student's ID
    curr->marks = marks;               // Set the student's marks
    curr->no_of_subject = marks.size(); // Set the number of subjects
    curr->next = nullptr;              // Initialize the next pointer to null

    // Step 2: Add the node to the linked list
    if (head == nullptr) {             // If the list is empty
        head = curr;                   // Make the new node the head
    } else {                           // If the list is not empty
        Node* temp = head;             // Start at the head
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = curr;             // Append the new node
    }
}

// Function to display all student data in the linked list
void display(Node* head) {
    Node* temp = head;                 // Start from the head of the list
    while (temp != nullptr) {          // Traverse until the end of the list
        cout << "Name: " << temp->name << ", USN: " << temp->usn
             << ", Subjects: " << temp->no_of_subject << ", Marks: ";
        for (int mark : temp->marks) { // Print marks for all subjects
            cout << mark << " ";
        }
        cout << endl;
        temp = temp->next;             // Move to the next node
    }
}

int main() {
    Node* head = nullptr; // Initialize the head of the linked list as null

    int size;
    cout << "Enter the total number of students: ";
    cin >> size;

    // Input data for each student
    for (int i = 0; i < size; ++i) {
        str name;
        int usn, num_subjects;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter USN: ";
        cin >> usn;
        cout << "Enter the number of subjects: ";
        cin >> num_subjects;

        vector<int> marks(num_subjects); // Collect marks for each subject
        cout << "Enter marks for " << num_subjects << " subjects: ";
        for (int j = 0; j < num_subjects; ++j) {
            cin >> marks[j];
        }

        // Add the student data to the linked list
        add_data(head, name, usn, marks);
    }

    // Display all student data
    cout << "\nStudent Data:\n";
    display(head);

    return 0;
}
