#include <iostream>
using namespace std;

class BallsFaced;

class Runs{
    int runs;

    public:
       Runs(int r){
          runs = r;
       }
       friend float calculateStrikeRate(Runs r , BallsFaced b);
};

class BallsFaced{
    int balls;

    public:
       BallsFaced(int b){
          balls = b;
       }
       friend float calculateStrikeRate(Runs r , BallsFaced b);
};

float calculateStrikeRate(Runs r , BallsFaced b){
    return (static_cast<float>(r.runs)/b.balls)*100;
}

int main(){
    Runs r(100);
    BallsFaced b(50);

    float strikeRate = calculateStrikeRate(r,b);
    cout << strikeRate << endl;
    return 0;
}
