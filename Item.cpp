#include <iostream>
#include <string>
#include "Item.h"
using namespace std;
/**
 * Item class represents an item that can be picked up and dropped through out the game.
 * 
 * @author Caitlin Snyder
 * @version 2013.10.09
 */

    /**
     * Create an item described "description".
     */
    Item::Item(string n, string descript, int w)
    {
        name = n;
        description = descript;
        weight = w;
    }
    
    /**
     * Returns a short description of the item.
     */
    string Item::getDescription()
    {
       return description; 
    }
    
    
    /**
     * Returns the weight of the item.
     */
    int Item::getWeight()
    {
        return weight;
    }
    
    /**
     * Returns the name of the item.
     */
    string Item::getName()
    {
        return name;
    }



