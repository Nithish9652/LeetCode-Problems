class Solution {
public:
    int findComplement(int num) {
        int bLen=(31-__builtin_clz(num));
        int mask=(bLen==31)?INT_MAX:((1<<bLen)-1);
        return (INT_MAX^num)&mask;
    }
};