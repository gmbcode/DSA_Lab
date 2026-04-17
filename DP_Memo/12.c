#include<stdlib.h>
#include<limits.h>
#include<stdio.h>
/*
Question 12: The Corrupted Transmission (Valid Substring Splitting)
Problem Description
A network packet containing a string of lowercase English letters was intercepted. You must
extract the longest valid data block from this packet. A "valid data block" is defined as a strictly
contiguous substring where every unique character present in that substring appears at least K
times within that exact substring. If no such substring exists, the valid length is 0.
Input Format
Line 1: Two space-separated integers N and K, where N is the length of the string and K is the
required frequency threshold
Line 2: A string S of length N, consisting only of lowercase English letters (a–z)
Output Format
Print a single integer representing the length of the longest valid substring.
*/
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int compute(char* s,int l,int r,int k){
    if((r - l + 1) < k){
        return 0;
    }
    int count[26] = {0};
    int t_index = -1;
    FL(i,l,r+1){
        count[s[i] - 'a']++;
    }
    FL(i,l,r+1){
        if(count[s[i] - 'a'] < k){
            t_index = i;
            break;
        }
    }
    if(t_index == -1){
        return r - l + 1;
    }
    else{
        int lt = compute(s,l,t_index-1,k);
        int rt = compute(s,t_index+1,r,k);
        return MAX(lt,rt);
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char s[n+1];
    scanf("%s",s);

    printf("%d\n",compute(s,0,n-1,k));
}