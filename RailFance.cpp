#include<bits/stdc++.h>
using namespace std;

// Function to encrypt the text using Rail Fence Cipher
string encryptRailFence(const string& text, int numRails) {
    if (numRails <= 1) return text; // No encryption 

    vector<string> railMatrix(numRails);
    int rail = 0;
    bool directionDown = false;

    // Place characters in the rail matrix in a zig-zag manner
    for (char ch : text) {
        railMatrix[rail] += ch;

        if (rail == 0 || rail == numRails - 1) {
            directionDown = !directionDown; // Change direction
        }

        rail += directionDown ? 1 : -1;
    }

    // Collect characters from the rail matrix row by row
    string cipherText;
    for (const auto& railString : railMatrix) {
        cipherText += railString;
    }

    return cipherText;
}

// Function to decrypt the text using Rail Fence Cipher
string decryptRailFence(const string& cipherText, int numRails) {
    if (numRails <= 1) return cipherText; // No decryption 
    
    vector<string> railMatrix(numRails, string(cipherText.length(), '\0'));
    int rail = 0;
    bool directionDown = false;

    // Mark positions in the rail matrix
    for (int i = 0; i < cipherText.length(); ++i) {
        railMatrix[rail][i] = '*';

        if (rail == 0 || rail == numRails - 1) {
            directionDown = !directionDown; // Change direction
        }

        rail += directionDown ? 1 : -1;
    }

    // Fill the marked positions with the ciphertext
    int index = 0;
    for (int i = 0; i < numRails; ++i) {
        for (int j = 0; j < cipherText.length(); ++j) {
            if (railMatrix[i][j] == '*' && index < cipherText.length()) {
                railMatrix[i][j] = cipherText[index++];
            }
        }
    }

    // Read the plaintext from the rail matrix in a zig-zag manner
    string plainText;
    rail = 0;
    directionDown = false;

    for (int i = 0; i < cipherText.length(); ++i) {
        plainText += railMatrix[rail][i];

        if (rail == 0 || rail == numRails - 1) {
            directionDown = !directionDown; // Change direction
        }

        rail += directionDown ? 1 : -1;
    }

    return plainText;
}

int main() {
    
    bool flag = true;
    while(true){
        string text;
        int numRails = 0;
    if(flag){
        cout << "Enter Plain Text: " ;
        getline(cin,text);
        
        cout << "Enter number of rails: ";
        cin >> numRails;
        flag = false;
    }
        

        string encrypted = encryptRailFence(text, numRails);
        cout << "Encrypted: " << encrypted << endl;

        string decrypted = decryptRailFence(encrypted, numRails);
        cout << "Decrypted: " << decrypted << endl;
    
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
