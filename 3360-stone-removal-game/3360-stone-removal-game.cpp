
class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool aliceTurn = true;

        while (true) {
            if (n < remove) {
                return !aliceTurn;
            }

            n -= remove;
            remove--;

            aliceTurn = !aliceTurn;
        }
    }
};