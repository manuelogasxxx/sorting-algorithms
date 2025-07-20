#include <iostream>
#include <utility>
#include <vector>
#include <random>
#include <cstdlib>
#include <set>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <sstream>
using namespace std;

/*Aqui van los algoritmos de ordenamiento*/

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}
/*El código fue obtenido de
https://www.geeksforgeeks.org/bubble-sort-algorithm/
*/


void insertionSort(vector<int>& arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
/*El código fue obtenido de 
https://www.geeksforgeeks.org/insertion-sort-algorithm/
*/

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/*
El código para la función partition y quicksort fue obtenido de:
https://www.geeksforgeeks.org/quick-sort-algorithm/ 
*/
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
 

/*Este código fue obtenido de
https://www.geeksforgeeks.org/iterative-merge-sort/
*/



int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = { 0 };

    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = output;
}

void radixsort(vector<int>& arr) {
    if (arr.empty()) return;

    int m = getMax(arr);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}
/*Este código fue obtenido de:
https://www.geeksforgeeks.org/radix-sort/
*/


void swap(vector<int>  exm, int pos_a,int pos_b){
    int a = exm.at(pos_a);
    int b = exm.at(pos_b);
    
    exm.at(pos_a)=b;
    exm.at(pos_b)=a;
}


void mostrar(vector<int> exmp){
	for(int i=0;i<exmp.size();i++)
		cout<<exmp[i]<<" ";
	cout<<endl;
}


//funcion que ejecuta los algoritmos
void ejecutar(string archivoEntrada,string archivoSalida){
    ifstream entrada(archivoEntrada);
    if(!entrada){
        cout<<"Error al abrir el archivo de entrada"<<endl;
        return;
    }
    ofstream salida(archivoSalida);
    if(!salida){
        cout<<"Error al abrir el archivo de salida"<<endl;
        return;
    }
    string linea;
    vector<int> leido;
    int elemento;
    //double inicio,fin;
    while(getline(entrada,linea)){
        leido.clear();
        istringstream iss(linea);
        
        //lee una línea y la almacena en el vector
        while (iss>>elemento){
            leido.push_back(elemento);
        }

        //en esta parte se comentan y descomentan los algoritmos segun sea el caso

        auto inicio=chrono::high_resolution_clock::now();
       //quickSort(leido,0,(leido.size()-1));
        bubbleSort(leido);
        //insertionSort(leido,leido.size());
        //mergeSort(leido,leido.size());
        //radixsort(leido);
        auto fin=chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin-inicio;

        //se escribe la duracion en el archivo de salida
        salida << duracion.count() <<endl;
    }
    entrada.close();
    salida.close();
}


int main(void){  

    ejecutar("100.txt","bubble100.txt");
    //ejecutar("50k.txt","bubble50k.txt");
    

    return 0;
}
