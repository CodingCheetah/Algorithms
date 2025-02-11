/*
    Following program is implementation of 
    Rabin Karp algorithm for string matching
*/
#include <iostream>
using namespace std;
/*
    n == txt length
    m == pat length
    q == a prime number
    d == the number of characters in the input alphabet
*/
#define d 256
void rabinKarp(string txt, string pat, int q){
    int n = txt.size();
    int m = pat.size();
    int i,j;
    int p = 0; //hash value for pattern
    int t = 0; // hash value for text
    int h = 1;
    // the value of h would be "pow(d,m-1)%q"
    for(i = 0;i<m-1;i++)
        h=(h*d)%q;
    // calculate the value of pattern
    // and the first window of text
    for(i = 0;i<m;i++){
        p=(d * p + pat[i]) % q;
        t=(d * t + txt[i]) % q;
    }
    //slide the pattern over text one by one
    for(i = 0;i<n-m;i++){
        /*
            check the hash value of pat and text
            if the hahs values match then only 
            check each character one by one
        */
        if(p==t){
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==m)
                cout<<"Pattern found at index: "<<i<<endl;
        }
        /*
            calculate the hash value of next window of text
            remove leading digit 
            add trailing digit
        */
        if(i<n-m){
            t = (d*(t-txt[i]*h) + txt[i+m])%q;
            // we may get negetive value of t 
            // hence making it positive
            if(t<0){
                t+=q;
            }
        }
    }
}
// driver code
int main(){
    string txt, pat;
    cout<<"Enter text: "<<endl;
    getline(cin,txt);
    cout<<"Enter pattern: "<<endl;
    getline(cin,pat);
    int q = 101; // prime number
    rabinKarp(txt,pat,q);
}