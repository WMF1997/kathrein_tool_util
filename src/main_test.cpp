#include "kathrein_util.h"

// test cases in main function 
int main(int argc, const char** argv, const char** env) {
    // dbm to watts 
    int dbm = 30;
    int watts = 2;
    std::cout << dbm_2_watts(dbm) << std::endl;
    std::cout << watts_2_dbm(watts) << std::endl;
	
	// touchdown pointes
    std::vector<double> r1 = touchdown_point_info(20, 60, 60);
    std::cout << r1[0] << " " << r1[1] << " " << r1[2] << std::endl;

	// reflection conversion
    std::vector<double> r2 = reflection_conversion(3);
    std::cout << r2[0] << " " << r2[1] << " " << r2[2] << std::endl;

    return 0;
}

