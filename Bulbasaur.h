#pragma once
#include "Pokemon.h"
#include<iostream>
using namespace std;

class Bulbasaur : public Pokemon {
public:
    Bulbasaur(const string& name): Pokemon(name) {
        maxHp= 65;
        hp= maxHp;
    }

    void attack(Pokemon& other) override {
        int damage=7+ level * 2;
        cout<<name<<" uses vine whip for "<<damage<<" damage!"<<endl;
        other.setHealth(other.getHealth()- damage);  
    }

    void specialMove(Pokemon& other) override {
        int probability = rand()%100;
        if(probability<=45){          //might change probabiltiy 
        int damage = 16 + level * 3;
        cout<<name<<" uses Razor Leaf for "<<damage<< " damage!"<<endl;
        other.setHealth(other.getHealth()- damage);
    }
    else{
        cout<<name<<"'s Razor Leaf missed!"<<endl;       //if the random number selected is 51 or more
    }
}

    void heal() override {
        cout<<name<<" drank a healing potion and is fully healthy"<<endl;
        setHealth(maxHp); 
    }

    void evolve() override {
        Pokemon::evolve();
        if (level== 5){
             name= "Ivysaur";
             cout<<name<<" has evolved into Ivysaur"<<endl;
             cout<<R"(
                   ,'"`.,./.
                             ,'        Y',"..
                           ,'           \  | \
                          /              . |  `
                         /               | |   \
            __          .                | |    .
       _   \  `. ---.   |                | j    |
      / `-._\   `Y   \  |                |.     |
     _`.    ``    \   \ |..              '      |,-'""7,....
     l     '-.     . , `|  | , |`. , ,  /,     ,'    '/   ,'_,.-.
     `-..     `-.  : :     |/ `   ' "\,' | _  /          '-'    /___
      \""' __.,.-`.: :        /   /._    l'.,'
       `--,   _.-' `".           /__ `'-.' '         .
       ,---..._,.--"""""""--.__..----,-.'   .  /    .'   ,.--
       |                          ,':| /    | /     ;.,-'--      ,.-
       |     .---.              .'  :|'     |/ ,.-='"-.`"`' _   -.'
       /    \    /               `. :|--.  _L,"---.._        "----'
     ,' `.   \ ,'           _,     `''   ``.-'       `-  -..___,'
    . ,.  .   `   __     .-'  _.-           `.     .__    \
    |. |`        "  ;   !   ,.  |             `.    `.`'---'
    ,| |C\       ` /    | ,' |(]|            -. |-..--`
   /  "'--'       '      /___|__]        `.  `- |`.
  .       ,'                   ,   /       .    `. \
    \                      .,-'  ,'         .     `-.
     x---..`.  -'  __..--'"/"""""  ,-.      |   |   |
    / \--._'-.,.--'     _`-    _. ' /       |     -.|
   ,   .   `-..__ ...--'  _,.-' | `   ,.-.  ;   /  '|
  .  _,'         '"-----""      |    `   | /  ,'    ;
  |-'  .-.    `._               |     `._// ,'     /
 _|    `-'   _,' "`--.._________|        `,'    _ /.
//\   ,-._.'"/\__,.   _,"     /_\__/`. /'.-.'.-/_,`-' 
`-"`"' v'    `"  `-`-"              `-'`-`  `'
             )"<<endl;
        }
        else if (level == 10){
            name= "Venusaur";
            cout<<name<< "has evolved into Venusaur!"<<endl;
            cout<<R"(
                            _._       _,._
                        _.'   `. ' .'   _`.
                ,"""/`""-.-.,/. ` V'\-,`.,--/"""."-..
              ,'    `...,' . ,\-----._|     `.   /   \
             `.            .`  -'`"" .._   :> `-'   `.
            ,'  ,-.  _,.-'| `..___ ,'   |'-..__   .._ L
           .    \_ -'   `-'     ..      `.-' `.`-.'_ .|
           |   ,',-,--..  ,--../  `.  .-.    , `-.  ``.
           `.,' ,  |   |  `.  /'/,,.\/  |    \|   |
                `  `---'    `j   .   \  .     '   j
              ,__`"        ,'|`'\_/`.'\'        |\-'-, _,.
       .--...`-. `-`. /    '- ..      _,    /\ ,' .--"'  ,'".
     _'-""-    --  _`'-.../ __ '.'`-^,_`-""""---....__  ' _,-`
   _.----`  _..--.'        |  "`-..-" __|'"'         .""-. ""'--.._
  /        '    /     ,  _.+-.'  ||._'   """". .          `     .__\
 `---    /        /  / j'       _/|..`  -. `-`\ \   \  \   `.  \ `-..
," _.-' /    /` ./  /`_|_,-"   ','|       `. | -'`._,   L  \ .  `.   |
`"' /  /  / ,__...-----| _.,  ,'            `|----.._`-.|' |. .` ..  .
   /  '| /.,/   \--.._ `-,' ,          .  '`.'  __,., '  ''``._ \ \`,'
  /_,'---  ,     \`._,-` \ //  / . \    `._,  -`,  / / _   |   `-L -
   /       `.     ,  ..._ ' `_/ '| |\ `._'       '-.'   `.,'     |
  '         /    /  ..   `.  `./ | ; `.'    ,"" ,.  `.    \      |
   `.     ,'   ,'   | |\  |       "        |  ,'\ |   \    `    ,L
   /|`.  /    '     | `-| '                  /`-' |    L    `._/  \
  / | .`|    |  .   `._.'                   `.__,'   .  |     |  (`
 '-""-'_|    `. `.__,._____     .    _,        ____ ,-  j     ".-'"'
        \      `-.  \/.    `"--.._    _,.---'""\/  "_,.'     /-'
         )        `-._ '-.        `--"      _.-'.-""        `.
        ./            `,. `".._________...""_.-"`.          _j
       /_\.__,"".   ,.'  "`-...________.---"     .".   ,.  / \
              \_/"""-'                           `-'--(_,`"`-` 

            )"<<endl;
    }
}
};

