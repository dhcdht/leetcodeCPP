// https://leetcode.com/problems/nim-game/#/description
// 292. Nim Game
/*
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 */

class Solution11 {
public:
    bool canWinNim(int n) {
        int mask1 = 0x1;
        int mask2 = 0x2;

        int mask1Result = n ^mask1;
        int mask2Result = n ^mask2;
        if (mask1Result > n && mask2Result > n) {
            return false;
        }


        return true;
    }

    void test() {
        int num = 8;
        bool result = this->canWinNim(num);
        cout << "292. Nim Game : " << result << endl;
    }
};
