

#include "Direction.h"
#include <vector>
#include <string>

class Ship {

private:
    int x_start;
    int y_start;
    int size;
    Direction dir;

    string name;
    vector<bool> hits;
    // int hit_score;

public:
    Ship(int x, int y, int size, Direction dir, string name);
    bool is_dead();
    bool occupies(int x, int y);
    bool hit(int x, int y);

    
}