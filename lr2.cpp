#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Institute {
protected:
    string name;
public:
    Institute() : name("Институт") {}
    Institute(string n) : name(n) {}
    virtual void print() {
        cout << "Институт: " << name << endl;
    }
};

class FormOfEducation : public Institute {
protected:
    string form;
public:
    FormOfEducation() : Institute(), form("Форма обучения") {}
    FormOfEducation(string n, string f) : Institute(n), form(f) {}
    void print() override {
        Institute::print();
        cout << "Форма обучения: " << form << endl;
    }
};

class Group : public FormOfEducation {
protected:
    string group;
public:
    Group() : FormOfEducation(), group("Группа") {}
    Group(string n, string f, string g) : FormOfEducation(n, f), group(g) {}
    void print() override {
        FormOfEducation::print();
        cout << "Группа: " << group << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    Group g1;
    Group g2("Инженерный институт", "Очная", "ИТ-101");

    g1.print();
    cout << endl;
    g2.print();

    return 0;
}
