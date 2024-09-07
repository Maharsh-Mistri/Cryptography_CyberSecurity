#include <bits/stdc++.h>
using namespace std;


string EncryptText(string plainText, string key)
{
    int size=0;
    for(int i=0;i<plainText.length();i++)
    {
        if(isalpha(plainText[i]))
        size++;
        
    }
    int temp = size / key.length();
    int rem = size % key.length();
    string keyz;
    while(temp--){
        keyz+=key;
    }
    temp=0;
    while(rem--){
        keyz+=key[temp++];
    }
    string encryptedText = "";
    temp=0;
    for (int i = 0; i < plainText.length(); i++)
    {
        if(isalpha(plainText[i])){
            if(plainText[i] >= 'a' && plainText[i] <= 'z' ){
                encryptedText+=(char) ((( (plainText[i]-'a') + (keyz[temp++]-'a')) %26 ) +'a');
            }
            
            
        }
        
        if(plainText[i] == ' '){
            encryptedText += ' '; 
        }
    }
    return encryptedText;
}
string DecryptText(string encryptedText, string key)
{
   
    int size=0;
    for(int i=0;i<encryptedText.length();i++)
    {
        if(isalpha(encryptedText[i]))
        size++;
    }
    int temp = size / key.length();
    int rem = size % key.length();
    string keyz;
    while(temp--){
        keyz += key ;
    }
    temp=0;
    while(rem--){
        keyz += key[temp++];
    }
    temp=0;
    string plainText = "";
    for (int i = 0; i < encryptedText.length(); i++)
    {
        if(isalpha(encryptedText[i])){
            if(encryptedText[i] >= 'a' && encryptedText[i] <= 'z' ){
                plainText+=((( encryptedText[i]-'a')-(keyz[temp++]-'a') +26 )%26 +'a');
            }
            
                     
        }
        if( encryptedText[i] == ' '){
           plainText += ' '; 
        }
    }

    return plainText;
}
int main()
{   
    bool flag = true;
    while(true){
        string Text;
        string key;
        if(flag){
            
            cout<<"Enter the PlainText Here: ";
            getline(cin,Text);
            cout<<"Enter key: ";
            
            getline(cin,key);
            flag = false;
        }

        cout<<"Encripted Text is: "<<EncryptText(Text,key)<<endl;

        cout<<"Decripted Text is: "<<DecryptText(EncryptText(Text,key),key)<<endl;

        
        cout << "wanted to continue ? (y/n): "; 
        char y;
        cin>>y;
        if(y == 'y'){
            flag = true;
        }else{
            cout<<"Exiting..."<<endl;
            break;
        }
        cin.ignore();//To clear new linw entering char otherwise it will go into infinite loop

    }
    

    return 0;
}