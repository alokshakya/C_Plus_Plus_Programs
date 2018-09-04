#include <iostream>
using namespace std;

int main()
{
    string input, output;

    while(getline(cin , input))
    {

        bool foundComment = false;
        output = "";

        for(int i = 0; i < input.size(); i++)
        {

            if(foundComment){

                output += input[i];
                continue;
            }

            if(i < input.size() - 1 && input[i] == '/' && input[i + 1] == '/')
            {

                output += "//";
                foundComment = true;
                i++;
            }

            else if(i < input.size() - 1 && input[i] == '-' && input[i + 1] == '>')
            {

                output += '.';
                i++;

            }
            else
                output += input[i];
        }

        cout << output << endl;
    }

    return 0;
}
