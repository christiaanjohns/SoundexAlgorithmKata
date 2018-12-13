//
// Created by christiaanjohns on 12/13/2018.
//
#include "Soundex.h"

/**
     * @brief pad word to 4 digits
     * @param word - input string
     * @return - padded string
     */
string Soundex::zeroPad(const string& word) const
{
    /*if(word.size() == 3)
    {
        return word + "0";
    }
    else if(word.size() == 2)
    {
        return word + "00";
    }
    else if(word.size() == 1)
    {
        return word + "000";
    } else return word;*/
    return word + "000";
}
/**
    * @brief Encode string to Soundex Algorithm format
    * @param word - string to code
    * @return - encoded string
    */
string Soundex::encode(const string& word) const
{
    return zeroPad(word);
}