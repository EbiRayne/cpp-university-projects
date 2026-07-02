#include <iostream>
#include <string>
using namespace std;

struct infoBook {
    string title;
    string author;
    int publicationYear;
    bool returned;
};

struct infoPerson {
    string Fullname;
    long long ID;
    infoBook* borrowedBooks[10];
    int borrowedCount;
    infoPerson* next;
};

void addingPeople(infoPerson*& head) {
    int n;
    cout << "How many people do you want to add?: ";
    cin >> n;
    cin.ignore();

    infoPerson* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    for (int i = 0; i < n; i++) {
        infoPerson* newPerson = new infoPerson;

        cout << "What's this person's name: ";
        getline(cin, newPerson->Fullname); 

        cout << "Enter ID: ";
        cin >> newPerson->ID;
        cin.ignore(); 

        newPerson->borrowedCount = 0;
        newPerson->next = nullptr;

        tail->next = newPerson;
        tail = newPerson;
    }
}

infoPerson* searchByID(infoPerson* head, long long id) {
    infoPerson* current = head;
    while (current != nullptr) {
        if (current->ID == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void addBookToPerson(infoPerson* person) {
    if (person->borrowedCount >= 10) {
        cout << "This person already has maximum number of books.\n";
        return;
    }

    infoBook* newBook = new infoBook;

    cin.ignore();

    cout << "Book title: ";
    getline(cin, newBook->title);

    cout << "Author: ";
    getline(cin, newBook->author);

    cout << "Publication year: ";
    cin >> newBook->publicationYear;

    cout << "Returned (0 or 1): ";
    cin >> newBook->returned;

    person->borrowedBooks[person->borrowedCount] = newBook;
    person->borrowedCount++;

    cout << "Book added successfully.\n";
}

void displayAllPeople(infoPerson* head) {
    infoPerson* current = head;

    while (current != nullptr) {
        cout << "\nName: " << current->Fullname << endl;
        cout << "ID: " << current->ID << endl;

        if (current->borrowedCount == 0) {
            cout << "  No borrowed books.\n";
        }

        for (int i = 0; i < current->borrowedCount; i++) {
            cout << "  Title: " << current->borrowedBooks[i]->title << endl;
            cout << "  Author: " << current->borrowedBooks[i]->author << endl;
            cout << "  Year: " << current->borrowedBooks[i]->publicationYear << endl;
            cout << "  Returned: " << current->borrowedBooks[i]->returned << endl;
        }

        current = current->next;
    }
}

int main() {
    infoBook book1{"Moby Dick", "Herman Melville", 1851, false};
    infoBook book2{"Da Vinci Code", "Dan Brown", 2003, true};

    infoPerson* person1 = new infoPerson;
    infoPerson* person2 = new infoPerson;

    person1->Fullname = "Amelia Watson";
    person1->ID = 81010200141;
    person1->borrowedCount = 1;
    person1->borrowedBooks[0] = &book1;

    person2->Fullname = "John Books";
    person2->ID = 81800676710;
    person2->borrowedCount = 1;
    person2->borrowedBooks[0] = &book2;

    person1->next = person2;
    person2->next = nullptr;

    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add new person\n";
        cout << "2. Search person by ID\n";
        cout << "3. Add book to person\n";
        cout << "4. Display all people and books\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            addingPeople(person1);
        }
        else if (choice == 2) {
            long long id;
            cout << "Enter ID to search: ";
            cin >> id;

            infoPerson* found = searchByID(person1, id);
            if (found != nullptr) {
                cout << "Person found: " << found->Fullname << endl;
            } else {
                cout << "Person not found.\n";
            }
        }
        else if (choice == 3) {
            long long id;
            cout << "Enter ID of person: ";
            cin >> id;

            infoPerson* found = searchByID(person1, id);
            if (found != nullptr) {
                addBookToPerson(found);
            } else {
                cout << "Person not found.\n";
            }
        }
        else if (choice == 4) {
            displayAllPeople(person1);
        }
        else if (choice == 0) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "\n !!Invalid choice!!\n";
        }

    } while (choice != 0);

    return 0;
}
