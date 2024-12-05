
#ifndef ShipTypes_H
#define ShipTypes_H

#include <string>
using namespace std;

/// @brief Struct that represents a ship type
struct ShipType {
    /// @brief name is the name of the ship type
    string name;
    /// @brief size is the size of the ship type
    int size; 
};

/// @brief Class that contains all the ship types
class ShipTypes
{
    
    public:
        static const ShipType BATTLESHIP;
        static const ShipType CRUISER;
        static const ShipType DESTROYER;
        static const ShipType SUBMARINE_1;
        static const ShipType SUBMARINE_2;
        static const ShipType FISHING_1;
        static const ShipType FISHING_2;
        // static const int SHIP_COUNT = 2;
        static const int SHIP_COUNT = 7;
        static const ShipType SHIP_TYPES[SHIP_COUNT];

    
};

#endif // ShipTypes_H
