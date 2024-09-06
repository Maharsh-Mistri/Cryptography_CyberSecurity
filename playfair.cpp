#include<bits/stdc++.h>
using namespace std;

char m[5][5];
bool char_check[26] = {false};

// Function to create the 5x5 matrix using the key
void make_m(const string& key) {
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string combined_key = key;
    unordered_set<char> used_chars;

    // Append the rest of the alphabet (excluding 'J') to the key
    for (char c : alphabet) {
        if (combined_key.find(c) == string::npos) {
            combined_key += c;
        }
    }

    // Fill the matrix
    int idx = 0;
    for (char c : combined_key) {
        if (!used_chars.count(c) && c != 'J') {
            used_chars.insert(c);
            m[idx / 5][idx % 5] = c;
            idx++;
        }
    }
}

// Function to prepare the plaintext for encryption
string make_text(const string& text) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'R';
            result += c;
        }
    }

    for (int i = 0; i < result.length() - 1; i += 2) {
        if (result[i] == result[i + 1]) {
            result.insert(i + 1, 1, 'X');
        }
    }
    if (result.length() % 2 != 0) {
        result += 'Z';
    }
    return result;
}

// Function to find the position of a character in the matrix
pair<int, int> find(char c) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (m[i][j] == c) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Function to encrypt a pair of characters
string enc_char(char a, char b) {
    auto A = find(a);
    auto B = find(b);

    if (A.first == B.first) {
        // Same row
        return string(1, m[A.first][(A.second + 1) % 5]) + m[B.first][(B.second + 1) % 5];
    } else if (A.second == B.second) {
        // Same column
        return string(1, m[(A.first + 1) % 5][A.second]) + m[(B.first + 1) % 5][B.second];
    } else {
        // Rectangle
        return string(1, m[A.first][B.second]) + m[B.first][A.second];
    }
}

// Function to encrypt the plaintext
string enc(const string& text) {
    string ciphertext;
    for (size_t i = 0; i < text.length(); i += 2) {
        ciphertext += enc_char(text[i], text[i + 1]);
    }
    return ciphertext;
}

string dec_char(char a, char b) {
    auto A = find(a);
    auto B= find(b);

    if (A.first == B.first) {
        // Same row
        return string(1, m[A.first][(A.second + 4) % 5]) + m[B.first][(B.second + 4) % 5];
    } else if (A.second == B.second) {
        // Same column
        return string(1, m[(A.first + 4) % 5][A.second]) + m[(B.first + 4) % 5][B.second];
    } else {
        // Rectangle
        return string(1, m[A.first][B.second]) + m[B.first][A.second];
    }
}

// Function to decrypt a string using the Playfair cipher
string dec(const string &text) {
    string decrypted;
    for (int i = 0; i < text.length(); i += 2) {
        decrypted += dec_char(text[i], text[i + 1]);
    }
    return decrypted;
}

int main() {
    string key, plaintext;
    
    cout << "Enter the key: ";
    getline(cin, key);
    for (auto &c : key) c = toupper(c);
    
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    for (auto &c : plaintext) c = toupper(c);
    
    make_m(key);
    string cph_text = enc(make_text(plaintext));

    string dec_text = dec(enc(make_text(plaintext)));
    
    cout << "Ciphertext: " << cph_text << endl;
    cout << "decrrepted text: " << dec_text <<endl; 
    return 0;
}