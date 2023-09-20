#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class books {
private:
    string author, title, publisher, genre, date;
    double price;
public:
    books(string a, string t, string p, string g, string d, double pr) : author(a), title(t), publisher(p), genre(g), date(d), price(pr) {}
    void search_books_by_author(string author_name) {
        if (author.find(author_name) != string::npos) {
            cout << title << endl;
        } else {
            cout << "Книги этого автора не найдены" << endl;
        }
    }
};

int main() {
	SetConsoleOutputCP(65001);
    books book1("Tolstoy", "Война и мир", "Эксмо", "Роман", "01.01.1869", 1000);
    books book2("Достоевский Ф.М.", "Преступление и наказание", "АСТ", "Роман", "01.01.1866", 800);

    string author;
    cout << "Введите фамилию автора: ";
    getline(cin, author);

    book1.search_books_by_author(author);
    book2.search_books_by_author(author);

    return 0;
}