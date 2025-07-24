# Algoritmos de ordenamiento

Este trabajo fue una actividad realizada en la materia "Análisis y Diseño de algoritmos" impartida por el Dr. Iván Olmos Pineda en la Facultad de Ciecias de la Computación de la BUAP durante el prediodo académico de Otoño 2024 

## Contenido
Se presenta un análisis teórico y préctico de los algoritmos de ordenamiento:
- Bubble Sort 
- Insertion Sort
- Quick Sort
- Merge Sort
- Radix Sort

El repositorio cuenta con un documento PDF con una documentación más detallada de dicho análsis
## Deployment

Para poder ejecutar este proyecto copia el repositorio en una carpeta local. A continuación se describe la forma en que funciona Archivos.cpp y Ordenamiento.cpp

- Archivos.cpp

La función principal debe tener una estructura similar a la sigue 

```bash
  vector<int> distribucion ={200,300,500};
  vector<int> porcentaje ={10,50,100};
  genArchivos("1K.txt",distribucion,porcentaje,1000);
```
Donde **distribucion** representa particiones del total de números y **porcentaje** el porcentaje de desorden asociado a cada partición. La funcion *genArchivos* toma como parámetos el nombre final del archivo y dos vectores de enteros (distribución y porcentaje respectivamente) y el tamaño total de dígitos a generar.

Este programa creará un m vectores de tamaño n y desordenara una fracción de ellos (distribución) con un determinado porcentaje 

- Ordenamiento.cpp

la función más importante de este programa es *ejecutar*, recibe una string con el nombre del archivo que contiene los arreglos a ordenar, y otra string con los tiempos de ejecución asociados a cada arreglo.

Dentro de la definición de *ejecutar* se encuentran las líneas que ejecutan cada algoritmo de ordenamiento, asegurate de comentar todas menos la que quieras ejecutar.

##Advertencias.
Toma en cuenta que algoritmos cuadráticos tardarán mucho tiempo en ordenar una gran cantidad de arreglos superiores a 60K elementos.


##Recomendaciones
- Desactivar HiperThreading: aumenta la potencia mononúcleo empleada en este programa
- Asignar un núcleo a un proceso para eficientar la ajecución de las pruebas.
