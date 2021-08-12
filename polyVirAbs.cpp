//polymorphism
//The program will throw error on Robber because in the Robber class the function has not been overriden please uncomment the function
#include <stdio.h>
#include <iostream>

using namespace std;

class enemy
{
protected:
    int attackPower;

public:
    void setAttackPower(int x)
    {
        attackPower = x;
    }
    virtual void attack() {}
    virtual void defence() = 0; // pure virtual function
    // because of this pure virtual function this class is now an abstract class.
};

class ninja : public enemy
{
public:
    void attack()
    {
        cout << "Ninja Has Attacked : " << attackPower << endl;
    }
    void defence()
    {
        cout << "I am a Ninja and I can Defend myself.. "<< endl;
    }
};

class robber : public enemy
{
public:
    void attack()
    {
        cout << "Robber Has attacked : " << attackPower;
    }

    void defence()
    {
        cout << "I am a Robber and I can not Defend myself.. " << endl;
    }
};

int main()
{

    robber r;
    ninja n;
    enemy *enemy1 = &r;
    enemy *enemy2 = &n;
    int x;
    enemy1->setAttackPower(25);
    enemy2->setAttackPower(55);
    cout<<"The program will throw error on Robber because in the Robber class the function has not been overriden\n";
    cout << "\n Press 1 to access Robber and 2 to access Ninja :" << endl;
    cin >> x;
    if (x == 1)
    {
        enemy1->attack();
        cout << endl;
        enemy1->defence();
    }
    else if (x == 2)
    {

        cout << endl;
        enemy2->attack();
        cout << endl;
        enemy2->defence();
    }

    return 0;
}
