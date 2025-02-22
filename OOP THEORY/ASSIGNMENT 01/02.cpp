#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ball
{
    int x, y;

public:
    Ball() : x(0), y(0) {}

    void move(int cx, int cy)
    {
        x += cx;
        y += cy;
    }

    int getx() const { return x; }
    int gety() const { return y; }

    void getposition() const
    {
        cout << "Ball Position : " << x << "," << y << endl;
    }
};

class Goal
{
    int x, y;

public:
    Goal() : x(5), y(5) {} // goal fix at 5,5

    bool GoalReached(int ballx, int bally)
    {
        return (ballx == x && bally == y);
    }
};

class Robot
{
    string name;
    int hits;

public:
    Robot(string rname) : name(rname), hits(0) {}

    void HitBall(Ball &ball, const string &direction)
    {
        hits++;
        if (direction == "up")
        {
            ball.move(0, 1);
        }
        else if (direction == "down")
        {
            ball.move(0, -1);
        }
        else if (direction == "left")
        {
            ball.move(-1, 0);
        }
        else if (direction == "right")
        {
            ball.move(1, 0);
        }
        cout << name << "hit the ball" << direction << ". Hits : " << hits << endl;
    }

    int gethits() const { return hits; }
    string getname() const { return name; }
};

class Team
{
    string TeamName;
    Robot *robot;

public:
    Team(string name, Robot *r) : TeamName(name), robot(r) {}

    string getteamname() const { return TeamName; }
    Robot *getrobot() const { return robot; }
};

class Game
{
    Team *t1;
    Team *t2;
    Ball b;
    Goal g;

public:
    Game(Team *team1, Team *team2) : t1(team1), t2(team2) {}

    void play(Team *team)
    {
        cout << team->getteamname() << "is playing" << endl;
        Robot *robot = team->getrobot();
        b.getposition();

        while (!g.GoalReached(b.getx(), b.gety()))
        {
            string direction[] = {"up", "down", "left", "right"};
            string dir = direction[rand() % 4];
            robot->HitBall(b,dir);
            b.getposition();
        }
        cout << team->getteamname() << "reached goal in" << robot->gethits() << "hits" << endl;
    }

    void StartGame()
    {
        srand(time(0));
        play(t1);
        b = Ball();
        play(t2);
        DeclareWin();
    }

    void DeclareWin()
    {
        int hits1 = t1->getrobot()->gethits();
        int hits2 = t2->getrobot()->gethits();

        if (hits1 < hits2)
        {
            cout << t1->getteamname() << "wins" << endl;
        }
        else if (hits1 > hits2)
        {
            cout << t2->getteamname() << "wins" << endl;
        }
        else
        {
            cout << "tie" << endl;
        }
    }
};

int main()
{
    Robot r1("Orca"), r2("Livyatan");
    Team t1("Madrid", &r1), t2("Barca", &r2);

    Game game(&t1, &t2);
    game.StartGame();
    
    return 0;
}