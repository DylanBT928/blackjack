#include <iostream>
#include <map>

int main()
{
    std::unordered_map<char, int> values = {
        {'K', 10}, {'Q', 10}, {'J', 10},
        {'T', 10}, {'9', 9}, {'8', 8},
        {'7', 7}, {'6', 6}, {'5', 5},
        {'4', 4}, {'3', 3}, {'2', 2},
        {'A', 1}
    };

    char deck[] = {
        'K', 'K', 'K', 'K',
        'Q', 'Q', 'Q', 'Q',
        'J', 'J', 'J', 'J',
        'T', 'T', 'T', 'T',
        '9', '9', '9', '9',
        '8', '8', '8', '8',
        '7', '7', '7', '7',
        '6', '6', '6', '6',
        '5', '5', '5', '5',
        '4', '4', '4', '4',
        '3', '3', '3', '3',
        '2', '2', '2', '2',
        'A', 'A', 'A', 'A'
    };

    std::cout << "Cards Left: " << sizeof(deck) << std::endl;
    std::cout << "Dealer's Hand: " << std::endl;
    std::cout << "Your Hand: " << std::endl;

    return 0;
}
