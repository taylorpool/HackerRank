#include "sherlock_anagrams/sherlock.hpp"

int sherlockAndAnagrams(std::string str)
{
    int num_anagrams = 0;
    std::queue<std::vector<int>> matches;
    std::map<int,std::map<int,std::map<int,std::map<int,int>>>> all_matches;
    int length = str.length();
    for(int first_index = 0; first_index < length-1; ++first_index)
    {
        for(int last_index = first_index+1; last_index < length; ++last_index)
        {
            if(str[first_index] == str[last_index])
            {
                ++num_anagrams;
            }
        }
    }
    return num_anagrams;
}