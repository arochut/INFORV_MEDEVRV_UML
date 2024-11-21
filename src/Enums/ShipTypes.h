// Enum of all boat that need to be created in the game
enum class ShipTypes
{
    BATTLESHIP,
    CRUISER,
    DESTROYER,
    SUBMARINE_1,
    SUBMARINE_2,
    FISHING_1,
    FISHING_2,
};

// Create a map of boat types to their respective sizes
std::map<ShipTypes, int> shipSizes = {
    {ShipTypes::BATTLESHIP, 5},
    {ShipTypes::CRUISER, 4},
    {ShipTypes::DESTROYER, 3},
    {ShipTypes::SUBMARINE_1, 2},
    {ShipTypes::SUBMARINE_2, 2},
    {ShipTypes::FISHING_1, 1},
    {ShipTypes::FISHING_2, 1},
};

// And their names
std::map<ShipTypes, std::string> shipNames = {
    {ShipTypes::BATTLESHIP, "Battleship"},
    {ShipTypes::CRUISER, "Cruiser"},
    {ShipTypes::DESTROYER, "Destroyer"},
    {ShipTypes::SUBMARINE_1, "Submarine 1"},
    {ShipTypes::SUBMARINE_2, "Submarine 2"},
    {ShipTypes::FISHING_1, "Fishing 1"},
    {ShipTypes::FISHING_2, "Fishing 2"},
};


#endif // ShipTypes_H
