//
// Parsa Sedighi/5550071047
//

#include "computer_player.h"
#include "game.h"
#include "options.h"

#include <vector>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <random>
#include <string>

int main(int argc,char *argv[])
{

    mesa::option game_Options;
    std::vector<uint32_t> game_Vector;
    game_Options = get_options(argc, const_cast<char**>(argv));
    
    std::string player_One = "";
    std::string player_Two = "";
    uint32_t temp_Pile = 0 ;
    uint32_t temp_Stone = 0;
    std::string user_Prompt = "y";
    std::string temp_Prompt;
 
    std::cout << "Welcome to Take-Away!" << std::endl;
    
    //Display the help message
    std::cout << help(*argv);
    //If the options set are valid
    if((game_Options.valid))
    {
       //Set the names...
        player_One =  get_entry("Enter Your Name, Player 1: ");
        if(game_Options.has_ai)
        {
            player_Two = "Computer";
        }
        else
        {
            player_Two = get_entry("Enter your Name, Player 2: ");
        }
            std::cout << std::endl;
        
   
        //While the game is to be played...
        while(user_Prompt == "y")
        {
            //Initialize the vector with the given piles and stone values
            initialize_game_Piles(game_Vector, game_Options.piles, game_Options.stones);
            //            //Initialize the vector with the given piles and stone values
            //            initialize_game_Piles(game_Vector, game_Options.piles, game_Options.stones);
                        std::cout << player_One << " VS " << player_Two << std::endl;
                        std::cout << "Be the person who takes the last stone and you win!!!" << std::endl;
            while(!(game_Over(game_Vector)))
            {
              
                //Display it in a readable format
                display_Vector(game_Vector);
                std::cout << player_One << "'s turn: " << std::endl;
                            
                //Repeat if the entered values are false..
                //  do{
                                
                temp_Pile = get_value("Which pile to take from(Pick between the given range of Piles): ",static_cast<int>(game_Vector.size()-1),0);

                                //}while(temp_Pile > game_Vector.size()-1);
                         //   do{
                temp_Stone = get_value("How many Stones to take(Pick from the number of available stones inside []): ", game_Vector[temp_Pile], 1);
                            //    }while(temp_Stone > game_Vector[temp_Pile] || temp_Stone == 0);
                            //Take/remove from the vector
                take_From_Vector(game_Vector, temp_Pile, temp_Stone);
                            
                update_Vector(game_Vector);
                            //Check for game ending
                if(game_Over(game_Vector))
                {
                    std::cout << "Game Over, Winner is " << player_One << std::endl;
                }
                else
                {
                    display_Vector(game_Vector);
                }
                            
                //The computers turn
                if(game_Options.has_ai && !(game_Over(game_Vector)))
                {
                    std::cout << player_Two << "'s turn: " << std::endl;
                    //Chose the pile to take from
                    //Assign that value
                    temp_Pile = choose_heap(game_Vector, 0);
                    //Generate a random number of stones to take
                    temp_Stone = get_Random(game_Vector[temp_Pile]);
                    //Take from the vector
                    take(game_Vector,temp_Pile,temp_Stone);
                    update_Vector(game_Vector);
                    //Describe computer's action
                    std::cout << player_Two << " Removed " << temp_Stone << " stones from " << " pile " << temp_Pile << std::endl;
                    //If the game is over, dsplay the winner
                    if(game_Over(game_Vector))
                    {
                        std::cout << "Game Over, Winner is " << player_Two << std::endl;
                    }
                    else
                    {
                        display_Vector(game_Vector);
                    }

                }
                //The second player's turn
                else if(!(game_Over(game_Vector)))
                {
                    std::cout << player_Two << "'s turn: " << std::endl;
                            // do{
                    temp_Pile = get_value("Which pile to take from(Pick between the given range of Piles): ", static_cast<int>(game_Vector.size()-1),0);
                                    
                             //   }while(temp_Pile > game_Vector.size()-1 );
                                    
                             //   do{
                    temp_Stone = get_value("How many Stones to take(Pick from the number of available stones): ",game_Vector[temp_Pile]);
                              //  }while(temp_Stone > game_Vector[temp_Pile] || temp_Stone == 0 );
                                            
                    take_From_Vector(game_Vector, temp_Pile, temp_Stone);
                    update_Vector(game_Vector);
                    if(game_Over(game_Vector))
                    {
                        std::cout << "Game Over, Winner is " << player_Two << std::endl;
                    }
                    else
                    {
                        display_Vector(game_Vector);
                    }
                }
                    std:: cout << "---------------------------------------------------" << std::endl;
            }
            
            //Ask user to whether to play again
            if((game_Over(game_Vector)) == true)
            {
                do
                {
                     user_Prompt = get_entry("Would you like to play again? (y for yes, n for No)");
                }while(user_Prompt != "y" && user_Prompt != "n");
            }

        }
                
        std::cout << "Programmed by Parsa Sedighi/5550071047" << std::endl;
        
    }
    
}
