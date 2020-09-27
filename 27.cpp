class Solution {
    void search( unordered_map <string,vector <pair<string,double> > >&mp,
                string f1,string f2,double &m, double cur, unordered_map<string,bool> mt){
        
        if(mt[f1]==0){
            mt[f1]=1;
       
            if(f1==f2){
                m=cur;
                return;
            }
           for(auto i : mp[f1]){
               if(mt[i.first]==0){
               search(mp,i.first,f2,m,(cur*i.second),mt);
               }
           }

          mt[f1]=0;
        
    }
    
}
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        
     vector <double> w;
     unordered_map <string,vector <pair<string,double> > > mp;
     unordered_map<string,bool> mt;
        
       for(int i=0;i<eq.size();i++){
            string f1=eq[i][0];
            string f2=eq[i][1];
            double op = 1/v[i];
            mp[f1].push_back({f2,v[i]});
            mp[f2].push_back({f1,op});
            mt[f1]=0;
            mt[f2]=0;
           
         }
        
        
        for(int i=0;i<q.size();i++){
            string f1=q[i][0];
            string f2=q[i][1];
            double m=-1;
            
            if(f1!=f2)
                search(mp,f1,f2,m,1,mt);
            else if(f1==f2 && mp.find(f1)!=mp.end() && mp.find(f2)!=mp.end())
                m=1;
            w.push_back(m);
        }
        
        return w;
        
        
        
        
    }
};
