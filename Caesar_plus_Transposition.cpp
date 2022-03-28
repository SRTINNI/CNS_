#include<bits/stdc++.h>
using namespace std;

//CC encrypt
string encrypt(string text, int shift)
{
    string str = "";
    for(int i=0; i<text.size(); i++)
    {
        if(isupper(text[i]))
        {
            char ch = (text[i]+shift-'A')%26 + 'A';
            str.push_back(ch);
        }
        else if(islower(text[i]))
        {
            char ch = (text[i]+shift-'a')%26 + 'a';
            str.push_back(ch);
        }
        else
            str.push_back(text[i]);
    }
    return str;
}
//CC decrypt
string decrypt(string text, int shift)
{
    string str = "";
    for(int i=0; i<text.size(); i++)
    {
        if(isupper(text[i]))
        {
            char ch = (text[i]+shift-'A')%26 + 'A';
            str.push_back(ch);
        }
        else if(islower(text[i]))
        {
            char ch = (text[i]+shift-'a')%26 + 'a';
            str.push_back(ch);
        }
        else
            str.push_back(text[i]);
    }
    return str;
}

// TC decrypt
string decrypt_tc(string text, int width)
{
    string str(text.size(), ' ');
    int col = 0, j = 0;
    for(int i=0; i<text.size(); i++)
    {
        str[j] = text[i];
        j += width;
        if(j >= text.size())
            j = ++col;
    }
    return str;
}

//TC encrypt
string encrypt_tc(string text, int width)
{
    string str;
    int col = 0, i = 0;
    while(col < width)
    {
        str.push_back(text[i]);
        i += width;
        if(i >= text.size())
            i = ++col;
    }
    return str;
}


int main()
{
    string text;
    cout<<"Enter your original text: ";
    getline(cin, text);

    cout<<endl<<endl;
    cout<<"........Caesar Cipher..........."<<endl<<endl;

    int shift;
    cout<<"Enter how many shift to the right: ";
    cin>>shift;
    shift = shift%26;

    cout<<"\nPlain Text: "<<text<<endl;

    string chiper = encrypt(text, shift);
    cout << "\nEncrypted Cipher: " << chiper <<endl;

    string original = decrypt(chiper, 26-shift);
    cout << "\nAfter Reverse Operation(Decryption): " << original <<endl<<endl;


    cout<<"...........Transposition Cipher........."<<endl;

   // cout<<"\nPlain Text: "<<text<<endl;
    int width;
    cout<<"Enter width: ";
    cin>>width;
    string chiper_tc = encrypt_tc(text, width);
    cout << "\nEncrypted Cipher: " << chiper_tc <<endl;

    string original_tc = decrypt_tc(chiper_tc, width);
    cout << "\nAfter Reverse Operation(Decryption): " << original_tc <<endl;



    return 0;
}


