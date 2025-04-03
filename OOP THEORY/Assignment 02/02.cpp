#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ghost {
protected:
    string workerName;
    int scareLevel;
public:
    Ghost(string name) : workerName(name), scareLevel(rand() % 10 + 1) {}
    virtual void haunt() const = 0;
    virtual ~Ghost() {}
    
    int getScareLevel() const { return scareLevel; }
    
    friend ostream& operator<<(ostream& os, const Ghost& g) {
        os << "Ghost played by " << g.workerName << " with scare level " << g.scareLevel;
        return os;
    }
    
    Ghost& operator+(const Ghost& other) {
        this->scareLevel += other.scareLevel;
        this->workerName += " & " + other.workerName;
        return *this;
    }
};

class Poltergeist : public virtual Ghost {
public:
    Poltergeist(string name) : Ghost(name) {}
    void haunt() const override {
        cout << workerName << " (Poltergeist) moves objects eerily!" << endl;
    }
};

class Banshee : public virtual Ghost {
public:
    Banshee(string name) : Ghost(name) {}
    void haunt() const override {
        cout << workerName << " (Banshee) screams loudly!" << endl;
    }
};

class ShadowGhost : public virtual Ghost {
public:
    ShadowGhost(string name) : Ghost(name) {}
    void haunt() const override {
        cout << workerName << " (ShadowGhost) whispers creepily..." << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost {
public:
    ShadowPoltergeist(string name) : Ghost(name), Poltergeist(name), ShadowGhost(name) {}
    void haunt() const override {
        Poltergeist::haunt();
        ShadowGhost::haunt();
    }
};

class Visitor {
public:
    string name;
    int bravery;
    
    Visitor(string n, int b) : name(n), bravery(b) {}
    
    void reactToScare(int ghostScare) {
        if (ghostScare < bravery)
            cout << name << " laughs and taunts the ghost!" << endl;
        else if (ghostScare > bravery)
            cout << name << " screams and runs away!" << endl;
        else
            cout << name << " gets a shaky voice but stays!" << endl;
    }
};

class HauntedHouse {
public:
    string name;
    Ghost* ghosts[3];
    int ghostCount;
    
    HauntedHouse(string n) : name(n), ghostCount(0) {}
    
    void addGhost(Ghost* g) {
        if (ghostCount < 3) {
            ghosts[ghostCount++] = g;
        }
    }
    
    void simulateVisit(Visitor visitors[], int visitorCount) {
        cout << endl << "Visiting " << name << "..." << endl;
        for (int i = 0; i < visitorCount; i++) {
            cout << visitors[i].name << " enters the haunted house..." << endl;
            for (int j = 0; j < ghostCount; j++) {
                ghosts[j]->haunt();
                visitors[i].reactToScare(ghosts[j]->getScareLevel());
            }
            cout << "-----------------------------" << endl;
        }
    }
    
    ~HauntedHouse() {
        for (int i = 0; i < ghostCount; i++) delete ghosts[i];
    }
};

int main() {
    srand(time(0));
    
    HauntedHouse house1("House 1");
    house1.addGhost(new Poltergeist("Hanzala"));
    house1.addGhost(new Banshee("Ali"));
    
    HauntedHouse house2("House 2");
    house2.addGhost(new ShadowGhost("Zahid"));
    house2.addGhost(new ShadowPoltergeist("Saad"));
    
    Visitor visitors[] = {
        Visitor("Azan", 3),
        Visitor("Ibrahim", 6),
        Visitor("Ahmed", 9)
    };
    
    house1.simulateVisit(visitors, 3);
    house2.simulateVisit(visitors, 3);
    
    return 0;
}