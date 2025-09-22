#include <iostream>
#include <string>
#include "netaddr.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        cout << "Usage: " << argv[0] << " <IP_address> <subnet_mask>" << endl;
        cout << "Example: " << argv[0] << " 192.168.1.42 255.255.255.0" << endl;
        return 1;
    }
    
    string result = calc_address(argv[1], argv[2]);
    cout << result << endl;
    
    return 0;
}
