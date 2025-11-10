//
// Parsa Sedighi/5550071047
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <string.h>


namespace mesa{
//Step 2
struct option{
    bool valid = true;
    bool has_ai = false;
    uint32_t piles = 0;
    uint32_t stones = 0;
    
    
};


}
//Step 3
std::string usage (const char*);
//Step 4
std::string help (const char*);
//Step 5
mesa::option get_options(int,char**);






