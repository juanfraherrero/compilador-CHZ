# COMPILADOR-CHZ

## Requerimientos para desarrollar

Hay que bajarse el VsCode o algún IDE

instalarse la extensión para VsCode:
- c/c++ de microsoft
- c/c++ Makefile Project
- Code Runner
- Yash

## Compilación

Instalar make, https://sourceforge.net/projects/mingw/ 

En el archivo Makefile en la línea 13, en la variable src deben poner el path completo hacia la carpeta src. Ejemplo - "C:\Escritorio\compilador-CHZ\src"

Desde la carpeta raiz (donde está el Makefile) le dan al siguiente comando para compilar el código:

```make
make all
```

## Ejecución
Una vez tenemos compilado el código, solo resta ejecutarlo:

```
/compilador-CHZ pathToFileToCompile nombreArchivoSalida
```

El primer parámetro es el binario o ejecutable, el segundo es el archivo de texto de código a compilar y el tercero es el nombre del archivo de salida.

# Consideraciones

Para la genereación del .obj y .exe se requiere de tener instalado el MASM32 y guardado en la variable de entorno path. Debe estar instalada en "C:\\masm32"
