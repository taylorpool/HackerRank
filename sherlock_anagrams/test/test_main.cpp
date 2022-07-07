#include "sherlock_anagrams/sherlock.hpp"

#include <gtest/gtest.h>

TEST(Anagram, a0)
{
    ASSERT_EQ(sherlockAndAnagrams("a"), 0);
}

TEST(Anagram, b0)
{
    ASSERT_EQ(sherlockAndAnagrams("b"), 0);
}

TEST(Anagram, aa1)
{
    ASSERT_EQ(sherlockAndAnagrams("aa"), 1);
}

TEST(Anagram, ab0)
{
    ASSERT_EQ(sherlockAndAnagrams("ab"), 0);
}

TEST(Anagram, ba0)
{
    ASSERT_EQ(sherlockAndAnagrams("ba"), 0);
}

TEST(Anagram, bb1)
{
    ASSERT_EQ(sherlockAndAnagrams("bb"), 1);
}

TEST(Anagram, abc0)
{
    ASSERT_EQ(sherlockAndAnagrams("abc"), 0);
}

TEST(Anagram, aac1)
{
    ASSERT_EQ(sherlockAndAnagrams("aac"), 1);
}

TEST(Anagram, aaa4)
{
    ASSERT_EQ(sherlockAndAnagrams("aaa"), 4);
}

TEST(Anagram, aba2)
{
    ASSERT_EQ(sherlockAndAnagrams("aba"), 2);
}

TEST(Anagram, abba4)
{
    ASSERT_EQ(sherlockAndAnagrams("abba"), 4);
}

TEST(Anagram, abcd0)
{
    ASSERT_EQ(sherlockAndAnagrams("abcd"), 0);
}

TEST(Anagram, ifailuhkqq3)
{
    ASSERT_EQ(sherlockAndAnagrams("ifailuhkqq"), 3);
}

TEST(Anagram, kkkk10)
{
    ASSERT_EQ(sherlockAndAnagrams("kkkk"), 10);
}

TEST(Anagram, cdcd5)
{
    ASSERT_EQ(sherlockAndAnagrams("cdcd"), 5);
}