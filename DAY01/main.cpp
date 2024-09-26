#include <iostream>
#include <string>




struct ci_char_traits : public std::char_traits<char>
{
    static bool eq(char c1, char c2)
    {
        return toupper(c1) == toupper(c2);}
    static bool lt(char c1, char c2)
    {return std::toupper(c1) < std::toupper(c2); }

    static int compare(const char *s1, const char *s2, size_t n)
    {
        char * nc1, *nc2;
        nc1 = new char[n];
        nc2 = new char[n];
        size_t N = n-1;
        for(int i = 0; i < N; ++i)
        {
            nc1[i] = toupper(s1[i]);
            nc2[i] = toupper(s2[i]);
        }
        int result = std::__memcmp(nc1, nc2, n);
        delete []nc1;
        delete []nc2;// ???

        return result;
    }


    static const char * find(const char * s, int n, char a)
    {
        while(n-- > 0 && toupper(*s) != toupper(a))
        {
            ++s;
        }
        return n >= 0 ? s : nullptr;
    }
};


typedef std::basic_string<char, ci_char_traits> ci_string;

int main(int argc, char **argv) {

    ci_string str1("CaT");
    ci_string str2("CAT");

    std::cout << (str1 == str2);
}
