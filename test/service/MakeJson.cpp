#include "MakeJson.h"

string MakeJson::generate_token(){
    srand((unsigned int)time(NULL));
    char hex_characters[] ="0123456789abcdef";
    char* token_char = new char[16]; //to store values in for loop
    string token_string="";

    for (size_t j = 0; j < 16; j++){
        token_char[j] = hex_characters[rand() % 16];
        token_string = token_string + token_char[j];
    }

    delete[] token_char;
    return token_string;
}