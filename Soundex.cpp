//
// Created by christiaanjohns on 12/13/2018.
//
#include "Soundex.h"
#include <unordered_map> //similar to a dictionary or lookup table

/**
     * @brief pad word to 4 digits
     * @param word - input string
     * @return - padded string
     */
string Soundex::zeroPad(const string& word) const
{
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + string(zerosNeeded, '0');
}
/**
    * @brief Encode string to Soundex Algorithm format
    * @param word - string to code
    * @return - encoded string
    */
string Soundex::encode(const string& word) const
{
    return zeroPad(head(word) + encodeDigits(tail(word)));
}
/**
 * @brief - Extract the first char of the string
 * @param word - input string
 * @return - first letter of string
 */
string Soundex::head(const string &word) const
{
    return word.substr(0,1);
}
/**
 * @brief - Return all but the first character
 * @param word - input string
 * @return - string from 2:End
 */
string Soundex::tail(const string &word) const
{
    return word.substr(1); //Substring funct - if you only pass one param, it will take from that index to the end of word
}
/**
 * @brief - Encode the string into digits using Soundex Algorithm rules
 * @param word - input string
 * @return - encoded string
 */
string Soundex::encodeDigits(const string &word) const
{
    string encoding;
    for (auto letter : word)
    {
        if(isComplete(encoding))
        {
            break;
        }
        if(encodeDigit(letter) != lastDigit(encoding))
        {
            encoding += encodeDigit(letter);
        }
    }
    return encoding;
}
/**
 * @brief - Encode single digit
 * @return - Encoded digit
 */
string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char, string> encoding //char is the key, string is the value
    {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"}
    };
    // Find the letter in the map and return the associated value
    // If you reach the end of the map and you have no match, then return an empty string, otherwise
    // return the value from the map that matches the passed in key.
    auto it = encoding.find(letter);
    return it == encoding.end() ? "" : it->second;

}
/**
 * @brief Return true or false when the encoding string reaches maximum size
 * @param encoding - input string
 * @return - True for complete, false otherwise
 */
bool Soundex::isComplete(const string &encoding) const
{
    return encoding.length() == MaxCodeLength -1;
}

/**
 * @brief Keep track of the last digit in the coding string
 * @param encoding - input string
 * @return - last encoding digit
 */
string Soundex::lastDigit(const string &encoding) const
{
    if (encoding.empty())
    {
        return "";
    }
    return std::string(1, encoding.back());
}
