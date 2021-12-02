class Solution {

    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",                                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",                                     "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    public:
    string numberToWords(int num) {
        return num?toWords(num).substr(1):"Zero";
    }
    
    string toWords(int n)
    {
        if(n>=1e9)
            return toWords(n/1e9) + " Billion" + toWords(n%(int)1e9);
        if(n>=1e6)
            return toWords(n/1e6) + " Million" + toWords(n%(int)1e6);
        if(n>=1e3)
            return toWords(n/1e3) + " Thousand" + toWords(n%(int)1e3);
        if(n>=1e2)
            return toWords(n/1e2) + " Hundred" + toWords(n%(int)1e2);
        if(n>=20)
            return " " + tens[n/10] + toWords(n%10);
        if(n>=1)
            return " " + ones[n];
        return "";
    }
};