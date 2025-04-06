# 🔄 Alternando entre Implementações da TAD Matriz

Este projeto oferece **duas formas de implementar uma matriz em C**:

- `"simples"` → utilizando **vetor linear (1D)**
- `"ponteiros"` → utilizando **vetor de ponteiros (2D dinâmico)**

---

## ✅ Como escolher a implementação

Abra o arquivo `CMakeLists.txt` na raiz do projeto.

Encontre esta linha:

```cmake
set(MATRIZ_IMPL "ponteiros")  # ou "simples"

E altere o tipo desejado.

set(MATRIZ_IMPL "simples") 
set(MATRIZ_IMPL "ponteiros")