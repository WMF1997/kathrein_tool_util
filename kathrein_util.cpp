// kathrein_util.cpp 
// kathrein scala division. 

// compile: 
// g++ -fPIC -shared -O2 kathrein_util.cpp -o libkathrein_util.so 
// g++ -O2 -L . main_test.cpp -lkathrein_util 

#include "kathrein_util.h"

// speed of light (m/s) in vaccum(or in air, in approximation)
const double c = 299796200;

// dbm to watts 
// converts dbm to watts 
// enter the known value(dbm or watts) and press enter, 
// then read then equivalent value. 
// (calculation only good for dbm values betwenn 109.9999 and -150)

double watts_2_dbm(double watts) {
    return 10 * log10(watts / 0.001);
}

double dbm_2_watts(double dbm) {
    return pow(10, dbm / 10) * 0.001;
}

// cascade VSWR 
// enter your first VSWR value 'VSWR 1', e.g. 2:1
// then enter your second VSWR value 'VSWR 2', e.g. 3:1
// then click the '=' button and the maximum possible VSWR will appear in 'Max VSWR'  
double max_cascade_vswr(double vswr_1, double vswr_2) {
    return vswr_1 * vswr_2;
}

// wavelength calculator
// calculates the wavelength for a desired frequency 
// wavelength: millimeters, centimeters, meters, inches, feet, yards 
// frequency: Hz, KHz, MHz, GHz
// only Hz <-> meters is supported now, perhaps we can use std::ratio to convert other types. 
double freq_2_wavelength(double freq) {
    return c / freq;
}

double wavelength_2_freq(double wavelength) {
    return c / wavelength;
}

double deg_2_rad(double deg) {
    return deg / 180 * M_PI;
}

double rad_2_deg(double rad) {
    return rad / M_PI * 180;
}

// touchdown points 
// calculates the touchdown point distance for an antenna main beam and the upper and lower 3dB points. 

// height above average terrain. feet, meters, only meters is supported now. 
// vertical beam width in degrees. (only in degrees, not in radius)
// downtilt in degrees. (only in degrees, not in radius)
// the calculation returns: 
// feet, yards, miles, meters, kilometers 

std::vector<double> touchdown_point_info(double height, double beam_width_deg, double downtilt_deg) {
    // return value type in the vector: 
    // non-negative float value: correct 
    // inf: over horizon (TODO)
    // nan: behind tower (TODO)
    std::vector<double> result;
    
    double beam_width_rad = deg_2_rad(beam_width_deg);
    double downtilt_rad = deg_2_rad(downtilt_deg);

    // upper 3db 
    result.push_back(height / tan(downtilt_rad - beam_width_rad/2));
    // main beam
    result.push_back(height / tan(downtilt_rad));
    // lower 3db
    result.push_back(height / tan(downtilt_rad + beam_width_rad/2));

    return result;
}

// reflection conversion table 
// VSWR, Return Loss(dB), Reflected Power, Reflection Coeffiecient 
// Adjust slider for the known value on the appropriate scale reading from then box at the right, then read the equivalent values. 
std::vector<double> reflection_conversion(double vswr) {
    // use vswr as input, calculates return loss(db), reflected power, reflected coeffiecient. 
    // these 3 parts are output, stored in a std::vector<double> 
    // reference: https://blog.csdn.net/pt9321/article/details/126730197 

    // vswr = \frac{1 + 10^{\frac{-RL}{20}}}{1 - 10^{\frac{-RL}{20}}} 
    // where RL is the return loss(db)
    // thus, RL = 20 * \log_10{\frac{vswr+1}{vswr-1}}

    // reflection coeff: 
    // we can imagine the wave reflect back in one-dimension, and reflection wave adds with the input wave. 
    // then, with the two waves' amptitude, we can get (vswr - 1) / (vswr + 1)
    std::vector<double> result;

    double return_loss = 20 * log10((vswr + 1) / (vswr - 1));
    double reflection_coeff = (vswr - 1) / (vswr + 1); // or, = power(10, -return_loss / 10);
    double reflected_power = reflection_coeff * reflection_coeff; // or, = power(10, -return_loss / 20);

    result.push_back(return_loss);
    result.push_back(reflected_power);
    result.push_back(reflection_coeff);

    return result;
}


