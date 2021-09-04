class Solution 
{
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    isRotated(str1, str2)
    {
        if(str1.length != str2.length)
        return false;
        
        if(str1.length<=2)return str1 == str2;
        
        let cr = "";
        let acr = "";
        let len = str2.length;
        acr = acr + str2.substr(len-2,2)+str2.substr(0,len-2);
        cr = cr + str2.substr(2) + str2.substr(0,2);
        return (str1==cr || str1==acr);
    }
}