#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

int solution(std::vector<int> &&A, int M)
{
    std::unordered_map<int, int> map;

    auto calculateDist = [&M](int const d1, int const d2)
    {
        return std::abs(d1 - d2) % M;
    };
    
    for(std::size_t i {}; i < A.size(); ++i)
    {
        for(std::size_t j{ i }; j < A.size(); ++j)
        {
            auto const d1 = A[i];
            auto const d2 = A[j];

            auto const d = calculateDist(d1, d2);
            if(d == 0)
            {
                ++map[i];
            }
        }
    }

    int max { 0 };
    for(auto m : map)
    {
        if(m.second > max)
        {
            max = m.second;
        }
    }

    return max;
}

int main(int, char**) {

    auto sol = solution( {-3, -2, 1, 0, 8, 7, 1}, 3 );
    // auto sol = solution( {7, 1, 11, 8, 4, 10}, 8 );

    return 0;
}
