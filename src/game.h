//
// Parsa Sedighi/5550071047
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

//Function body from NumberGuessingFunctionRefactor @DaveParillo in the cisc187coursereader
/// https://daveparillo.github.io/cisc187-reader/function-overloads/guidelines.html#example-number-guessing
std::string get_entry (const std::string&);

//Function body from NumberGuessingFunctionRefactor @DaveParillo in the cisc187coursereader
/// https://daveparillo.github.io/cisc187-reader/function-overloads/guidelines.html#example-number-guessing
uint32_t get_value (const std::string prompt, int max , int min = 1);

// Example function From the CISC187 Coursereader
/// https://daveparillo.github.io/cisc187-reader/c_review/random-numbers.html#random-numbers
uint32_t get_Random_Number();

void initialize_game_Piles(std::vector<uint32_t>&, uint32_t, uint32_t);

void take_From_Vector(std::vector<uint32_t>&, uint32_t, uint32_t);

void display_Vector(std::vector<uint32_t>);

bool game_Over(std::vector<uint32_t>);

void update_Vector(std::vector<uint32_t>&);
