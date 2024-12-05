

#ifndef SHIP_H
#define SHIP_H

#include "Enums/Direction.h"
#include <vector>
#include <string>


using namespace std;


/// @brief Class that represents a ship
class Ship {

private:
    /// @brief x_start is the x coordinate of the top left corner of the ship
    int x_start;
    /// @brief y_start is the y coordinate of the top left corner of the ship
    int y_start;

    /// @brief size is the number of squares the ship occupies
    int size;

    /// @brief dir is the direction of the ship (Horizontal or Vertical)
    Direction dir;

    /// @brief name is the name of the ship
    string name;

    /// @brief hits is a vector of booleans that indicates if a ship is hit at a certain position
    vector<bool> hits;
    // int hit_score;

public:
    /// @brief Constructor for ship
    /// @param x the x coordinate of the top left corner of the ship
    /// @param y the y coordinate of the top left corner of the ship
    /// @param size the number of squares the ship occupies
    /// @param dir the direction of the ship (Horizontal or Vertical)
    /// @param name the name of the ship
    Ship(int x, int y, int size, Direction dir, string name);

    /// @brief Check if the ship is dead
    /// @return true if the ship is dead, false otherwise
    bool is_dead();

    /// @brief Check if the ship occupies a certain position
    /// @param x the x coordinate of the position
    /// @param y the y coordinate of the position
    /// @return true if the ship occupies the position, false otherwise
    bool occupies(int x, int y);

    /// @brief Tries to hit at a certain position, if the ship occupies the position, the ship is hit
    /// @param x the x coordinate of the position
    /// @param y the y coordinate of the position
    /// @return true if the ship is hit at the position, false otherwise
    bool hit(int x, int y);

    /// @brief Check if the ship is hit at a certain position
    /// @param x the x coordinate of the position
    /// @param y the y coordinate of the position
    /// @return true if the ship is hit at the position, false otherwise
    bool is_hit(int x, int y);

    /// @brief Get the x_start object
    /// @return the x coordinate of the top left corner of the ship
    int get_x_start();

    /// @brief Set the x_start object
    /// @param _x the x coordinate of the top left corner of the ship
    void set_x_start(int _x);

    /// @brief Get the y_start object
    /// @return the y coordinate of the top left corner of the ship
    int get_y_start();

    /// @brief Set the y_start object
    /// @param _y the y coordinate of the top left corner of the ship
    void set_y_start(int _y);

    /// @brief Get the size object
    /// @return the number of squares the ship occupies
    int get_size();

    /// @brief Set the size object
    /// @param _size the number of squares the ship occupies
    void set_size(int _size);

    /// @brief Get the dir object
    /// @return the direction of the ship (Horizontal or Vertical)
    Direction get_dir();

    /// @brief Set the dir object
    /// @param _dir the direction of the ship (Horizontal or Vertical)
    void set_dir(Direction _dir);

    /// @brief Get the name object
    /// @return the name of the ship
    string get_name();

    /// @brief Set the name object
    /// @param _name the name of the ship
    void set_name(string _name);

    /// @brief Get the hits object
    /// @return the vector of booleans that indicates if a ship is hit at a certain position
    vector<bool> get_hits();

    /// @brief Set the hits object
    /// @param _hits the vector of booleans that indicates if a ship is hit at a certain position
    void set_hits(vector<bool> _hits);
};

#endif