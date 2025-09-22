#include <iostream>
#include <string>
#include <arpa/inet.h>
#include "../netcalc.h"

using namespace std;

string calc_address(const string& ip, const string& mask) 
{
    in_addr ip_addr;
    in_addr mask_addr;
    in_addr network_addr;
    
    // Převod IP adresy a masky z textového formátu
    inet_aton(ip.c_str(), &ip_addr);
    inet_aton(mask.c_str(), &mask_addr);
    
    // Výpočet síťové adresy (IP AND maska)
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;
    
    string result = "[dynlib] Network: " + string(inet_ntoa(network_addr));
    
    return result;
}
