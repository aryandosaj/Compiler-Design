#include <bits/stdc++.h>
#include <string.h>
using namespace std;
vector<char> pun;
vector<string> opr;
vector<string> key;
vector<string> iden;
vector<string> con;
vector<string> floating_num;
vector<string> str;
vector<string> chr;
vector<string> e_num;

vector<string> keywords;
vector<string> operators;

int chkidentifier(string s)
{
    int i = 0;
    if (s[i] == '_' || (s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A'))
        return 1;
    else
        return 0;
}
int chkkeyword(string s)
{
    int k = 13, i = 0;
    string keywords[100] = {"#include","main", "int", "float", "double", "char", "bool", "long", "for", "while", "if", "break","return"};
    for (i = 0; i < k; i++)
        if (s.compare(keywords[i]) == 0)
            return 1;
    return 0;
}
int chkoperator(string s)
{
    int k = 10, i = 0;
    string oper[100] = {"+", "-", "*", "/", ">", "<", "=", "++", "--", "=="};
    for (i = 0; i < k; i++)
        if (s.compare(oper[i]) == 0)
        {
            return 1;
        }
    return 0;
}
int punctuation(char c)
{
    if (c == '}' || c == '{' || c == ';' || c == '(' || c == ')' || c == ',')
        return 1;
    return 0;
}
int oper(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '<' || c == '>' || c == '=')
        return 1;
    return 0;
}
void chkconstant(string s)
{
    if (s[0] == '"')
    {
        str.push_back(s);
        return;
    }
    if (s[0] == '\'')
    {
        chr.push_back(s);
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            floating_num.push_back(s);
            return;
        }
        else if (s[i] == 'e')
        {
            e_num.push_back(s);
            return;
        }
    }
    con.push_back(s);
}
void fun(string s)
{
    if (s.size() == 0)
        return;
    if (chkkeyword(s))
        key.push_back(s);
    else if (chkidentifier(s))
        iden.push_back(s);
    else if (chkoperator(s))
        opr.push_back(s);
    else
        chkconstant(s);
}

int main()
{
    freopen("input.txt", "r", stdin);
    string s = "";
    while (cin >> s)
    {
        if (s.size() >= 2)
        {
            if (s[0] == '/' && s[1] == '/')
            {
                getline(cin, s);
                continue;
            }
        }
        int j = 0, k = 0;
        string temp = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (punctuation(s[j]))
            {
                pun.push_back(s[j]);
                fun(temp);
                temp.clear();
            }
            else if (oper(s[j]))
            {

                fun(temp);
                string t2 = "";
                int c = 0;
                while (c < 2 && oper(s[j]))
                {
                    t2.push_back(s[j++]);
                    c++;
                }
                opr.push_back(t2);
                j--;
                temp.clear();
            }
            else
            {
                temp.push_back(s[j]);
            }
        }
        fun(temp);
    }
    cout << "Keyword : ";
    for (int i = 0; i < key.size(); i++)
        cout << key[i] << " ";
    cout << "\n";
    cout << "Identifier : ";

    for (int i = 0; i < iden.size(); i++)
        cout << iden[i] << " ";
    cout << "\n";
    cout << "Constant : ";

    for (int i = 0; i < con.size(); i++)
        cout << con[i] << " ";
    cout << "\n";
    cout << "Punctuation : ";

    for (int i = 0; i < pun.size(); i++)
        cout << pun[i] << " ";
    cout << "\n";
    cout << "Operator : ";
    for (int i = 0; i < opr.size(); i++)
        cout << opr[i] << " ";
    cout << "\n";
    cout << "Number : ";
    for (int i = 0; i < con.size(); i++)
        cout << con[i] << " ";
    cout << "\n";
    cout << "Floating Number : ";
    for (int i = 0; i < floating_num.size(); i++)
        cout << floating_num[i] << " ";
    cout << "\n";
    cout << "Exponential Number : ";
    for (int i = 0; i < e_num.size(); i++)
        cout << e_num[i] << " ";
    cout << "\n";
    cout << "Character : ";
    for (int i = 0; i < chr.size(); i++)
        cout << chr[i] << " ";
    cout << "\n";
    cout << "String : ";
    for (int i = 0; i < str.size(); i++)
        cout << str[i] << " ";
    cout << "\n";
}
