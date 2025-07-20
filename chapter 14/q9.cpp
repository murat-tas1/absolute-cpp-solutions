#include <iostream>
using namespace std;

class Creature{
    public:
    Creature( ); // Initialize to human, 10 strength, 10 hit points
    Creature(int newType, int newStrength, int newHit); // Initialize creature to new type, strength, hit points
    int getDamage();
    void setHitpoints(int newHitpoint);
    int getHitpoints() const;
    void setType(int newType);
    int getType() const;
    void setStrength(int newStrength);
    int getStrenght() const;
    private:
     int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
     int strength; // How much damage we can inflict 
     int hitpoints; // How much damage we can sustain 
     string getSpecies(); // Returns type of species 

};

int main(){
    return 0;
}