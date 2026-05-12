class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false; 

        sort(hand.begin(), hand.end());
        unordered_map<int, int> um; 

        for (int i = 0; i < hand.size(); i++) {
            um[hand[i]]++;
        }

        for (int i = 0; i < hand.size(); i++) {
            if (um[hand[i]] == 0) continue; 
            else {
                for (int j = hand[i]; j <= hand[i] + groupSize - 1; j++) {
                    if (um[j] == 0) return false; //unable to make group
                    else {
                        um[j]--;
                    }
                }
            }
        }

        return true; 
    }
};
