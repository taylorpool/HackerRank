#pragma once
#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>

struct MatchIndices
{
    int firstLower;
    int firstUpper;
    int secondLower;
    int secondUpper;
};

bool operator==(const MatchIndices& indices1, const MatchIndices& indices2);

std::ostream& operator<<(std::ostream& os, const MatchIndices& indices);

template<>
struct std::hash<MatchIndices>
{
    size_t operator()(const MatchIndices& indices) const
    {
        return indices.firstLower + 10*indices.firstUpper + 100*indices.secondLower + 1000*indices.secondUpper;
    }
};

int sherlockAndAnagrams(std::string);