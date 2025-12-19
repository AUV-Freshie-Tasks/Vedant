#include<iostream>
#include "matrixDec.hpp"
#include<pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>
namespace py=pybind11;
PYBIND11_MODULE(matrix_lib, m) {
	py::class_<matrix<double>>(m,"matrix")
		.def_readwrite("data",&matrix<double>::mat)
		.def(py::init<int,int>())
		.def(py::init<const std::vector<std::vector<double>>&>())
		.def(py::self + py::self)
		.def(py::self - py::self)
             	.def(py::self*py::self);

	py::class_<matrix<float>>(m,"matrixF")
                .def_readwrite("data",&matrix<float>::mat)
                .def(py::init<int,int>())
                .def(py::init<const std::vector<std::vector<float>>&>())
		.def(py::self + py::self)
                .def(py::self - py::self)
                .def(py::self*py::self);

	m.def("modifyMatrix", &modifyMatrix<double>);
	m.def("modifyMatrix", &modifyMatrix<float>);
	m.def("inverse", &inverse<double>);
	m.def("Lmatrix", &LMatrix<double>);
	m.def("Umatrix", &UMatrix<double>);
	m.def("solveMatrix", &solveMatrix<double>);
	m.def("linear_Reg",&lReg<double>);
	m.def("inverse", &inverse<float>);
        m.def("Lmatrix", &LMatrix<float>);
        m.def("Umatrix", &UMatrix<float>);
        m.def("solveMatrix", &solveMatrix<float>);
        m.def("linear_Reg",&lReg<float>);
}

