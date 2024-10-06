#include <iostream>
#include <cmath>  // Para la función abs()

using namespace std;

int main() {
    int cantidad;

    cout <<"\nPROGRAMA QUE DETERMINA EL DIGITO MAYOR DE CADA NUMERO INGRESADO\n";
    cout <<"____________________________________________________________________\n";

    // Validar la entrada de la cantidad
    do {
        cout << "\nIngrese la cantidad de numeros: ";
        cin >> cantidad;
    } while (cantidad < 1);

    // Procesa cada número
    for (int i = 1; i <= cantidad; i++) {
        int numero;
        cout << "\n\n" << i << "° NUMERO: ";
        cin >> numero;

        numero = abs(numero);  // Asegura que el número sea positivo

        int valorMayor = -1;
        int posicion = 0;
        int digitos = 0;
        int posActual = 1;
        int primerDigito = numero % 10;
        bool todosIguales = true;

        // Itera sobre cada dígito del número
        while (numero != 0) {
            int digito = numero % 10;

            if (digito > valorMayor) {
                valorMayor = digito;
                posicion = posActual;
            }

            if (digito != primerDigito) 
                todosIguales = false;
                
            numero /= 10;
            posActual++;
            digitos++;
        }

        // Salida de resultados
        if (todosIguales)
            cout << "\nNo existe numero mayor.....";
        else 
            cout << "\nEl digito mayor es " << valorMayor << " y ocupa la posicion " << (digitos - posicion + 1);
    }
    
    return 0;
}
