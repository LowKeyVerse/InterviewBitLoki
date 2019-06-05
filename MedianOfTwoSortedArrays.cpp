//This solution handles the test case when the version numbers are very large(within a .) which long long also cant handle
//eg 999999999999999999999999999999999999999999999999999.8888888888888888888888888. 
// now 99999999....  is very large for long

int Solution::compareVersion(string A, string B) {
    int i=0, j=0, an=A.length(), bn=B.length();
    
    string c1="",c2=""; //In leetcode we used a long long variable to do the same
    
    while(i<an || j<bn){
        while(i<an && A[i]=='0')    //remove  0's from A
            i++;
            
        while(i<an && A[i]!='.')
            c1=c1+A[i++];
        
        while(j<bn && B[j]=='0')    //remove 0's from B
            j++;
            
        while(j<bn && B[j]!='.')    // till j reaches the end or a . is seen concatenate to B 
            c2=c2+B[j++];
            
        if(c1!=c2){
                if(c1.length()==c2.length())
                  return c1.compare(c2)>0?1:-1;
                else
                  return c1.length()>c2.length()?1:-1;
        }   
        else{
            i++;
            j++;
            c1="";c2="";
        }
    }
    return 0;
}
