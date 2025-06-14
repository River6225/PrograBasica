#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Grupo # 3
/* Integrantes:
Luis Enrique Herrera Figueroa - 20231031357
Soad Nallybeth Velásquez López - 20241001880
María Isabel Oviedo Zelaya - 20241000887
Daniel Edgardo Pavón Castro - 20241001960
Kristhian Josué Rivera Castro - 20231001015
*/


int main() {
    int tipoEmpleado, respuestaMenu, edadEmpleado, horasTrabajadas, i = 1;
    string nombreEmpleado;
    double sueldoMensual, sueldoHora, sueldoMinuto, sueldoSegundo;
    double sueldoDiario, sueldoSemanal, sueldoQuincenal;
    char generoEmpleado; 
     
    cout << "  ******************************************************\n";
    cout << "                    BIENVENIDO                          \n";
    cout << "   ******************************************************"; 
    
    do {
        bool nombreCorrecto = false, edadCorrecta = false, generoCorrecto = false, sueldoCorrecto = false;
        int  horasTotales = 0;
        do
        {
            cout << "\nEMPLEADO #" << i << endl;
            cout << "Nombre del empleado: ";
            cin.ignore();
            getline(cin, nombreEmpleado);
    
            if (nombreEmpleado.empty()) { /*Valida que el usuario no haya dejado nombreEmpleado sin nada*/
                cout << " Nombre vacio intente nuevamente\n";
                
            }else{
                nombreCorrecto = true;
            }
            
        } while (nombreCorrecto == false);
        

        do{
            cout << "Edad del empleado: ";
            cin >> edadEmpleado;
            if (edadEmpleado < 18 || edadEmpleado > 100) {
                cout << "Edad incorrecta\n";
                cout << "Solo edad [18, 100] \n ";
            }else{
                edadCorrecta = true;
            }

        }while(edadCorrecta == false);
       do
       {
           cout << "Genero del empleado (M/m o F/f): ";
           cin >> generoEmpleado;
           if (!(generoEmpleado == 'M' || generoEmpleado == 'm' || generoEmpleado == 'F' || generoEmpleado == 'f')) {
               cout << "Genero incorrecto\n";
            }else{
                generoCorrecto = true;
            }
        
        } while (generoCorrecto == false);
       
         do
         {
            cout << "Sueldo mensual (No menor a L.18,000.00): ";
            cin >> sueldoMensual;
            if (sueldoMensual < 18000) {
               cout << "Sueldo incorrecto\n";
                
            }else{
                sueldoCorrecto = true;
            }

         } while (sueldoCorrecto ==false);
         

        cout << "Tipo de Empleado (1. Planta | 2. Medio tiempo | 3. Contrato): ";
        cin >> tipoEmpleado;

        switch (tipoEmpleado) {
            case 1: {
                cout << "\nEMPLEADO DE PLANTA\n";
                double horasMensuales = 214;
                double horasDiariasLaV = 9.5;
                double horasSabado = 6;
                double sueldoSabado;
                sueldoHora = sueldoMensual / horasMensuales;
                sueldoMinuto = sueldoHora / 60;
                sueldoSegundo = sueldoMinuto / 60;
                sueldoDiario = sueldoHora * horasDiariasLaV ;
                sueldoSemanal = sueldoDiario * 5;
                sueldoSabado = sueldoHora * horasSabado;
                sueldoSemanal = sueldoSemanal + sueldoSabado;

                sueldoQuincenal = sueldoMensual / 2;
                break;
            }
            case 2: {
                cout << "\nEMPLEADO DE MEDIO TIEMPO\n";
                double horasMensuales = 138;
                double horasDiarias = 5.75;
                sueldoHora = sueldoMensual / horasMensuales;
                sueldoMinuto = sueldoHora / 60;
                sueldoSegundo = sueldoMinuto / 60;
                sueldoDiario = sueldoHora * horasDiarias;
                sueldoSemanal = sueldoDiario * 6;
                sueldoQuincenal = sueldoMensual / 2;
                break;
            }
            case 3: {
                cout << "\nEMPLEADO POR CONTRATO\n";
               do
               {
                   for (int i = 1; i <= 4; i++){
                       cout << " Cuantas horas trabajo la semana " << i << "?\n" ;
                       cin >> horasTrabajadas;
                       horasTotales = horasTotales + horasTrabajadas;

                    }
                    if (horasTotales < 25 || horasTotales >30) {
                        cout << "las horas Totales del Mes deben ser [18 , 30] \n";
                        
                    }
                    
                   
                } while (horasTotales < 25 || horasTotales > 30);
               
                sueldoHora = sueldoMensual / horasTotales;
                sueldoMinuto = sueldoHora / 60;
                sueldoSegundo = sueldoMinuto / 60;
                sueldoSemanal = sueldoMensual / 4;
                sueldoDiario = sueldoSemanal / 6;
                sueldoQuincenal = sueldoMensual / 2;
                break;
            }
            default:
                cout << "Opcion de empleado incorrecto\n";
                continue;
        }
        
        // Mostrar resultados con dos decimales
        cout << fixed << setprecision(2);
        cout << "\nSueldo mensual es: L. " << sueldoMensual << endl;
        cout << "Sueldo quincenal es: L. " << sueldoQuincenal << endl;
        cout << "Sueldo semanal es: L. " << sueldoSemanal << endl;
        cout << "Sueldo diario es: L. " << sueldoDiario << endl;
        cout << "Sueldo por hora es: L. " << sueldoHora << endl;
        cout << "Sueldo por minuto es: L. " << sueldoMinuto << endl;
        cout << "Sueldo por segundo es: L. " << sueldoSegundo << endl;

        cout << "Desea calcular el sueldo de otro empleado (1 = Si | 2 = No): ";
        cin >> respuestaMenu;
        i++;

    } while (respuestaMenu == 1);

    cout << "\nGracias por utilizar el programa\n";

    return 0;
}