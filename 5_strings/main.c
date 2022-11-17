#include <stdio.h>
#include <string.h>

//swapping
void Swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//search element
int Search(char* s, char a){
    int i;
    for(i=0; s[i] != '\0'; i++)
        if(a == s[i]) 
            return i ;
    
    return -1;
}
//finding length
int Length(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;

    return i;
}

//changing case
void ToUpperCase(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (97 <= s[i] && s[i] <= 122)
            s[i] = s[i] - 32;
}

void ToLowerCase(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (65 <= s[i] && s[i] <= 90)
            s[i] = s[i] + 32;
}

void ToggleCase(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (97 <= s[i] && s[i] <= 122)
            s[i] = s[i] - 32;
        else if (65 <= s[i] && s[i] <= 90)
            s[i] = s[i] + 32;
    }
}

//counting vowels and consonents
int VowelCount(char *s)
{
    int count = 0;
    int i;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            count++;

    return count;
}

//not working
int ConsonentCount(char *s)
{
    int count = 0;
    int i;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            count++;

    return count;
}

//validating a string
int Validate(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 50))
            return 0;

    return 1;
}

//reversing a string
void Reverse(char *s)
{
    int i = 0;
    int j = Length(s) - 1;

    while (i < j)
    {
        Swap(&s[i], &s[j]);
        i++;
        j--;
    }
}

void Reverse2(char *s)
{
    int i, j;
    int len = Length(s);
    char r[100];

    for (i = len - 1, j = 0; i >= 0; i--, j++)
        r[j] = s[i];

    for (i = 0; s[i] != '\0'; i++)
        s[i] = r[i];
}

//comparing string
int Compare(char *a, char *b)
{
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0')
    {
        if (a[i] < b[i])
            return -1;
        else if (a[i] > b[i])
            return 1;

        i++;
    }

    return 0;
}

//checking Plaindrome
int Palindrome(char *s)
{
    ToUpperCase(s);
    int i = 0;
    int j = Length(s) - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return 0;

        i++;
        j--;
    }
    return 1;
}

//finding duplicates
void Duplicates(char* s)
{
    int  len = Length(s);
    int i,j, count;

    for(i=0; i < len; i++){
        count =1;
        for(j = i+1; j < len; j++)
            if(s[i] == s[j])
                s[j] = -1;
                count++;
        

        if(count > 1 && s[i] != -1)
            printf("%c : %d", s[i], count);
    }

}

// finding duplicates in tring using hashtable
//only for string with lower alphabets
void Duplicates2(char* s){
    int hash[26] = {0};
    int i;

    for(i=0; s[i] != '\0'; i++)
        hash[s[i] - 97]++;

    for(i=0; i < 26; i++){
        if(hash[i] > 1){
            printf("%c : ", i+97);
            printf("%d\n", hash[i]);
        }
    }
}

//finding duplicates in string using bit operations
//for string with small letter
void Duplicates3(char* s){
    int h= 0, check=0;// h stores letter value which appear, check strores value of duplicate
    int a;// a helps in merging and masking
    int i;

    for(i=0; s[i] != '\0'; i++){
        a=1;
        a = a<<s[i]-97;

        if( (h & a) > 0)
            check = a | check;
        else 
            h = a | h; 
    }

    for(i=0; i<26; i++){
        //masking process
        a=1;
        a = a<<i;
        if(a & check) printf("%c\n", i+97 ); 
    }

}

//checking angram only for lower case

//only for strings with distinct letter
int Anagram(char* a, char* b){
    int i, j;

    if(Length(a) != Length(b)) return 0;

    for(i=0; a[i] != '\0'; i++)
        if(Search(b, a[i]) == -1) return 0;

    return 1;
}

//for string with duplicates letter
int Anagram2(char* a, char* b){
    int hash[26] = {0};
    int i;

    for(int i=0; a[i] != '\0'; i++)
        hash[a[i] -97] ++;
    
    for(int i=0; b[i] != '\0'; i++)
        hash[b[i] -97 ] --;

    for(i=0; i<26; i++)
        if(hash[i] != 0) return 0; 

    return 1;
}


//printing all permutation of a string
void Permutation(char* s){

}

int main()
{

    char a[100] = "verbosee";
    char b[100] = "observeee";
   
   printf("%s", Anagram2(a, b) ? "yes" : "no" );

    return 0;
}