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
    std::queue<MatchIndices> matches;
    std::unordered_set<MatchIndices> all_indices;

    int length = str.length();
    for(int first_index = 0; first_index < length-1; ++first_index)
    {
        for(int last_index = first_index+1; last_index < length; ++last_index)
        {
            if(str[first_index] == str[last_index])
            {
                MatchIndices indices {first_index, first_index, last_index, last_index};
                std::cout << indices << std::endl;
                matches.push(indices);
                all_indices.insert(indices);
                ++num_anagrams;
            }
        }
    }
    while(!matches.empty())
    {
        MatchIndices match = matches.front();
        matches.pop();
        if(str[match.firstUpper+1] == str[match.secondUpper+1])
        {
            MatchIndices new_match {match.firstLower, match.firstUpper+1, match.secondLower, match.secondUpper+1};
            if(all_indices.insert(new_match).second)
            {
                std::cout << new_match << std::endl;
                matches.push(new_match);
                ++num_anagrams;
            }
        }
        if(match.firstLower < (match.secondLower-1) && str[match.firstUpper+1] == str[match.secondLower-1])
        {
            MatchIndices new_match {match.firstLower, match.firstUpper+1, match.secondLower-1, match.secondUpper};
            if(all_indices.insert(new_match).second)
            {
                std::cout << new_match << std::endl;
                matches.push(new_match);
                ++num_anagrams;
            }
        }
    }
    return num_anagrams;
}