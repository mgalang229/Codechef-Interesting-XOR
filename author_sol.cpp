#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	// watch the video tutorial (link in this repository)
	// for better understanding
	while (tt--) {
		long long c;
		cin >> c;
		int id = 0;
		// get the highest value of 2 ^ i such that its Most Significant Bit(MSB)
		// is equal to the MSB of integer 'c'
		for (int i = 31; i >= 0; i--) {
			if ((1 << i) & c) {
				id = i;
				// once it's found, then stop the loop
				break;
			}
		}
		// create an 'f' variable to be used once only for the MSB of 'a' integer
		int f = 1;
		// create 'a' variable
		long long a = 0;
		// create 'b' variable
		long long b = 0;
		for (int i = id; i >= 0; i--) {
			if ((1 << i) & c) {
				// if the MSB of 2 ^ i is equal to the bit of 'c'
				// then it means that the current bit is 1
				if (f) {
					// in the first iteration, assign 1 to the MSB of 'a'
					// using the 'OR' bitwise operator
					a |= (1 << i);
					// set the 'f' variable to 0 because the rest of the
					// bits in 'a' are needed to have a 0-bit,
					// which means that the MSB of 'b' will be set to zero
					// this will make the two numbers 'a' and 'b' close to
					// each other as possible
					f = 0;
				} else {
					// after the execution of the if statement above,
					// we will set the remaining bits of 'b' using the 'OR' bitwise operator
					b |= (1 << i);
				}
			} else {
				// otherwise, if the MSB of 2 ^ i is not equal to 'c',
				// then it means that the current bit in 'c' is equal to 0
				// in this case, set both of the current bits of 'a' and 'b'
				// to 1 instead of 0 since both 1's can also produce a 0 in the XOR operation
				// to make sure that the program finds the maximum value of 'a' and 'b'
				a |= (1 << i);
				b |= (1 << i);
			}
		}
		// lastly, print the product of 'a' and 'b'
		cout << a * b << '\n';
	}
	return 0;
}
