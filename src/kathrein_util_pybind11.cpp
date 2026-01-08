#include <pybind11/pybind11.h>
#include "kathrein_util.h"

namespace py = pybind11;

PYBIND11_MODULE(kathrein_util, m) {
	m.doc() = "kathrein util pybind11 binding";
}

