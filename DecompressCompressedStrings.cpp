#include <iostream>
#include <sstream>
using namespace std;

pair<string, int> decompress(string text, int start = 0, int times = 1)
{
    pair<string, int> result = make_pair("", 0);
    for (int x = 0; x < times; x++)
    {
        int i = start;
        while (i < text.size() && ']' != text[i])
        {
            if (islower(text[i]))
                result.first += text[i];
            else
            {
                int subtimes = 0;
                while (isdigit(text[i]))
                {
                    subtimes = subtimes * 10 + (text[i] - '0');
                    i++;
                }
                i++;
                pair<string, int> res = decompress(text, i, subtimes);
                result.first.append(res.first);
                i = res.second;
            }
            i++;
        }
        result.second = i;
    }

    return result;
}

int main()
{
    auto res = decompress("2[6[a]4[d]2[b]r]bc");
    cout << res.first << endl;
    cout << res.second << endl;
    return 0;
}
