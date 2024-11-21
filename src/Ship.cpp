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