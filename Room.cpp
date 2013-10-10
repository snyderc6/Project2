#include <string>
#include <iostream>
#include <map>
#include "Room.h"
#include "Item.h"
using namespace std;

/**
 * Class Room - a room in an adventure game.
 *
 * This class is adapted from a part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 *
 * A "Room" represents one location in the scenery of the game.  It is 
 * connected to other rooms via exits.  For each existing exit, the room 
 * stores a reference to the neighboring room.
 * 
 * @author  Caitlin Snyder
 * @version 2013.10.09
 */


    /**
     * Create a room described "description". Initially, it has
     * no exits. "description" is something like "a kitchen" or
     * "an open court yard".
     * @param description The room's description.
     */

    Room::Room(string descript) 
    {
        description = descript;
        exits = map<string, Room*>();
       // items = map<string, Item*>();
    }

    Room::Room()
    {
        description = "";
        exits = map<string,Room*>();
       // items = map<string, Item*>();
    }

    /**
     * Define an exit from this room.
     * @param direction The direction of the exit.
     * @param neighbor  The room to which the exit leads.
     */
    void Room::setExit(string direction, Room* neighbor) 
    {
        exits[direction] = neighbor;
    }

    void Room::setItems(string decription, Item* type)
    {
       // items[description] = type;
    }

    /**
     * @return The short description of the room
     * (the one that was defined in the constructor).
     */
    string Room::getShortDescription()
    {
        return description;
    }

    /**
     * Return a description of the room in the form:
     *     You are in the kitchen.
     *     Exits: north west
     * @return A long description of this room
     */
    string Room::getLongDescription()
    {
        return "You are " + description + ".\n" + getExitString();
    }


    /**
     * Return a string describing the room's exits, for example
     * "Exits: north west".
     * @return Details of the room's exits.
     */
    string Room::getExitString()
    {
        string returnString = "Exits:";
        for(map<string,Room*>::iterator entry = exits.begin();
            entry != exits.end(); entry++){
            returnString += " " + entry -> first;   
        }
            
        return returnString;
    }

    /**
     * Return the room that is reached if we go from this room in direction
     * "direction". If there is no room in that direction, return null.
     * @param direction The exit's direction.
     * @return The room in the given direction.
     */
    Room* Room::getExit(string direction) 
    {
        if(exits.find(direction)!=exits.end()){
            return exits[direction];
        }
        return NULL;
    }

   /** Item* getItem(string item)
    {
        if(items.find(direction)!=items.end()){
            return items[direction];
        }
        return NULL;
    
    void removeItem(string item)
    {
        items.erase(item);
    }

    bool checkRoomForItem(string item)
    {
        if(items.find(direction)!=items.end()){
            return true;
        }
        return false;
    }

    string getItemList()
    {
        string returnString = "You see: ";
        for(map<string,Item*>::iterator entry = items.begin();
            entry != items.end(); entry++){
            returnString += " " + (entry -> first)->getName();   
        }
            
        return returnString;
    }
**/
    
/**
int main(int argc, char * argv[])
{
    Room* a = new Room("Room a");
    Room* b = new Room("Room b");
    Room* c = new Room("Room c");
    a->setExit("north", b);
    b->setExit("south", a);
    b->setExit("east", c);
    c->setExit("west", b);
    cout <<b->getLongDescription() << endl;
}
**/

