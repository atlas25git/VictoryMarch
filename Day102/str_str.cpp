int strstr(string txt, string pat)
{
        int m = pat.length();
    	int n = txt.length();
    	
    	for(int i=0;i<=n-m;i++)
    	{
    	    int j;
    	    for(j=0;j<m;j++)
    	        if(txt[i+j]!=pat[j])
    	            break;
                if(j==m)
                    return i;
    	}
    	return -1;
}