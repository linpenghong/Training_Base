#include <regex>
#include <iostream>

using namespace std;

int main()
{
    const char cstr0[] = "C3";
    const char cstr1[] = "ABC3";
    const char cstr2[] = "C3DE";

    regex e("C[[:digit:]]", regex_constants::extended);
    // regex e("C[[:digit:]]");
    // regex e("C[[\\d]]+", regex_constants::extended);
    // regex e("C[[\\d]]+", regex_constants::match_default);
    // regex e("C[\\d]+");

    if (regex_match(cstr0, e))
        cout << "0: string object matched\n";

    if (regex_match(cstr1, e))
        cout << "1: string object matched\n";

    if (regex_match(cstr2, e))
        cout << "2: string object matched\n";

    return 0;
}
