#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

int solution(std::vector<int> &&blocks) {
    std::unordered_map<int, int> map{};

    for(std::size_t p { 0 }; p < blocks.size(); ++p)
    {
        auto origin = blocks[p];
        
        map[p] = 1;
        for(std::size_t i { p - 1 }; i < blocks.size(); --i)
        {
            auto const target = blocks[i];
            if(target < origin)
            {
                break;
            }

            origin = target;
            ++map[p];
        }

        for(std::size_t j { p + 1 }; j < blocks.size(); ++j)
        {
            auto const target = blocks[j];
            if(target < origin)
            {
                break;
            }

            origin = target;
            ++map[p];
        }
    }

    int max { 0 };
    for(auto m : map)
    {
        if(m.second > max) { max = m.second; }
    }

    return max;
}

int main(int, char**) {
    auto sol = solution( {2, 6, 8, 5} );
    // auto sol = solution( {1, 5, 5, 2, 6} );
    return 0;
}
