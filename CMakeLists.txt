cmake_minimum_required(VERSION 3.14)
project(imobiliaria)

set(CMAKE_CXX_STANDARD 14)

add_executable(imobiliaria main.cpp implementacoes/cliente.cpp implementacoes/cliente.h implementacoes/imovel.cpp implementacoes/imovel.h)