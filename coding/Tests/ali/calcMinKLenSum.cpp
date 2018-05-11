#include <iostream>
#include <string>
using namespace std;

/*
 * 给定两个由数字0-9组成的字符数组，如“2345”， “4436”，从这两个数组分别取数，生成新数组。
 * 比如生成：44234365，生成方式如下图所示，每个数组取数放入新数组的时候，是按照下标从小到大取得。
 * 对于字符数组，定义跨度值：K(c)，为数字c最大下标和最小下标之差。比如数字44234365每个数字的K(c)定义如下：
 *  num   2  3 4 5 6
 *  K(c)   0  2 4 0 0
 * 请找到一种取合成方式，使得K(c)的总和最小（比如，上例总和为6，但总和并非最小）。打印出最小的K(c) 之和。
 *
 * 输入范例:
 * 2345
 * 4436
 * 输出范例:
 * 5
 */

/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */

/******************************开始写代码******************************/

// 思路使用递归遍历
int calcMinKLenSum(string& first, string& second){
    int max=0;
    int len_first = first.size();
    int len_second = second.size();
    int *tmp = new int[len_first][len_second];
    return max;
}

/******************************结束写代码******************************/

int main() {
    string first, second;
    cin >> first >> second;
    int sum = calcMinKLenSum(first, second);
    cout << sum << endl;
    return 0;
}
