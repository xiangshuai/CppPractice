/**<
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void split(string &s, string &delim, vector<string> &ret)
{
    string::size_type pos1, pos2;
    pos2 = s.find(' ');
    pos1 = 0;
    while (string::npos != pos2)
    {
        ret.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = s.find(' ', pos1);
    }
    if(pos2 - pos1 > 0)
    {
        ret.push_back(s.substr(pos1));
    }
}

void trim(string &s)
{
    string::iterator c;
    // Erase whitespace before the string

    for (c = s.begin(); c != s.end() && iswspace(*c++);); s.erase(s.begin(), --c);

    // Erase whitespace after the string

    for (c = s.end(); c != s.begin() && iswspace(*--c);); s.erase(++c, s.end());
}

void reverseWords(string &s)
{
    vector<string> ret;
    string delim = " ";
    split(s, delim, ret);
    string str;
    for(int i=0; i<ret.size(); i++)
    {
        str.append(ret[ret.size()-1-i]);
        str.append(delim);
    }
    trim(str);
    s = str;
}

int main()
{
    string str = "";
    cout << str.size() << endl;
    reverseWords(str);
    cout << str.size() <<endl;
    cout << str << endl;

    return 0;
}
