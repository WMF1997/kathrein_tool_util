#include <pybind11/pybind11.h> // pybind11 binding
#include <pybind11/stl.h> // if return arg's type is related to stl containers, e.g., std::vector, include this header.  
#include "kathrein_util.h" 

namespace py = pybind11;
PYBIND11_MODULE(kathrein_util_pybind11, m) { 
	// the name of PYBIND11_MODULE, should be the same as the compile result in .so file! (kathrein_util_pybind11 -> kathrein_util_pybind11.so)
	m.def("watts_2_dbm", &watts_2_dbm, "watts to dbm function", py::arg("watts"));
	m.def("dbm_2_watts", &dbm_2_watts, "dbm to watts function", py::arg("dbm"));
	m.def("max_cascade_vswr", &max_cascade_vswr, "max cascade vswr", py::arg("vswr_1"), py::arg("vswr_2"));
	m.def("freq_2_wavelength", &freq_2_wavelength, "frequency to wavelength", py::arg("freq"));
	m.def("wavelength_2_freq", &wavelength_2_freq, "wavelength to frequency", py::arg("wavelength"));
	m.def("deg_2_rad", &deg_2_rad, "degree to radian", py::arg("deg"));
	m.def("rad_2_deg", &rad_2_deg, "radian to degree", py::arg("rad"));
	// 
	m.def("touchdown_point_info", &touchdown_point_info, "touchdown point info", py::arg("height"), py::arg("beam_with_deg"), py::arg("downtilt_deg"));
	m.def("reflection_conversion", &reflection_conversion, "reflection conversion", py::arg("vswr"));

	m.doc() = "kathrein util pybind11 binding";
}

// compile command (simply for testing)
// g++ -shared -O2 -fPIC -ffast-math -march=native -I /home/wmf1997/python313/lib/python3.13/site-packages/pybind11/include -I /home/wmf1997/.local/share/uv/python/cpython-3.13.2-linux-x86_64-gnu/include/python3.13 -I ../include kathrein_util.cpp kathrein_util_pybind11.cpp -o kathrein_util_pybind11.so