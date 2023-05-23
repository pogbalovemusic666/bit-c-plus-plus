// lesson8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
using namespace std;
#include <iostream>
#include"mystring.h"

//#include"string"
//using namespace std;
//class Solution {
//public:
//
//   
//
//
//
//    bool ischar(char ch)
//    {
//        if ((ch <= 'z' && ch>='a') || (ch <= 'Z' && ch>='A'))
//            return true;
//
//        return false;
//
//    }
//
//
//    string reverseOnlyLetters(string s) {
//
//        int begin = 0;
//
//        int end = s.size() - 1;
//
//
//        while (begin < end)
//        {
//            while (begin < end && !(ischar(s[begin])))
//            {
//                begin++;
//
//
//            }
//            while (begin < end && !(ischar(s[end])))
//            {
//                end--;
//
//
//            }
//
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//
//        }
//        return s;
//    }
//};




//
//
//
//class Solution {
//public:
//    int firstUniqChar(string s) {
//
//        //         string copy(s);
//
//
//        // while(copy.size()!=0)
//        // {
//        //         int ret=0;
//        //         int compare=1;
//
//        //         int eraseflag=0;
//        //         while(compare<=copy.size()-1)
//        //         {
//
//        //             if(copy[ret]==copy[compare])
//        //             {
//        //                 copy.erase(compare,1);
//
//        //                 eraseflag=1;
//        //             }
//        //             else
//        //             {
//        //                 compare++;
//
//        //             }
//
//
//        //         }
//        //         if(eraseflag==1)
//        //         copy.erase(ret,1);
//        //         else
//        //         {
//        //         return s.find(copy[ret]);
//
//        //         }
//        // }
//        //     return -1;
//
//
//
//        //时间复杂度为o（n）
//        int count[26] = { 0 };
//        for (auto ch : s)
//        {
//            count[ch - 'a']++;
//
//        }
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (count[s[i] - 'a'] == 1)
//                return i;
//
//
//
//        }
//
//
//        return -1;
//
//
//
//    }
//};




using namespace jhx;
//using std::cout;

int main()
{
 /*   string s("aadadaad");
    Solution str;
   int out= str.firstUniqChar(s);


   
    std::cout << out;*/


  
    jhx::string s1;
    s1.test1();

   /* for (auto ch : str)
    {

        cout << str;

    }*/



}

