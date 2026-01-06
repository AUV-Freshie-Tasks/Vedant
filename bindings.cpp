#include<iostream>
#include "matrixDec.hpp"
#include "linearReg.h"
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
		.def(py::self * double())
		//.def(double()*py::self)
             	.def(py::self*py::self);

	py::class_<matrix<float>>(m,"matrixF")
                .def_readwrite("data",&matrix<float>::mat)
                .def(py::init<int,int>())
                .def(py::init<const std::vector<std::vector<float>>&>())
		.def(py::self + py::self)
                .def(py::self - py::self)
		.def(py::self * float())
		//.def(float()*py::self)
                .def(py::self*py::self);
	
	py::class_<linearRegressor<double>>(m,"linear_regressor")
		.def(py::init<double,int>())
		.def("fit",&linearRegressor<double>::fit)
		.def("predict",&linearRegressor<double>::predict)
		.def("getParameters",&linearRegressor<double>::getParameters);

	py::class_<linearRegressor<float>>(m,"linear_regressorF")
		.def(py::init<float,int>())
                .def("fit",&linearRegressor<float>::fit)
                .def("predict",&linearRegressor<float>::predict)
                .def("getParameters",&linearRegressor<float>::getParameters);

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

