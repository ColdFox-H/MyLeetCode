#pragma once
#include <vector>
#include <iostream>
using namespace std;

string letterToMorse(char letter);
int compareMos(string mos, vector<string>& mosCompare);
int uniqueMorseRepresentations(vector<string>& words) {
    int size = words.size();
    if (size == 1)return 1;
    vector<string> mos(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            mos[i] += letterToMorse(words[i][j]);
        }
    }
    vector<string> mosCompare = {mos[0]};
    bool isSame = false;
    int res = 0;
    for (int i = 1; i < size; ++i) {
        res += compareMos(mos[i], mosCompare);
    }
    return res;
}

int compareMos(string mos, vector<string>& mosCompare) {
    for (int i = 0; i < mosCompare.size(); ++i) {
        if (mos == mosCompare[i])return 0;
    }
    mosCompare.push_back(mos);
    return 1;
}
//将字母转换成摩尔斯码
string letterToMorse(char letter) {
    if (letter == 'a')return ". - ";
    if (letter == 'b')return " - ...";
    if (letter == 'c')return " - . - .";
    if (letter == 'd')return "-..";
    if (letter == 'e')return ".";
    if (letter == 'f')return "..-.";
    if (letter == 'g')return "--.";
    if (letter == 'h')return "....";
    if (letter == 'i')return "..";
    if (letter == 'j')return ".---";
    if (letter == 'k')return "-.-";
    if (letter == 'l')return ".-..";
    if (letter == 'm')return "--";
    if (letter == 'n')return "-.";
    if (letter == 'o')return "---";
    if (letter == 'p')return ".--.";
    if (letter == 'q')return "--.-";
    if (letter == 'r')return ".-.";
    if (letter == 's')return "...";
    if (letter == 't')return "-";
    if (letter == 'u')return "..-";
    if (letter == 'v')return "...-";
    if (letter == 'w')return ".--";
    if (letter == 'x')return "-..-";
    if (letter == 'y')return "-.--";
    if (letter == 'z')return "--..";
    return "";
}
