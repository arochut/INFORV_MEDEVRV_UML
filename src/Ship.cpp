#include "Ship.h"
using namespace std;


Ship::Ship(int x, int y, int size, Direction dir, string name) {
    x_start = x;
    y_start = y;
    this->size = size;
    this->dir = dir;
    this->name = name;
    hits = vector<bool>(size, false);
}

bool Ship::is_dead() {
    for (int i = 0; i < size; i++) {
        if (!hits[i]) {
            return false;
        }
    }
    return true;
}

bool Ship::occupies(int x, int y) {
    if (dir == Direction::Horizontal) {
        if (x < x_start || x >= x_start + size) {
            return false;
        }
        return y == y_start;
    } else {
        if (y < y_start || y >= y_start + size) {
            return false;
        }
        return x == x_start;
    }
}

bool Ship::hit(int x, int y) {
    if (!occupies(x, y)) {
        return false;
    }
    if (dir == Direction::Horizontal) {
        hits[x - x_start] = true;
    } else {
        hits[y - y_start] = true;
    }
    return true;
}

int Ship::get_x_start()
{
    return x_start;
}

void Ship::set_x_start(int _x)
{
    x_start=_x;
}

int Ship::get_y_start()
{
    return y_start;
}

void Ship::set_y_start(int _y)
{
    y_start=_y;
}

int Ship::get_size()
{
    return size;
}

void Ship::set_size(int _size)
{
    size=_size;
}

Direction Ship::get_dir()
{
    return dir;
}

void Ship::set_dir(Direction _dir)
{
    dir=_dir;
}

string Ship::get_name()
{
    return name;
}

void Ship::set_name(string _name)
{
    name=_name;
}

vector<bool> Ship::get_hits()
{
    return hits;
}

void Ship::set_hits(vector<bool> _hits)
{
    hits=_hits;
}
