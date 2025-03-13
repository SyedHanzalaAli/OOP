#include <iostream>
using namespace std;

class Character {
    protected: 
        int health;
        int damage;
    public:
        Character(int h , int d) : health(h) , damage (d) {}
        
        void displaychar(){
            cout << "Health"  << health << endl;
            cout << "Damage"  << damage << endl;
        }
};

class Player : public Character {
    public:
        Player(int h , int d) : Character(h,d) {}

        void displayplay(){
            cout << "Health"  << health << endl;
            cout << "Damage"  << damage << endl;
        }
};

class Enemy : public Character {
    public:
        Enemy(int h , int d) : Character(h,d) {}

        void displayenem(){
            cout << "Health"  << health << endl;
            cout << "Damage"  << damage << endl;
        }
};

class Wizard : public Player{
    int magic;
    public:
    Wizard(int h , int d ,  int m) : Player(h,d) , magic(m) {}

    void displaywiz(){
        cout << "Health"  << health << endl;
        cout << "Damage"  << damage << endl;
        cout << "Magic " << magic << endl;
    }
};

int main(){
    Character c1(150 , 20);
    Player p1(130 , 25);
    Enemy e1(86 , 13);
    Wizard w1(130,14,78);

    c1.displaychar();
    p1.displayplay();
    e1.displayenem();
    w1.displaywiz();

    return 0;
}