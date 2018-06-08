class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size()==0)
            return false;
        if(wordDict.size()==0)
            return false;
        
        set<string> dict;
        
        for(int i=0;i<wordDict.size();i++)
            dict.insert(wordDict[i]);
        
        int n=dict.size();
        
        vector<bool> p(s.size()+1,false);
        p[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(p[j])
                {
                    string str=s.substr(j,i-j);
                    if(dict.find(str)!=dict.end())
                    {
                        p[i]=true;
                        break;
                    }
                }
            }
        }
        
        return p[s.size()];
    }
};
