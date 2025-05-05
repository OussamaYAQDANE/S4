#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Book
{
public:
    string name;
    int pages_number;

    Book(string name, int pages_number): name(name), pages_number(pages_number){}
};

ostream& operator<<(ostream& os, Book book){
    os << "Book[name: "<< book.name<< ", pages_number: "<< book.pages_number<<"]";
    return os;
}



int main() {
    vector<Book> books = {
        Book("The Great Gatsby", 218),
        Book("To Kill a Mockingbird", 281),
        Book("1984", 328),
        Book("Pride and Prejudice", 279),
        Book("The Hobbit", 310),
        Book("The Catcher in the Rye", 234),
        Book("Fahrenheit 451", 249),
        Book("Moby Dick", 635),
        Book("The Odyssey", 384),
        Book("Brave New World", 311)
    };
    cout << "Sort by name:" << endl;
    sort(books.begin(), books.end(), [](Book book1, Book book2 ){return book1.name < book2.name;});
    for_each(books.begin(), books.end(), [](Book book){cout << book << endl;});
    cout << endl << "Sort by name:" << endl;
    sort(books.begin(), books.end(), [](Book book1, Book book2 ){return book1.pages_number < book2.pages_number;});
    for_each(books.begin(), books.end(), [](Book book){cout << book << endl;});
}
