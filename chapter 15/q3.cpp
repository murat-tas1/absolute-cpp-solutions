#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int GRID_SIZE = 20;
const int INITIAL_ANT = 100;
const int INITIAL_DOODLEBUG = 5;
class Organism;
Organism* grid[GRID_SIZE][GRID_SIZE] = {nullptr};
class Organism{
    public:
    Organism(int newRow,int newCol);
    virtual void move() = 0;
    virtual void breed() = 0;
    ~Organism();
    protected:
    int currentRow;
    int currentColumn;
    int prevRow;
    int prevCol;
    void setMove(); //helper function
};
class Ant:public Organism{
    public:
    Ant(int newRow,int newCol);
    virtual void move();
    virtual void breed();
};
class Doodlebug:public Organism{
    public:
    Doodlebug(int newRow,int newCol);
    virtual void move();
    virtual void breed();
    void starve();
    private:
    bool hasEaten;
};
void Organism::setMove(){
    char dir[] = {'u','d','l','r'};
    int step = rand() % 4;
    prevRow = currentRow;
    prevCol = currentColumn;
    switch(dir[step]){
        case 'u':
        --currentRow;
        break;
        case 'd':
        ++currentRow;
        break;
        case 'l':
        --currentColumn;
        break;
        case 'r':
        ++currentColumn;
    }
}
Organism::Organism(int newRow,int newCol):currentRow(newRow),currentColumn(newCol){}


Ant::Ant(int newRow,int newCol):Organism(newRow,newCol){}
void Ant::move(){
    setMove();
    if((currentRow >= 0 && currentRow<20) && (currentColumn>=0 && currentColumn < 20) && grid[currentRow][currentColumn] == nullptr ){
        grid[currentRow][currentColumn] == grid[prevRow][prevCol];
        grid[prevRow][prevCol] = nullptr;
    }
    else{
        currentRow = prevRow;
        currentColumn = prevCol;
    }
}
void Ant::breed(){
    //if up is available
    if(grid[currentRow - 1][currentColumn] == nullptr)
    grid[currentRow - 1][currentColumn] = new Ant(currentRow - 1,currentColumn);
    else if(grid[currentRow + 1][currentColumn] == nullptr)
    // if down is available
    grid[currentRow + 1][currentColumn] = new Ant(currentRow + 1,currentColumn);
    // if left is available
    else if(grid[currentRow][currentColumn - 1] == nullptr)
    grid[currentRow][currentColumn - 1] = new Ant(currentRow,currentColumn - 1);
    // if right is available
    else if(grid[currentRow][currentColumn + 1] == nullptr)
    grid[currentRow][currentColumn + 1] = new Ant(currentRow,currentColumn + 1);
    
}

Doodlebug::Doodlebug(int newRow,int newCol):Organism(newRow,newCol),hasEaten(false){}


void Doodlebug::move(){
    //if up is available
    if(currentRow - 1>=0 && dynamic_cast<Ant*>(grid[currentRow - 1][currentColumn])){
    delete grid[currentRow - 1][currentColumn];
    grid[currentRow - 1][currentColumn] = this;
    hasEaten = true;
    }
    // if down is available
    else if(currentRow + 1 < 20 && dynamic_cast<Ant*>(grid[currentRow + 1][currentColumn])){
    delete grid[currentRow + 1][currentColumn];
    grid[currentRow + 1][currentColumn] = this;
    hasEaten = true;
    }
   // if left is available and contains an Ant
   else if(currentColumn - 1>= 0 && dynamic_cast<Ant*>(grid[currentRow][currentColumn - 1])) {
    delete grid[currentRow][currentColumn - 1]; // delete the existing Ant
    grid[currentRow][currentColumn - 1] = this; // move this object to that position
    hasEaten = true;
}
    // if right is available and contains an Ant
    else if(currentColumn + 1 < 20 && dynamic_cast<Ant*>(grid[currentRow][currentColumn + 1])) {
    delete grid[currentRow][currentColumn + 1]; // delete the existing Ant
    grid[currentRow][currentColumn + 1] = this; // move this object to that position
    hasEaten = true;
}
else{
    setMove();
    if(grid[currentRow][currentColumn] == nullptr || ((currentRow >= 0 && currentRow<20) && (currentColumn>=0 && currentColumn < 20))){
        grid[currentRow][currentColumn] = grid[prevRow][prevCol];
        grid[prevRow][prevCol] = nullptr;
    }
    else{
        currentRow = prevRow;
        currentColumn = prevCol;
    }
}
}
void Doodlebug::breed(){
    //if up is available
    if(grid[currentRow - 1][currentColumn] == nullptr)
    grid[currentRow - 1][currentColumn] = new Doodlebug(currentRow - 1,currentColumn);
    else if(grid[currentRow + 1][currentColumn] == nullptr)
    // if down is available
    grid[currentRow + 1][currentColumn] = new Doodlebug(currentRow + 1,currentColumn);
    // if left is available
    else if(grid[currentRow][currentColumn - 1] == nullptr)
    grid[currentRow][currentColumn - 1] = new Doodlebug(currentRow,currentColumn - 1);
    // if right is available
    else if(grid[currentRow][currentColumn + 1] == nullptr)
    grid[currentRow][currentColumn + 1] = new Doodlebug(currentRow,currentColumn + 1);
    
}
void Doodlebug::starve(){
    delete grid[currentRow][currentColumn];
}

void initalize(){
    // insert doodlebugs on the grid
    for(int i = 0; i < INITIAL_DOODLEBUG;++i){
        int newRow;
        int newCol;
        do{
            newRow = rand() % GRID_SIZE;
            newCol = rand() % GRID_SIZE;
            grid[newRow][newCol] = new Doodlebug(newRow,newCol);
        }while(grid[newRow][newCol] !=nullptr);
    }
    //insert ants on the grid
        for(int i = 0; i < INITIAL_ANT;++i){
        int newRow;
        int newCol;
        do{
            newRow = rand() % GRID_SIZE;
            newCol = rand() % GRID_SIZE;
            grid[newRow][newCol] = new Ant(newRow,newCol);
        }while(grid[newRow][newCol] !=nullptr);
    }
}

void simulate(){
    int step = 0;
    //first move all doodlebugs before ants
    for(int i = 0; i < GRID_SIZE;++i){
        for(int j = 0; j < GRID_SIZE;++j){
            if(dynamic_cast<Doodlebug*>(grid[i][j])){
                grid[i][j]->move();
            }
        }
    }
    // move all ants
        for(int i = 0; i < GRID_SIZE;++i){
        for(int j = 0; j < GRID_SIZE;++j){
            if(dynamic_cast<Ant*>(grid[i][j])){
                grid[i][j]->move();
            }
        }
    }
    
}