#include "includes.h"

int main(int argc, char** argv)
{
    string name;
    char action;
    
    cout << "Welcome to Monster Slayer" << endl;
    
    getchar();
    
    cout << "What's your name?" << endl;
    cout << "Name: ";
    cin >> name;
    
    cout << "Good Luck " << name << endl;
    
    getchar();
    
    Player* player = new Player(name, 100);
    Monster* monster = new Monster(250);
    
    getchar();
    
    while(player->getHP() > 0 && monster->getHP() > 0)
    {
        system("clear");
        
        cout << player->getName() << " has " << player->getHP() << " HP." << endl;
        cout << "The monster has " << monster->getHP() << " HP.\n" << endl;
        
        PrintMenu();
        cin >> action;
        
        switch(action)
        {
            case '1':
                Attack(player, monster);
                break;
            case '2':
                Block(player, monster);
                break;
            case '3':
                Heal(player, monster);
                break;
            case '4':
                GiveUp(player);
                break;
            default:
                break;
        }
        
        getchar();
    }
    
    if(player->getHP() <= 0)
        Defeat();
    else if(monster->getHP() <= 0)
        Victory();

    return 0;
}