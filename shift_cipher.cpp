#include <bits/stdc++.h>
using namespace std;
string EncriptText(string plainText, int key)
{
    
    string encriptedText = "";
    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            encriptedText += char((plainText[i] - 'a' + key) % 26 + 'a');
        }
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            encriptedText += char((plainText[i] - 'A' + key) % 26 + 'A');
        }
        if(plainText[i] == ' '){
            encriptedText += plainText[i];
        }
    }
    
    return encriptedText;
}
string DecriptText(string encriptedText , int key)
{
    string plainText = "";
    for (int i = 0; i < encriptedText.length(); i++)
    {
        if (encriptedText[i] >= 'a' && encriptedText[i] <= 'z')
        {
            // plainText += char('z' + (plainText[i] - 'a' - key));
            plainText += char((encriptedText[i] - 'a' - key + 26) % 26 + 'a');
        }
        if (encriptedText[i] >= 'A' && encriptedText[i] <= 'Z')
        {
            // plainText += char('z' + (plainText[i] - 'a' - key));
            plainText += char((encriptedText[i] - 'A' - key + 26) % 26 + 'A');
        }
        if(encriptedText[i] == ' '){
            plainText += encriptedText[i];
        }
    }
    
    return plainText;
}

int main()
{   
    
    bool flag = true; 
    while(true){
    string Text; //plain text for incription
    int key = 3; //by default it is 3 
    if(flag){
    
    cout<<"Enter Text Here: " ;
    getline(cin,Text);  // getiing text
    
    cout << "enter the key for encription: ";
    cin >> key;
    if(key > 26){
        key = key%26;
    }
    flag = false;
    }
    
    
        cout<<"Encripted text is: "<<EncriptText(Text,key);
        cout<<endl;
    
    
        cout<<"Decripted text is: "<<DecriptText(EncriptText(Text, key),key);
        cout<<endl;
    
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
    
}