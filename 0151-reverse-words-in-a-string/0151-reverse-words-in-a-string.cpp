class Solution {
public:
    string trimString(string& s){
        string trimmedString = "";
        int i=0;
        // trim prefix spaces
        for( ; i<s.length(); i++){
            if(s[i]!=' ')   break;
        }
        if(i==s.length())   return trimmedString;   // if all are spaces only
        for( ; i<s.length(); i++){
            trimmedString += s[i];
        }
        
        // trim suffix spaces
        for(int j=trimmedString.length()-1; j>=0; j--){
            if(trimmedString[j]==' ')   trimmedString.pop_back();
            else    break;
        }
        return trimmedString;
    }

    string reverseWords(string s) {
        string curString = trimString(s);
        cout<<curString<<endl;
        string revString = "";
        for(int i=0; i<curString.length(); i++){
            string w = "";
            while(i<curString.length() && curString[i]!=' '){
                w += curString[i];
                i++;
            }
            while(curString[i]==' ' && i+1<curString.length() && curString[i+1]==' '){
                i++;
            }
            if(revString.length()==0)   revString = w;
            else    revString = w + ' ' + revString;
        }

        return revString;
    }
};