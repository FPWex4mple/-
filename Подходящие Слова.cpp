#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    getline(cin, input);
    istringstream iss(input);
    unordered_map<string, int>word_count;

    string word;
    while(iss>>word){
        if(word == "end"){
            break;
        }
        word_count[word]++;
    }

    vector<string>repeated_words;

    for(const auto& pair : word_count){
        if(pair.second > 1){
            repeated_words.push_back(pair.first);
        }
    }

    sort(repeated_words.begin(), repeated_words.end());
    for(const auto& word : repeated_words){
        cout<<word<<" ";
    }

    return 0;
}
