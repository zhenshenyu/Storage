#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
 *LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
 * 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
 * “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
 * LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
 * 上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。
 * 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
 */

class Solution {
public:
    bool IsContinuous(const vector<int> &numbers) {
        int _min=13;
        int _max=1;
        if (numbers.size() != 5) {
            return false;
        }
        vector<int> tmp;
        for (auto elem:numbers) {
            if (elem != 0) {
                if (find(tmp.begin(), tmp.end(), elem) != tmp.end()) {
                    return false;
                }
                tmp.push_back(elem);
                _min = min(_min, elem);
                _max = max(_max, elem);
            }
        }
        return _max - _min < 5;
    }
};

/*
 * 有优化空间，现在使用数组存储已有数字，再判断是否重复
 * 可以用bit map的方法判断是否重复
 */
