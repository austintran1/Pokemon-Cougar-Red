#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Charmander.h"
#include "Squirtle.h"
#include "Bulbasaur.h"
#include <sstream>
using namespace std;


Pokemon* choosePokemon() {
    cout<<"Choose your Pokémon:"<<endl;
    cout<<"1. Charmander"<<endl;
    cout<<"2. Squirtle"<<endl;
    cout<<"3. Bulbasaur"<<endl;
    int choice;
    cin>> choice;
    string name;
    cout<<"Enter a name: ";
    cin>>name;

    switch (choice) {
        case 1: return new Charmander(name);  
        case 2: return new Squirtle(name);    
        case 3: return new Bulbasaur(name);   
        default: return new Charmander(name); 
    }
}


Pokemon* randomOpponent() {
    int r = rand() % 3;          //33% to get a certain pokemon
    if (r == 0){
     return new Charmander("Wild Charmander");
    }
    if (r == 1){
         return new Squirtle("Wild Squirtle");
    }
    else{
        return new Bulbasaur("Wild Bulbasaur");
    }
}


void battle(Pokemon* player, Pokemon* enemy) {
    while (!player->isFainted() && !enemy->isFainted()) {          //print after each round of attacks
        cout<< "-- Your Turn --"<<endl;
        player->printStats();                    
        enemy->printStats();
        cout<<"1. Attack"<<endl;
        cout<<"2. Special Move"<<endl;
        int move;
        cin>> move;
        if(move==0){
            cout<<"Invalid Choice"<<endl;
        }
        if (move == 1){
             player->attack(*enemy);
        }
        else{
             player->specialMove(*enemy);
        }

        if (enemy->isFainted()) {
            cout<< enemy->getName()<<" fainted!"<<endl;
            player->gainXP(50);
            return;
        }

        cout<< "-- Enemy Turn --"<<endl;
        int enemyMove = rand() % 2;        //50% chance at each attack
        if (enemyMove == 1){
             enemy->attack(*player);
        }
        else{
         enemy->specialMove(*player);
        }

        if (player->isFainted()) {
            cout<<player->getName()<<"fainted!"<<endl;
            return;
        }
    }
}

int main() {
    srand(time(0));
    Pokemon* myPokemon = nullptr;
    int choice;

    while (true) {
      //  cout<< "--- Pokémon Game Menu ---"<<endl;
       // cout<<"1. Create New Pokémon"<<endl;
      //  cout<<"2. Load Pokémon from File"<<endl;
      //  cout<<"3. Battle"<<endl;
      //  cout<<"4. Save Pokémon to File"<<endl;;
      //  cout<<"5. Heal Pokémon"<<endl;;
      //  cout<<"6. Exit"<<endl;
        cout<<R"(
        _______________________________
        │  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄  │
        │ ▐                         ▌ │
        │ ▐--- Pokémon Game Menu —  ▌ │
        │ ▐  1. Pick your Pokémon   ▌ │
        │ ▐  2. Load File           ▌ │
        │ ▐  3. Battle              ▌ │
        │ ▐  4. Save File           ▌ │
        │ ▐  5. Heal                ▌ │
        │ ▐  6. Exit                ▌ │
        │ ▐                         ▌ │
        │ ▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ │
        │_____________________________│
        |                             │
        │    ▐▌                       │
        │   ▄▄▄▄               ● A    │      
        │    ▐▌            ● B        │
        │                             │
        │  [Select]     [Start]       │
        │_____________________________│
    )";
        cout<< "Enter your choice: ";
        cin>> choice;

        switch (choice) {
            case 1:
                myPokemon= choosePokemon();  
                break;

            case 2: {
                string file;
                cout<<"Filename to load: ";
               cin>> file;
                
                if(myPokemon){
                     delete myPokemon; 
                } 
                myPokemon= new Charmander("");  
                myPokemon->load(file);
                break;
            }

            case 3:
                if (myPokemon){
                    battle(myPokemon, randomOpponent());
                }
                else{
                    cout<<"No Pokémon selected!"<<endl;
                }
                break;

            case 4:
                if (myPokemon) {
                    string file;
                    cout<<"Filename to save: ";
                    cin>>file;
                    myPokemon->save(file);
                }
                break;

            case 5:
                if(myPokemon){

                 myPokemon->heal();
                }
                break;

            case 6:
                cout<<"Thank you for playing!"<<endl;
                if (myPokemon){
                 delete myPokemon;          
                }
                return 0;

            default:
                cout<<"Invalid choice."<<endl;
        }
    }
}
