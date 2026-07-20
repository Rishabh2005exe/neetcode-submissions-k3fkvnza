class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double product = 1;

        while (N) {
            if (N & 1)
                product *= x;

            x *= x;
            N >>= 1;
        }

        return product;
    }
};