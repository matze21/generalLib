#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
    private:
    unordered_map<int,int> m_valToIdx;
    vector<int> m_val;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // checking with [] will insert a default val in the map
        if(m_valToIdx.contains(val)){
            return false;
        }
        
        m_valToIdx[val] = m_val.size();
        m_val.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!m_valToIdx.contains(val)){
            return false;
        }
        // remove last index
        int lastVal = m_val[m_val.size()-1];
        int valIdx = m_valToIdx[val];

        m_valToIdx[lastVal] = valIdx;
        m_val[valIdx] = lastVal;


        m_val.pop_back();
        m_valToIdx.erase(val);
        return true;
    }
    
    int getRandom() {
        return m_val[rand() % m_val.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */