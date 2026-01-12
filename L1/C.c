#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

int wc(char s[]);
int vc(char s[]);
void rev(char s[]);

int main(){
    char sentence[1000];
    fgets(sentence,1000,stdin);
    printf("Words : %d\n",wc(sentence));
    printf("Vowels : %d\n",vc(sentence));
    rev(sentence);
    
}

int wc(char s[]){
    int count = 0;
    int index = 0;
    while (s[index] != '\0')
    {
        if(s[index] == ' '){
            count++;
        }
        index++;
    }
    return count + 1;
       
}

int vc(char s[]){
    int count = 0;
    int index = 0;
    while (s[index] != '\0')
    {
        if(s[index] == 'a' || s[index] == 'e' || s[index] == 'i' || s[index] == 'o' || s[index] == 'u'){
            count++;
        }
        else if(s[index] == 'A' || s[index] == 'E' || s[index] == 'I' || s[index] == 'O' || s[index] == 'U'){
            count++;
        }
        index++;
    }
    return count;
       
}

void rev(char s[]){
    int count = 0;
    int index = 0;
    while (s[index] != '\0')
    {
        index++;
    }
    printf("Reversed :");  
    while (index >= 0)
    {
        printf("%c",s[index]);
        index--;
    }
    printf("\n");      
}