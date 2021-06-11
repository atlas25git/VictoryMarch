class Solution {
public:
    int calculate(string s) {
        int cn=0;
        char op ='+';
        stack<int> res;
        
        for(int i=0;s[i];i++)
        {
            char cc = s[i];
            
            if(isdigit(s[i])){
                cn = cn*10 + (cc-'0');
            }
            //first no simply add as op=+, now current s[i]:op is preserved and
            //woould be used for the next no.
            if(!isdigit(cc) && !iswspace(cc) || i==s.size()-1)
               {
                   if(op=='+')res.push(cn);
                   else if(op=='-')res.push(-cn);
                   else if(op=='*')
                   {
                       int st = res.top();
                       res.pop();
                       res.push(st*cn);
                   }
                   else if(op=='/')
                   {
                       int st=res.top();
                       res.pop();
                       res.push(st/cn);
                   }
                 //op preserved for next no
                  op=cc;
                   cn=0;
               }
        }
               int res1=0;
               while(res.size()!=0){
                   res1+=res.top();
                   res.pop();
               }
               
               return res1;
    }
};