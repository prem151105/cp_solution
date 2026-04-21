#include <iostream>
 
int main()
{
    int t = 1;
    std::cin >> t;
 
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        bool ans = ((n * k) % 2 == 0); // Either n*k is even
 
        int tot = 0; 
        while (n--) {
            int x;
            std::cin >> x; 
            tot += x;
        } 
        ans |= tot & 1; // Or sum(a) is odd
        
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
 
    return 0;
}