#include <iostream>

using namespace std;

int main() {
    int p;
    cin >> p;

    int total_primitive_roots = 0;

    // Loop through every possible x from 1 to p-1
    for (int x = 1; x < p; x++) {
        int current_power = 1;
        bool is_primitive = true;

        // Check powers from 1 to p-2
        for (int k = 1; k <= p - 2; k++) {
            // Calculate (current_power * x) % p
            current_power = (current_power * x) % p;

            // If we hit 1 before the power (p-1), it's not a primitive root
            if (current_power == 1) {
                is_primitive = false;
                break;
            }
        }

        // According to Fermat's Little Theorem, x^(p-1) % p is always 1
        // So we only need to check if the 'is_primitive' flag is still true
        if (is_primitive) {
            // Check the final power (p-1) just to be sure
            current_power = (current_power * x) % p;
            if (current_power == 1) {
                total_primitive_roots++;
            }
        }
    }

    cout << total_primitive_roots << endl;

    return 0;
}