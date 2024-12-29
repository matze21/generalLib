#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        string R{"Radiant"};
        string D{"Dire"};

        queue<int> m_r;
        queue<int> m_d;
        int n = senate.size();

        for(int i=0; i<n; i++){
            if(senate[i]=='R'){
                m_r.push(i);
            }
            else{
                m_d.push(i);
            }
        }

        
        while(!m_r.empty() && !m_d.empty()){
            int idx_r = m_r.front();
            int idx_d = m_d.front();

            if(idx_r<idx_d){
                m_r.push(idx_r + n);
            } else {
                m_d.push(idx_d+n);
            }
            m_d.pop(); m_r.pop();
        }
        return m_d.empty() ? R : D;
    }
};