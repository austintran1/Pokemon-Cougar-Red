#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Pokemon {
protected:
    string name;
    int level;
    int hp;
    int xp;
    int maxHp;
    

public:
    Pokemon(const string& name) : name(name), level(1), xp(0), hp(50), maxHp(50) {}

    virtual ~Pokemon() {}

    virtual void heal(){
        cout<<name<<" is fully healed!"<<endl;
        hp= maxHp;
    }
    virtual void attack(Pokemon& other)= 0;
    virtual void specialMove(Pokemon& other)= 0;
    
    int getHealth() const{     //grab the private variable
        return hp;
    }
    void setHealth(int newHp){
        hp= newHp;
    }
    void gainXP(int amount){
        xp+= amount;
        while(xp >= 100){
            xp-= 100;
            level++;
            maxHp+= 20;
            hp= maxHp;
            cout<<name<<" leveled up to "<<level<<"!"<<endl;
            evolve();
        }
    }

    bool isFainted() const{ 
        return hp <= 0; 
    }
    void printStats() const{
        cout<<name <<" - HP: "<<hp<<"/"<<maxHp<<" | Level: "<<level<<" | XP: "<<xp<<endl;
    }
    virtual void evolve(){
        if (level == 5 || level == 10){
            cout<<name<<" is evolving!"<<endl;
        }
    }


    const string& getName() const{ 
        return name; 
    }

    virtual void save(const string& fname) const {
        ofstream fout(fname);
        if (!fout.is_open())
    {
        
        cout << "File not found!" << endl;
        return;
    }
        
        fout<<name<<' ' <<level<<' ' <<hp<<' ' <<maxHp <<' '<<xp<<endl;       //new file created with info in this order 
        
    }

    virtual void load(const string& fname) {
        ifstream fin(fname);
        if (!fin.is_open())
    {
        
        cout << "File not found!" << endl;
        return;
    }
        
        fin>>name>>level>>hp>>maxHp>> xp;
        
    }
};