CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
PROJECT(Avaliacao)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(include/)

ADD_EXECUTABLE(
    programa
    src/main.cpp
    src/Candidato.cpp
    src/funcoes.cpp
)
