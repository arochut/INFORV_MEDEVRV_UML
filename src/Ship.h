

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

    int get_x_start();
    void set_x_start(int _x);
    int get_y_start();
    void set_y_start(int _y);
    int get_size();
    void set_size(int _size);
    Direction get_dir();
    void set_dir(Direction _dir);
    string get_name();
    void set_name(string _name);
    vector<bool> get_hits();
    void set_hits(vector<bool> _hits);
};