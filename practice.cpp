#include <iostream>
#include <vector>
using namespace std;
vector<int> longest(const string &pattern){
    int m = pattern.size();
    int i = 1;
    int len = 0;
    vector<int> lsp(m,0);
    while(i < m){
        if(pattern[i] == pattern[len]){
            len++;
            lsp[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lsp[len-1];
            }
            else{
                lsp[i] = 0;
                i++;
            }
        }
    }
    return lsp;
}
void KMP(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    vector<int> lsp = longest(pattern);
    int i = 0;
    int j = 0;
    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern found at index "<< i-j <<endl;
            j = lsp[j-1];
        }
        else if (i < n && text[i] != pattern[j]){
            if(j!=0){
                j = lsp[j-1];
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
    
    KMP(text, pattern);
    
    return 0;
}