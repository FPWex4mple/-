#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class University{
	protected:
		string name;
	public:
		University() : name("University"){}
		University(string n) : name(n){}
		virtual void print() = 0;
		virtual ~University(){
			cout << "Деструктор University" << endl;
		}
};

class FormOfEducation : public University{
	protected:
		string form;
	public:
		FormOfEducation() : University(), form("Form of education"){}
		FormOfEducation(string n, string f) : University(n), form(f){}
		void print() override{
			cout << "University: " << name << endl;
			cout << "Form of education: " << form << endl;
		}
		virtual ~FormOfEducation(){
			cout << "Деструктор FormOfEducation" << endl;
		}
};

class Group : public FormOfEducation{
	protected:
		string group;
	public:
		Group() : FormOfEducation(), group("Group"){}
		Group(string n, string f, string g) : FormOfEducation(n, f), group(g){}
		void print() override{
			cout << "University: " << name << endl;
			cout << "Form of education: " << form << endl;
			cout << "Group: " << group << endl;
		}
		virtual ~Group(){
			cout << "Деструктор Group" << endl;
		}
};

int main(){
	SetConsoleOutputCP(65001);
    University *u1 = new Group();
    u1->print();
    delete u1;

    University *u2 = new FormOfEducation("Information System", "Full-time education");
    u2->print();
    delete u2;

    return 0;
}