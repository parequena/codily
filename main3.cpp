#include <string>
#include <iostream>
#include <cstdint>

std::string solution(std::string&& S)
{
    auto remove = [](std::string const& str)
    {
        return str == "AB" || str == "BA" || str == "CD" || str == "DC";
    };

    std::string ret { "" };
    auto const size { S.size() };
    for(std::size_t i{}; i < size - 1; ++i)
    {
        std::string chars{ S[i] };
        chars += S[i + 1];

        if(!remove(chars)) { ret += S[i]; }
        else { ++i; }
    }

    if(size % 2 == 0)
    {
        ret += S[size - 1];
    }

    for(std::size_t i{}; i < ret.size(); ++i)
    {
        std::string chars{ ret[i] };
        chars += ret[i + 1];

        if(remove(chars)) { ret = ret.substr(2); }
        else { ++i; }
    }

    return ret;
}

int main()
{
    auto sol = solution("CBACD");
    // auto sol = solution("CABABD");

    return 0;
}