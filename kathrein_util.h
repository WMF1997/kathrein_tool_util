#ifndef KATHREIN_UTIL_H
#define KATHREIN_UTIL_H

#include <iostream>
#include <cmath>
#include <vector>

double watts_2_dbm(double watts);
double dbm_2_watts(double dbm);

double max_cascade_vswr(double vswr_1, double vswr_2);

double freq_2_wavelength(double freq);
double wavelength_2_freq(double wavelength);

double deg_2_rad(double deg);
double rad_2_deg(double rad);

std::vector<double> touchdown_point_info(double height, double beam_width_deg, double downtilt_deg);
std::vector<double> reflection_conversion(double vswr);


#endif 
