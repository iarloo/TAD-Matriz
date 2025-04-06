cmake_minimum_required(VERSION 3.30)
project(TAD_Matriz C)

set(CMAKE_C_STANDARD 11)

# Opção: escolha "simples" ou "ponteiros"
set(MATRIZ_IMPL "ponteiros")  # ou "simples"

# Adiciona os arquivos necessários
set(SOURCE_FILES main.c Matriz.h)

if(MATRIZ_IMPL STREQUAL "simples")
    list(APPEND SOURCE_FILES MatrizVetorSimples.c)
elseif(MATRIZ_IMPL STREQUAL "ponteiros")
    list(APPEND SOURCE_FILES MatrizVetorDePonteiros.c)
else()
    message(FATAL_ERROR "Implementação desconhecida: ${MATRIZ_IMPL}")
endif()

add_executable(TAD_Matriz ${SOURCE_FILES})