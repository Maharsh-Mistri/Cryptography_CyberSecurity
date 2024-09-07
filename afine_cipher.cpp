#include<bits/stdc++.h>
using namespace std;

// int MulOfA(int a , int b){
//     int r1 =26 , r2 = b;
//     int t1 = 0 , t2 = 1 ;
//     int t,q,r;
//     while( r2 > 0 ){
//        q = r1/r2;
//        r = r1 - q*r2 ;
//        r1 = r2; 
//        r2 = r;
//        t = t1 - q*t2;
//        t1 = t2;
//        t2 = t;
//     }
//     if(r1 == 1){
//         return t1;
//     }
//     return t1;

// }

int MulOfA(int a , int b){

for ( int i = 1 ; i <= 26 ; i++){
    if(((a*i)% 26) == 1){
        return i;
        break;
    }
}
 
}

string encription(string plainText , int a, int b ){
  

    string temp = "";
    string cipherText = "";

    for( char c : plainText){
        if(isalpha(c)){
            temp += c;
        }
        if(c == ' '){
            temp += c;
        }
    }

    for(char c : temp){
        if( c>= 'a' && c<= 'z'){
            cipherText += (char) ((a*(c - 'a') + b) % 26)  + 'a';
        }
        if( c>= 'A' && c<= 'Z'){
            cipherText += (char) ((a*(c - 'A') + b) % 26)  + 'A';
        }
        if(c == ' '){
            cipherText += c;
        }
        
    }

    return cipherText;
}

string decription(string cipherText , int a,int b){
   
    int mulinv = MulOfA(a , b);
    
    string decriptedText = "";
    
    for(char c : cipherText){
        if(c >= 'a' && c <= 'z' ){
            decriptedText += (char) (mulinv*(c - 'a'- b + 26) % 26) % 26 + 'a';
        }
        if(c >= 'A' && c <= 'Z' ){
            decriptedText += (char) (mulinv*(c - 'A'- b + 26) % 26) % 26 + 'A';
        }
        if(c == ' '){
            decriptedText += c;
        }
        

        
    }

    return decriptedText;

}

int main (){
    bool flag = true;
    while(true){
    string plainText;
    int a,b;
   if(flag){
        
        cout<<"Enter a Plain text here: ";
        getline(cin,plainText);
        cout<<" Enter the value of A and B: ";
        cin>>a>>b;
       flag = false;
    }
    
    cout<< "PlainText Is: " << plainText << endl;
    cout<< "encripted text is: " << encription(plainText , a ,b)<<endl;
    cout<< "decripted text is: " << decription(encription(plainText , a, b),a,b)<<endl;

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