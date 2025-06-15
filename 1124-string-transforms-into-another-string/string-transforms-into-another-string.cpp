class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        
        unordered_map<char, char> characterMapping; // to check if we got a mapping of 1 to many then we cant convert.
        
        unordered_set<char> uniqueCharInStr2; // to check how many unique char are there in 
        // str2 if less than 26 then we can convert using a temporary character.
        
        
        for(int i = 0; i < str1.size(); i++) {
            if(characterMapping.find(str1[i]) == characterMapping.end()) {
                characterMapping[str1[i]] = str2[i];
                uniqueCharInStr2.insert(str2[i]);
            } else if(characterMapping[str1[i]] != str2[i]){
                // we found 1 to many relationship
                return false;
            }
        }
        
        if(uniqueCharInStr2.size() < 26) {
            return true; // as we can use a temporary char
        }
        
        return false;
    }
};