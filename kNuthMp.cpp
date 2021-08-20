#include<iostream>
#include<stdio.h>
#include <bits/stdc++.h>


using namespace std;

void LPScalculate(int *lps,int patternLength, char *pattern)
{
    int len=0;

    
    for(int i=1;i<patternLength;i++)
    {
        if(pattern [i] == pattern [len] )
        {
            len++;
            lps[i]=len;
        }
        else   
            if(len == 0)
            { 
                lps[i]=len;
            }

            else if (len != 0 )
            {
                len =lps[len-1]; 
                i--;
            }
    }
}

void kmpCalculate(char *text, char *pattern)
{
   int stringLength=strlen(text);
   int patternLength=strlen(pattern);

    int lps[patternLength]; 

    lps[0]=0;

    LPScalculate(lps,patternLength,pattern);

    int i=0,j=0;

    while(i<stringLength)
    {
        if (text[i]==pattern[j])
        {
            i++;
            j++;
        }
        if (j == patternLength)
        {
            cout<<"Found Pattern at index "<<i-j <<endl;
            j = lps[j-1];
        }
        else if ( text[i] != pattern[j] && i< stringLength)
        {
            if (j != 0 )
                j= lps[j-1];
            else 
                i++;
        }
    }

}

int main()
{
    char text[]="abbacabbabba";
    char pattern[]="abba";

    kmpCalculate(text,pattern);
    return 0;
}