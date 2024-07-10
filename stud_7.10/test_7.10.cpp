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
        // ����ǰ���ո�
        size_t start = s.find_first_not_of(' ');
        if (start == string::npos) {
            return 0;  // �ַ���ȫ�ǿո�
        }

        // �������
        int sign = 1;
        if (s[start] == '-' || s[start] == '+') {
            sign = (s[start] == '-') ? -1 : 1;
            start++;
        }

        // ת������
        long result = 0;  // ʹ�� long ������������
        while (start < s.length() && isdigit(s[start])) {
            result = result * 10 + (s[start] - '0');
            if (result * sign > INT_MAX) {
                return INT_MAX;  // �����
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;  // �����
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