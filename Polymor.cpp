//polymorphism 
#include <stdio.h>
#include <iostream>

using namespace std;

class enemy
{
protected:
    int attackPower=33;

public:
    int setAttackPower(int x)
    {   
        int y =x;
        attackPower = y;
    }
    void virtual attack(){};
};
class ninja : public enemy
{
public:
    void attack()
    {
        cout << "Ninja Has Attacked : "<<attackPower;
    }
};
class robber : public enemy
{
public:
    void attack()
    {
        cout << "Robber Has attacked : "<<attackPower;
    }
};
int main()
{

    //////////////////////////POLYMORPHISM/////////////////////////////////
    robber r;
    ninja n;
    enemy *enemy1 = &r;
    enemy *enemy2 = &n;

    enemy1->setAttackPower(25);
    enemy2->setAttackPower(55);

    // Now that the values are set I need to call the function through object 

    // r.attack();
    // cout << endl
    //      << endl;
    // n.attack(); 

    //But if I want to keep using the same pointer and call the functions through it is not possible
    //So I will use virtual function in the parent class and it will allow the pointer to use the same function through the child classes

    enemy1->attack();
    cout << endl
         << endl;
    enemy2->attack(); 

    return 0;
}
