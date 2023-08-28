# COMPILADOR-CHZ

# Instalación

Hay que bajarse el vscode

instalarse la extensión:
- c/c++ de microsoft
- c/c++ Makefile Project
- Code Runner

Luego checkear tener instalado make en la máquina, deberían sino no busquen como

Cuando lo tengan todo instalado, si no tocaron nada en el código.  

En el archivo Makefile en la línea 13, en la variable src deben poner la carpeta raíz de donde esté su proyecto

desde la carpeta raiz le dan:

```make
make all
```

y con eso compilan todo. ya tienen el binario y ahr lo ejecutan

```
/compilador-CHZ filesToCompile/text.txt 
```
el primer parámetro es el binario, y el segundo el archivo de texto ode código a leer.