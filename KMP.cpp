/*
    Coded by Pratyaksh Garg
    11-Feb-2024
*/
#include <iostream>
#include <vector>
using namespace std;

// function for computing the Longest Prefix Suffix (LPS) array
vector<int> computeLps(const string &pattern){
    int m = pattern.size();
    vector<int> lps(m,0);
    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while(i<m){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Pattern Searchoing Algo 
void KMPSearch(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = computeLps(pattern);
    int i = 0; //index for text
    int j = 0; //index for pattern

    while(i<n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            cout << "Pattern found at index "<< i - j << endl;
            j = lps[j-1];
        }
        else if(i < n && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
}
int main(){
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    KMPSearch(text, pattern);
    
    return 0;
}