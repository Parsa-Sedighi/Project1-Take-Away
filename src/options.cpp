//
// Parsa Sedighi/5550071047
//

#include "options.h"

#include <stdint.h>
#include <string>
#include <iostream>
#include <string.h>


using namespace std;
//Step 3
std::string usage (const char* character )
{
    return "Usage: ./take-away [-h] [-c] [-p # piles] [-s # stones]\n";
}

//Step 4
std::string help (const char* character)
{
    return usage(character) + "\nOptions: \nType `-h` to display `h`elp text and exit. \nType `-c` to play against the `c`omputer \nType `-p` to set an exact number of `p`iles \nType `-s` to set an exact number of `s`tones in each pile \n  Max values for Piles and Stones: 20\n  Min values for Piles and Stones: 1\n" ;
}

//step 5
mesa::option get_options(int number,char** character)
{
   
    mesa::option opt;
    if(number == 1)
    {
        opt.valid = true;
    }
    if(number > 1)
    {
        if (strcmp(*(character+1) ,"-h") == 0)
        {
            opt.valid = false;
        }
        if(strcmp(*(character+1) , "-c") == 0)
        {
          opt.has_ai = true;
            if(     number > 5)
            {
              if(( strcmp(*(character+2), "-p") == 0) && (strcmp(*(character+4), "-s") == 0))
                 {
                     if(((stoi(character[3]) > 0) && stoi(character[3]) < 21) && ((stoi(character[5]) > 0) &&(stoi(character[5]) <21)))
                     {
                         opt.piles = stoi(character[3]);
                         opt.stones = stoi(character[5]);
                         opt.valid = true;
                     }
                     else
                     {
                         
                         opt.valid = false;
                     }
               }
            }
            else if(number > 3)
            {
              if(strcmp(*(character+2), "-p") == 0)
              {
                if((stoi(character[3]) > 0) && (stoi(character[3]) < 21))
                {
                  opt.piles = stoi(character[3]);
                  opt.valid = true;
                }
                else
                {
                  opt.valid = false;
                }
              }
              else
              {
                opt.valid = false;
            }
                
           }
        }
        
        
        if(strcmp(*(character+1) , "-p" ) == 0)
        {
            if(number > 4  && strcmp(*(character+3), "-s") == 0)
            {
              if(((stoi(character[4]) > 0) && stoi(character[4]) < 21) &&( (stoi(character[2]) > 0) &&( stoi(character[2]) < 21)))
               {
                 opt.piles = stoi(character[2]);
                  opt.stones =stoi(character[4]);
                  opt.valid = true;
               }
               else
               {
                opt.valid = false;
               }
            }
            else if(number > 2)
            {
                if((stoi(character[2]) > 0) && stoi(character[2]) < 21)
                {
                    opt.piles = stoi(character[2]);
                    opt.valid = true;
                    
                }
                
                else
                {
                    opt.valid = false;
                }
            }
            else
            {
                opt.valid = false;
            }
           
        }
        
        
        if(strcmp(*(character+1) , "-s") == 0)
        {
            if(number > 2)
            {
                if((stoi(character[2]) > 0) && stoi(character[2]) < 21 )
                {
                    opt.stones = stoi(character[2]);
                    opt.valid = true;
                }
                else
                {
                    opt.valid =false;
                }
            }
            else
            {
                opt.valid = false;
            }
        }
    }

    return opt;
}
