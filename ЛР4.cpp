#include <iostream>
#include <string>
using namespace std;

class Creature {
protected:
    string species;
public:
    Creature() : species("Creature") {}
    Creature(string s) : species(s) {}
    virtual void print() {
        cout << "Species: " << species << endl;
    }
};

class Mythical {
protected:
    string origin;
public:
    Mythical() : origin("Unknown") {}
    Mythical(string o) : origin(o) {}
    virtual void print() {
        cout << "Origin: " << origin << endl;
    }
};

class Gorgon : public Creature, public Mythical {
protected:
    string name;
    string power;
public:
    Gorgon() : Creature("Gorgon"), Mythical("Greek mythology"), name("Medusa"), power("Petrification") {}
    Gorgon(string s, string o, string n, string p) : Creature(s), Mythical(o), name(n), power(p) {}
    void print() override {
        Creature::print();
        Mythical::print();
        cout << "Name: " << name << endl;
        cout << "Power: " << power << endl;
    }
};

int main(){
    Gorgon g1;
    g1.print();
    cout << endl;

    Gorgon g2("Snake woman", "Ancient folklore", "Euryale", "Immortality");
    g2.print();

    return 0;
}