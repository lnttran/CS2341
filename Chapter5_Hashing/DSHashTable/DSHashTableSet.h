#ifndef DSHASHTABLESET_H
#define DSHASHTABLESET_H

#include <string>
#include <vector>
#include <forward_list>
#include <stdexcept>


/**
 * @brief Simple hash table class for a hashed set of strings.
 */
class DSHashTableSet
{
private:
    // a hash table with a singly-linked list for separate chaining
    std::vector<std::forward_list<std::string>> table;

public:
    /**
     * @brief  default constructor
     * @param size 
     */
    explicit DSHashTableSet(size_t size = 101)
    {
        // call resize for vector to get the empty lists
        table.resize(size);
    }

    /**
     * Rule of 3: Not needed! We avoid the use dynamic memory allocation, so the compiler defaults work.
     */


    /**
     * @brief insert a key into the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool insert(const std::string &x)
    {
        // find bucket using hash function in O(1)
        auto &whichEntry = table[calcHash(x)];
        
        // check the list to see if the item is already there. Lists are hopefully short -> O(1)
        if (std::find(whichEntry.begin(), whichEntry.end(), x) != whichEntry.end())
            return false;

        // add the item to the front of the list in O(1)
        whichEntry.push_front(x);
        
        return true;
    }

    /**
     * @brief remove a key from the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool remove(const std::string &x)
    {
        // find bucket using hash function in O(1)
        auto &whichEntry = table[calcHash(x)];
        
        // check the list to see if the item is in the list. Lists are hopefully short -> O(1)
        if (std::find(whichEntry.begin(), whichEntry.end(), x) == whichEntry.end())
            return false;
        
        whichEntry.remove(x);
        return true;
    }

    /**
     * @brief find a key in the hash table
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool contains(const std::string &x) const
    {
        // find bucket
        auto &whichEntry = table[calcHash(x)];
        
        // search list
        return std::find(whichEntry.begin(), whichEntry.end(), x) != whichEntry.end();
    }

    /**
     * @brief make the hash table empty (needs to be implemented)
     */
    void make_empty()
    {
        for (auto& entry : table)
            entry.clear();
    }

    /**
     * @brief number of elements stored in the hash table (needs to be implemented)
     * 
     * @return size_t 
     */
    size_t size() const
    {
        size_t n = 0;

        // Notes: forward_list currently has no size() function and k is unused -> compiler warning
        for (const auto& entry : table)
            for (const auto& k : entry)
                ++n;

        return n;
    }

    /**
     * @brief return the current loading factor of the hash table
     * 
     * @return double
     */
    double loading_factor() const
    {
        return double(size()) / table.size();
    }


    /**
     * @brief Rehash the hash table
     * 
     * Usually automatically increases the hash table size by a factor of 2 once 
     * the load_factor gets >1 during insert().
     * 
     * Here. I manually call rehash and specify the new hash table size.
     * 
     * Note on move semantics: I want to avoid compying the stored string several times.
     * std::move() marks an object as a rhs references 
     * (an object that can be moved during the next assignment if it has a move assignment 
     * operator). It is the programmers job to make sure that the original object is 
     * not used after the move.
     */
    void rehash(size_t theSize)
    {
        // 1. take all keys out of the table
        std::vector<std::string> keys;
        keys.reserve(size()); // avoid dynamic resizing of the vector

        for (const auto& entry : table)
            for (const auto& k : entry)
                keys.push_back(std::move(k));

        // 2. clear and resize the hash table
        make_empty();
        table.resize(theSize);

        // 3. insert the keys into the new table (the different table size will create different hash values!) 
        for (const auto& k : keys)
            insert(std::move(k));
    }

    // more useful functions would be nice: get keys, iterators, etc.

private:
    /**
     * @brief calculate the hash value for a string using the standard polynomial hash function.
     *
     * Note that 37^i is broken down to repeated multiplications with 37 which is 
     * a lot faster then calling `pow()` from cmath (math.h)
     * 
     * @param x 
     * @return size_t 
     */
    size_t calcHash(const std::string &x) const
    {
        size_t hashVal = 0;
        
        for (const auto &c : x)
            hashVal = 37 * hashVal + c;
            
        return hashVal % table.size();
    }
};

#endif