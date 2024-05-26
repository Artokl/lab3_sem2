cmake_minimum_required(VERSION 3.28)
project(lab_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_3 main.cpp
        Complex.h
        ListSequence.h
        DynamicArray.h
        ArraySequence.h
        LinkedList.h
        Sequence.h
        Vector.h
        Ui.h
        Tests/StandartTests.h
        Tests/VectorTests.h
        Tests/ComplexTests.h
        Abs.h
        RectangularMatrix.h
        Tests/MatrixTests.h
        LinearShape.h
        Tests/LinearShapeTests.h)
