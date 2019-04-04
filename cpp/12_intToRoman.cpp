/*
 * At the first, i think 800 is VIIIC
 */
class Solution {
public:
    string intToRoman(int num) {
        string res;
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < 13; i++) {
            while(num >= values[i]) {
                res += romans[i];
                num -= values[i];
            }
        }
        return res;
    }
};