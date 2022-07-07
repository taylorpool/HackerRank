#include "sherlock_anagrams/sherlock.hpp"
#include <unordered_set>

bool operator==(const MatchIndices& indices1, const MatchIndices& indices2)
{
    return 
        indices1.firstLower == indices2.firstLower &&
        indices1.firstUpper == indices2.firstUpper &&
        indices1.secondLower == indices2.secondLower &&
        indices1.secondUpper == indices2.secondUpper;
}

std::ostream& operator<<(std::ostream& os, const MatchIndices& indices)
{
    os << indices.firstLower << indices.firstUpper << indices.secondLower << indices.secondUpper;
    return os;
}

int sherlockAndAnagrams(std::string str)
{
    int num_anagrams = 0;
    int length = str.length();
    for(int lowerIndex = 0; lowerIndex < length-1; ++lowerIndex)
    {
        for(int upperIndex = lowerIndex+1; upperIndex < length; ++upperIndex)
        {
            if(str[lowerIndex] == str[upperIndex])
            {
                MatchIndices match {lowerIndex, lowerIndex, upperIndex, upperIndex};
                std::cout << match << std::endl;
                ++num_anagrams;
                if(upperIndex - lowerIndex > 1)
                {
                    match.firstUpper = match.secondUpper-1;
                    match.secondLower = match.firstLower+1;
                    ++num_anagrams;
                    std::cout << match << std::endl;
                    ++match.secondLower;
                    --match.firstUpper;
                    while(match.firstUpper > match.firstLower && match.secondLower < match.secondUpper && str[match.firstUpper] == str[match.secondLower])
                    {
                        ++num_anagrams;
                        std::cout << match << std::endl;
                        ++match.secondLower;
                        --match.firstUpper;
                    }
                }
            }
        }
    }
    return num_anagrams;
}