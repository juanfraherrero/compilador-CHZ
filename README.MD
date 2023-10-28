# COMPILADOR-CHZ

## Requerimientos para desarrollar

Hay que bajarse el vscode

instalarse la extensión:
- c/c++ de microsoft
- c/c++ Makefile Project
- Code Runner

### Compilación

Instalar make en la máquina, https://sourceforge.net/projects/mingw/ 

En el archivo Makefile en la línea 13, en la variable src deben poner el path completo hacia la carpeta src. Ejemplo - "C:\Escritorio\compilador-CHZ\src"

Desde la carpeta raiz (donde está el Makefile) le dan al siguiente comando para compilar el código:

```make
make all
```

## Ejecución
Una vez tenemos compilado el código, solo resta ejecutarlo:

```
/compilador-CHZ filesToCompile/text.txt 
```

El primer parámetro es el binario (tiene el nombre definido en el Makefile), y el segundo el archivo de texto de código a compilar.

# Consideraciones
Dentro de la carpeta ejecutables se encuentras los ejecutables de windows de 32 y 64 bits para usos directos sin necesidad de instalar nada.
