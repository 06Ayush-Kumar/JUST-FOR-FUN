#include<iostream>
#include<vector>
using namespace std;
using str = string;


vector<str> book_names;
vector<str> author_names;
vector<float> prices;

void add_new_items(str a, float b, str c) {
    book_names.push_back(a);
    author_names.push_back(c);
    prices.push_back(b);
}

void display_books() {
    cout << "Books in the library:\n";
    for (size_t i = 0; i < book_names.size(); ++i) {
        cout << "Book: " << book_names[i] << ", Author: " << author_names[i] << ", Price: " << prices[i] << "\n";
    }
}

int main() {
    int option;
    str book_name;
    float price;
    str author_name;
while(true){    
    cout << "Hello! Welcome to the library\n";
    cout << "Please select any one option\n";
    cout << "1. Display all the books\n" << "2. Add a new book\n" << "3. Display books by price\n"<<"4. Exit";
    
    cin >> option;
    
    if (option == 2) {
        cout << "Please name the book:\n";
        cin.ignore(); 
        getline(cin, book_name); 
        cout << "Please enter the author name:\n";
        getline(cin, author_name); 
        cout << "Please enter the price:\n";
        cin >> price;
        add_new_items(book_name, price, author_name);
    } 
    else if (option == 1) {
        display_books();
    }
    else if(option==4){
        break;
    }}
    
    return 0;
}
