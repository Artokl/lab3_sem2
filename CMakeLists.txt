cmake_minimum_required(VERSION 3.28)
project(lab_3)

set(CMAKE_CXX_STANDARD 23)

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
        LinearForm.h
        Tests/LinearFormTests.h
        ClassConclusions.h
)
