#include <iostream>
#include <string>
#include <vector>
#include "CommandWords.h"
using namespace std;

/**
 * This program was adapted from the zuul-better game in java. 
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.
 * 
 * This class holds an enumeration of all command words known to the game.
 * It is used to recognise commands as they are typed in.
 *
 * @author  Caitlin Snyder
 * @version 2013.09.30
 */
    CommandWords::CommandWords()
    {
        validCommands.push_back("go");
        validCommands.push_back("quit");
        validCommands.push_back("help");
    }

    /**
     * Check whether a given string is a valid command word. 
     * @return true if it is, false if it isn't.
     */
    bool CommandWords::isCommand(string aString)
    {
        for(int i = 0; i < validCommands.size(); i++) {
        
            if((validCommands.at(i).compare(aString) == 0) ){
              return true;
            }
        }
        // if we get here, the string was not found in the commands
        return false;
    }

    /**
     * Print all valid commands 
     */
    void CommandWords::showAll() 
    {
        for(vector<string>::iterator command = validCommands.begin();
            command != validCommands.end(); command++)
            cout << *command + " " << endl; 
    }


/** 
int main(int argc, char * argv[])
{
    CommandWords cm;
    cm.showAll();
    bool cmd1 = cm.isCommand("help");
    bool cmd2 = cm.isCommand("bob");
    cout << cmd1 << cmd2 << endl;
}
**/
