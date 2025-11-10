//
// Parsa Sedighi/5550071047
//

#include "computer_player.h"

#include <vector>
#include <stdint.h>
#include <random>

// Example function From the CISC187 Coursereader
// https://daveparillo.github.io/cisc187-reader/c_review/random-numbers.html#random-numbers
uint32_t get_Random(uint32_t max_value)
{

  std::random_device device;
  std::default_random_engine gen(device());
     return  std::uniform_int_distribution<uint32_t> {1 ,max_value} (gen);
}


uint32_t choose_heap(std::vector<uint32_t>& vector,
int largest_Pile)
{
    
    int j = 0;
    uint32_t max = 0;
    
    for( int i = 1; i<vector.size(); i++)
    {
        if(i == 1)
        {
            max = vector[0];
        }
        if(max < vector[i])
        {
            max = vector[i];
            largest_Pile = i;
        }
        if(vector.size() == 2 && (vector[i] == 1 && max == 1))
        {
            return 0;
        }
    }

    return largest_Pile;
}

void take(std::vector<uint32_t>& vector, uint32_t pile , uint32_t stones)
{
    
   vector[pile] = vector[pile] - stones;
}

