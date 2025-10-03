#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const int MESES = 12;

// Función para calcular el promedio de un vector
double calcularPromedio(double v[]) {
    double suma = 0;
    for (int i = 0; i < MESES; i++) {
        suma += v[i];
    }
    return suma / MESES;
}

// Función para encontrar el mes más caliente y devolver el índice
int mesMasCaliente(double v[]) {
    int indiceMax = 0;
    for (int i = 1; i < MESES; i++) {
        if (v[i] > v[indiceMax]) {
            indiceMax = i;
        }
    }
    return indiceMax;
}

// Función para calcular la desviación estándar
double desviacionEstandar(double v[]) {
    double prom = calcularPromedio(v);
    double suma = 0;
    for (int i = 0; i < MESES; i++) {
        suma += pow(v[i] - prom, 2);
    }
    return sqrt(suma / MESES);
}

// Función para encontrar el valor máximo en un vector
double maximo(double v[]) {
    double maxVal = v[0];
    for (int i = 1; i < MESES; i++) {
        if (v[i] > maxVal) {
            maxVal = v[i];
        }
    }
    return maxVal;
}

int main() {
    double santander[MESES];
    double guajira[MESES];
    double narino[MESES];

    string nombresMeses[MESES] = { "Enero","Febrero","Marzo","Abril","Mayo","Junio",
                                  "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };

    // Entrada de datos
    cout << "Ingrese las temperaturas promedio de Santander (12 meses):\n";
    for (int i = 0; i < MESES; i++) {
        cout << nombresMeses[i] << ": ";
        cin >> santander[i];
    }

    cout << "\nIngrese las temperaturas promedio de Guajira (12 meses):\n";
    for (int i = 0; i < MESES; i++) {
        cout << nombresMeses[i] << ": ";
        cin >> guajira[i];
    }

    cout << "\nIngrese las temperaturas promedio de Nariño (12 meses):\n";
    for (int i = 0; i < MESES; i++) {
        cout << nombresMeses[i] << ": ";
        cin >> narino[i];
    }

    // ---- Cálculos ----
    double promSantander = calcularPromedio(santander);
    double promGuajira = calcularPromedio(guajira);
    double promNarino = calcularPromedio(narino);

    double promedioNacional = (promSantander + promGuajira + promNarino) / 3;

    int mesSant = mesMasCaliente(santander);
    int mesGuaj = mesMasCaliente(guajira);
    int mesNar = mesMasCaliente(narino);

    double picoSant = maximo(santander);
    double picoGuaj = maximo(guajira);
    double picoNar = maximo(narino);
    double promedioPicos = (picoSant + picoGuaj + picoNar) / 3;

    string deptoMayor;
    double mayorProm = promSantander;
    deptoMayor = "Santander";

    if (promGuajira > mayorProm) {
        mayorProm = promGuajira;
        deptoMayor = "Guajira";
    }
    if (promNarino > mayorProm) {
        mayorProm = promNarino;
        deptoMayor = "Narino";
    }

    double maxGlobal = picoSant;
    string deptoMax = "Santander";
    int mesMax = mesSant;

    if (picoGuaj > maxGlobal) {
        maxGlobal = picoGuaj;
        deptoMax = "Guajira";
        mesMax = mesGuaj;
    }
    if (picoNar > maxGlobal) {
        maxGlobal = picoNar;
        deptoMax = "Narino";
        mesMax = mesNar;
    }

    double desSant = desviacionEstandar(santander);
    double desGuaj = desviacionEstandar(guajira);
    double desNar = desviacionEstandar(narino);

    // ---- Resultados ----
    cout << fixed << setprecision(2);
    cout << "\n=== RESULTADOS ===\n";
    cout << "Promedio anual Santander: " << promSantander << "°C\n";
    cout << "Promedio anual Guajira: " << promGuajira << "°C\n";
    cout << "Promedio anual Narino: " << promNarino << "°C\n";
    cout << "Promedio nacional: " << promedioNacional << "°C\n\n";

    cout << "Mes mas caliente Santander: " << nombresMeses[mesSant] << " (" << santander[mesSant] << "°C)\n";
    cout << "Mes mas caliente Guajira: " << nombresMeses[mesGuaj] << " (" << guajira[mesGuaj] << "°C)\n";
    cout << "Mes mas caliente Narino: " << nombresMeses[mesNar] << " (" << narino[mesNar] << "°C)\n\n";

    cout << "Promedio de los picos: " << promedioPicos << "°C\n";
    cout << "Departamento con mayor promedio: " << deptoMayor << "\n";
    cout << "Temperatura maxima global: " << maxGlobal << "°C en " << deptoMax
        << " (" << nombresMeses[mesMax] << ")\n\n";

    cout << "Desviacion estandar Santander: " << desSant << "\n";
    cout << "Desviacion estandar Guajira: " << desGuaj << "\n";
    cout << "Desviacion estandar Narino: " << desNar << "\n";

    return 0;
}