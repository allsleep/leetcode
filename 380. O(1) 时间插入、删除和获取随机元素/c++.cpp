#include <vector>
#include <random>
#include <time.h>
using namespace std;
class RandomizedSet {
public:
    vector<int> pool;
    int _srand = 1; 
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
            for (auto v : pool)
                if (v == val)
                    return false;
            pool.push_back(val);
            return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        for (vector<int>::iterator i = pool.begin(); i != pool.end(); i++){
            if (*i == val){
                pool.erase(i);
                return true;
            }
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        this->_srand ++;
        srand((unsigned)time(NULL) + this->_srand);
        return pool[rand()%pool.size()];
    }
};