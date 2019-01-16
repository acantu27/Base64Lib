#ifndef BASE64LIB_BASE64_H
#define BASE64LIB_BASE64_H

#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#define LEAST_SIG_BITS '0'
#define PADDING '='

namespace Base64 {
    const std::vector<char> encodeTable{
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
            'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
            'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', '+', '/'
    };

    static std::unordered_map<char, char> decodeTable{
            {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4},
            {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9},
            {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14},
            {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
            {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24},
            {'Z', 25}, {'a', 26}, {'b', 27}, {'c', 28}, {'d', 29},
            {'e', 30}, {'f', 31}, {'g', 32}, {'h', 33}, {'i', 34},
            {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39},
            {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44},
            {'t', 45}, {'u', 46}, {'v', 47}, {'w', 48}, {'x', 49},
            {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54},
            {'3', 55}, {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59},
            {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63}
    };

    short int padding;
    short int leastSigBit;

    class Base64 {
    private:
        std::string output;
        std::string input;


        void encodePadding(int len) {
            if (len == 1) { padding = 2; leastSigBit = 4; }
            else if (len == 2) { padding = 1; leastSigBit = 2; }
            else {
                if (len % 3 == 0) { padding = 0; leastSigBit = 0; }
                else if (len % 3 == 1) { padding = 2; leastSigBit = 4; }
                else { padding = 1; leastSigBit = 2; }
            }
        }

        void decodePadding() {
            size_t n = std::count(input.begin(), input.end(), '=');
            if(n == 2) { padding = 2; leastSigBit = 4; }
            else if(n == 1) { padding = 1; leastSigBit = 2; }
            else { padding = 0; leastSigBit = 0; }
        }

    public:
        std::string encode64(std::string str) {
            input = str.c_str();
            std::string binaryStr = "";
            std::string temp = "";
            encodePadding(input.length());

            for (int i = 0; i < input.length(); i++) {
                binaryStr += std::bitset<8>(input[i]).to_string();
                if ((leastSigBit == 2) && (input.length() == (i + 1)))
                    binaryStr.append(2u, LEAST_SIG_BITS);
                else if ((leastSigBit == 4) && (input.length() == (i + 1)))
                    binaryStr.append(4u, LEAST_SIG_BITS);
            }

            for (int i = 0; i < binaryStr.length(); i += 6) {
                temp = binaryStr.substr(i, 6);
                unsigned long sextet = std::bitset<6>(temp).to_ulong();
                output += encodeTable.at(sextet);
            }

            if(padding == 1)
                output += PADDING;
            else if(padding == 2)
                output.append(2u, PADDING);

            return output;
        }

        std::string decode64(std::string str) {
            input = str;

            std::string temp = "";
            std::string another = "";

            if(padding == 1)
                input.pop_back();
            else if(padding == 2)
                input.resize(input.length()-2);

            for(int i = 0; i < input.length(); i++)
                temp += std::bitset<6>(decodeTable[input[i]]).to_string();

            if(leastSigBit == 2)
                temp.resize(temp.length()-2);
            if(leastSigBit == 4)
                temp.resize(temp.length()-4);

            for(int i = 0; i < temp.length(); i+=8) {
                another = temp.substr(i, 8);
                output += char(std::bitset<8>(another).to_ulong());
            }

            output.erase(std::find(output.begin(), output.end(), '\0'), output.end());
            return output;
        }

    };
}   // End of Namespace

#endif //BASE64LIB_BASE64_H
