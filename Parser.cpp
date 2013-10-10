#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "Parser.h"
#include "Command.h"
#include "CommandWords.h"
#include "Room.h"
using namespace std;

/**
 * This class is an adaptation of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 * 
 * This parser reads user input and tries to interpret it as an "Adventure"
 * command. Every time it is called it reads a line and
 * tries to interpret the line as a two word command. It returns the command
 * as an object of class Command.
 *
 * The parser has a set of known command words. It checks user input against
 * the known commands, and if the input is not one of the known commands, it
 * returns a command object that is marked as an unknown command.
 * 
 * @author  Caitlin Snyder
 * @version 2013.10.08
 */ 

    /**
     * Create a parser to read from the terminal window.
     */
        Parser::Parser() 
        {
            commands = CommandWords();
        }

     /**
     * changes a string to lower case
    **/
     string Parser::toLowerCase(string data)
     {
        tolower('A');
        transform(data.begin(), data.end(), data.begin(), ::tolower);
        return data;
     }

    /**
     * @return The next command from the user.
     */
    Command Parser::getCommand() 
    {
        string inputLine;   // will hold the full input line
        string word1 = "";
        string word2 = "";

        cout << "> ";
        getline(cin, inputLine);
        inputLine = toLowerCase(inputLine);

        // Find up to two words on the line.
        // Ignore anything past the first two words.
        int location = inputLine.find_first_of(" ");
        word1 = inputLine.substr(0,location);
        inputLine = inputLine.substr(location+1);
        location = inputLine.find_first_of(" ");
        word2 = inputLine.substr(0,location);
        
        // Now check whether this word is known. If so, create a command
        // with it. If not, create a "" command (for unknown command).

        if(commands.isCommand(word1)) {
            return Command(word1, word2);
        }
        else {
            return Command("", word2); 
        }
    }

    /**
     * Print out a list of valid command words.
     */
    void Parser::showCommands()
    {
        commands.showAll();
    }

/**
int main(int argc, char * argv[])
{
    Parser p;
    p.getCommand();
    p.showCommands();
}
**/
