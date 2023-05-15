#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,t,len,j,k,cnt;
    string word,temp,temp2;
    
    cin>>n;
    cin.ignore();
    
    string words[n];
    
    for(i=0;i<n;i++)
        getline(cin,words[i]);
    
    cin>>t;
    
    while(t--){
        cin>>word;
        cnt = 0;
        for(i=0;i<n;i++){
            len = words[i].length();
            j = 0;
            while(j<len){
                while(j<len && words[i][j]==32)
                    j++;
                temp = "";
                while(j<len && words[i][j]>=97 && words[i][j]<=122){
                    temp += words[i][j];
                    j++;
                }
                if(temp==word)
                    cnt++;
                else if(temp.length()==word.length()-1){
                    temp2 = "";
                    for(k=0;k<word.length()-2;k++){
                        if(word[k]!='o' || word[k+1]!='u' || word[k+2]!='r')
                            temp2 += word[k];
                        else {
                            temp2 += word[k];
                            k++;
                        }
                    }
                    if(word[word.length()-3]!='o' || word[word.length()-2]!='u' || word[word.length()-1]!='r'){
                        temp2 += word[word.length()-2];
                        temp2 += word[word.length()-1];
                    }
                    else
                        temp2 += 'r';
                    if(temp2==temp)
                        cnt++;
                }
            }
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}
