#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#include "vector.h"


class Solution1 {
public:


    int myAtoi(string s) {
        // 处理前导空格
        size_t start = s.find_first_not_of(' ');
        if (start == string::npos) {
            return 0;  // 字符串全是空格
        }

        // 处理符号
        int sign = 1;
        if (s[start] == '-' || s[start] == '+') {
            sign = (s[start] == '-') ? -1 : 1;
            start++;
        }

        // 转换数字
        long result = 0;  // 使用 long 类型来检测溢出
        while (start < s.length() && isdigit(s[start])) {
            result = result * 10 + (s[start] - '0');
            if (result * sign > INT_MAX) {
                return INT_MAX;  // 正溢出
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;  // 负溢出
            }
            start++;
        }

        return result * sign;
    }
};





int main()
{
	
	luow::test_vector1();
	luow::test_vector2();
	/*luow::test_vector3();
	luow::test_vector4();
	luow::test_vector5();*/
	luow::test_vector6();
	luow::test_vector7();

	return 0;
}