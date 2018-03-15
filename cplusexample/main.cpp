//
//  main.cpp
//  cplusexample
//
//  Created by Tahir Hameed on 3/1/18.
//  Copyright © 2018 AtTech. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isSpecialCharacter(char keywordtosearch[]){
    char specialCharacters[6][10] = {"{","}","<",">","<<",">>"};
    int i, flag = 0;
    for(i = 0; i < 32; ++i){
        if(strcmp(specialCharacters[i], keywordtosearch) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

bool isKeyword(char buffer[]){
    char keywords[33][10] = {"auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while","cout"};
    for(int i = 0; i < 32; i++){
        if(strcmp(keywords[i], buffer) == 0){
            return true;
        }
    }
    return false;
}

bool isThisOperator(char ch){
    char operators[] = "+-*/%=";
    for(int i = 0; i < 6; ++i){
        if(ch == operators[i])
            return true;
    }
    return false;
}

bool isThisValidIDorNot(char buffer[]){
    return true;
}

int main(){
    char ch, buffer[15];
    ifstream fin("/Users/akhzar/Desktop/LexicalAnalyzerFinalCode/cplusexample/program.txt");
    int j=0;
    if(!fin.is_open()){
        cout<<"error while opening the file\n";
        exit(0);
    }
    while(!fin.eof()){
        ch = fin.get();
        if (isThisOperator(ch)) {
            cout<<"<operator,"<<ch<<">\n";
        }
        if(isalnum(ch)){
            buffer[j++] = ch;
        }else if((ch == ' ' || ch == '\n' || isThisOperator(ch)) && (j != 0)){
            buffer[j] = '\0';
            j = 0;
            if(isKeyword(buffer))
            cout<<"<keyword,"<<buffer<<">\n";
            else{
                // Is ID
                // Now check is this valid ID or not ?
                bool isThsiValid = isThisValidIDorNot(buffer);
                cout<<"<indentifier,"<<buffer<<">\n";
            }
        }
    }
    fin.close();
    return 0;
}
