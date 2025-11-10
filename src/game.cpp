//
// Parsa Sedighi/5550071047
//

#include "game.h"

#include <stdint.h>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
//Step 6
//Function body from NumberGuessingFunctionRefactor @DaveParillo in the cisc187coursereader
/// https://daveparillo.github.io/cisc187-reader/function-overloads/guidelines.html#example-number-guessing
std::string get_entry (const std::string &prompt)
{
    std::cout << prompt << std::endl;
    std::string line;
    while(getline(std::cin,line))
    {
        if(isdigit(line[0]))
        {
            std::cout << "Bad input, Enter an Alphabetic character...\n";
        }
        else if(!(line.empty()))
        {
            break;
        }
        line.clear();
    }
    return line;
}


//Step 7
//Function body from NumberGuessingFunctionRefactor @DaveParillo in the cisc187coursereader
/// https://daveparillo.github.io/cisc187-reader/function-overloads/guidelines.html#example-number-guessing
uint32_t get_value (const std::string prompt, int max, int min)
{
    std::string number = "";
    uint32_t number_integer;
    
    std::cout << prompt << std::endl;
    uint32_t input = std::numeric_limits<int>::max();
    while (input < min || input > max) {
        std::cin >> number;
        std::cin.ignore();
        
       // number.i
        
        if(isdigit(number[0]) )
        {
            //std::cout << number;
            input = stoi(number);
        }
        //std::cout << "Here is " << input;
        if ((input < min || input > max)) {
            std::cout << "Bad Input, please try again...\n";
        } else {
            break;
        }
    }
    return  input;
}
    
    
// Example function From the CISC187 Coursereader
/// https://daveparillo.github.io/cisc187-reader/c_review/random-numbers.html#random-numbers
uint32_t get_Random_Number ()
{
    std::random_device device;
    std::default_random_engine gen(device());
    return  std::uniform_int_distribution<uint32_t> {1 ,20} (gen);
}
    
void initialize_game_Piles(std::vector<uint32_t>& vector, uint32_t piles, uint32_t stones)
{
    uint32_t temp_Size = 0;
    if(piles == 0 && stones == 0)
    {
        temp_Size = get_Random_Number();
        for(int i = 0; i<temp_Size; ++i)
        {
            vector.push_back(get_Random_Number());
        }
    }
    else if(piles > 0 && stones == 0)
    {
        temp_Size = piles;
        for(int i = 0; i<temp_Size; ++i)
        {
            vector.push_back(get_Random_Number());
        }
    }
    else if (piles == 0 && stones > 0)
    {
        temp_Size = get_Random_Number();
        vector.resize(temp_Size,stones);
    }
    else if(piles > 0 && stones > 0)
    {
        vector.resize(piles,stones);
    }
        
}
    
void take_From_Vector(std::vector<uint32_t>& vector, uint32_t piles, uint32_t stones)
{
    if(vector[piles])
        vector[piles] = vector[piles]-stones;
}
    
    
void display_Vector(std::vector<uint32_t> vector)
{
    std::string output = "";
    for(int i = 0; i< vector.size(); ++i)
    {
        std::cout <<  "Pile " << std::to_string(i) << " [" << std::to_string(vector[i]) << "] : ";
        
        for(int j = 0; j < vector[i]; ++j)
        {
            std::cout <<  "*" ;
        }
            
        std::cout << "\n";
    }
        
}

bool game_Over(std::vector<uint32_t> vector)
{
    for(int i = 0; i<vector.size() ; ++i)
    {
        if(vector[i] > 0)
        {
            return false;
        }
    }
        return true;
        
}
    
    
void update_Vector(std::vector<uint32_t>& vector)
{
    auto it = std::find(vector.begin(), vector.end(),0);
    if(it!=vector.end())
    {
        vector.erase(it);
    }
}
