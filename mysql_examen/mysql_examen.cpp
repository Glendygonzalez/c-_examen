// mysql_examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Estudiante.h"
#include <iostream>
using namespace  std;

int main()
{

	string carnet, nombres, apellidos, direccion, email, fecha_nacimiento;
	int telefono=0, menu=0,smenu=0;
	Estudiante e = Estudiante();
	do {
		cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
		cout<<"1 - Crear Estudiantes, 2 - Lista de los Estudiantes, 3 - Actualizar Datos, 4 - Eliminar Estudiante " << endl;
		cin >> smenu;
		switch (smenu) {
		case 1:
			cout << "-------- CREAR ESTUDIANTE -----------" << endl;
			cout << "Ingrese Carnet:";
			getline(cin, carnet);
			getline(cin, carnet);
			cout <<"" << endl;
			cout << "Ingrese Nombres:";
			getline(cin, nombres);
			cout << "Ingrese Apellidos:";
			getline(cin, apellidos);
			cout << "Ingrese Direccion:";
			getline(cin, direccion);
			cout << "Ingrese Telefono:";
			cin >> telefono;
			cin.ignore();
			cout << "Ingrese Email:";
			getline(cin, email);
			cout << "Fecha Nacimiento:";
			cin >> fecha_nacimiento;
			cout << "ID:"; e.setCarnet(carnet);
			e.setNombres(nombres);
			e.setApellidos(apellidos);
			e.setDireccion(direccion);
			e.setTelefono(telefono);
			e.setEmail(email);
			e.setFecha_Nacimiento(fecha_nacimiento);
			e.crear();
			break;
		case 2:
			cout << "-------- LISTA DE LOS ESTUDIANTES --------" << endl;
			e.leer();
			break;
		case 3:
			cout << "------- Actualizar Datos --------" << endl;
			e.leer();
			cout << "-----------------------------------------------------" << endl;
			cout << "Ingrese Carnet del estudiante que desea actualizar:";
			getline(cin, carnet);
			getline(cin, carnet);
			cout << "" << endl;
			cout << "Ingrese Nombres:";
			getline(cin, nombres);
			cout << "Ingrese Apellidos:";
			getline(cin, apellidos);
			cout << "Ingrese Direccion:";
			getline(cin, direccion);
			cout << "Ingrese Telefono:";
			cin >> telefono;
			cin.ignore();
			cout << "Ingrese Email:";
			getline(cin, email);
			cout << "Fecha Nacimiento:";
			cin >> fecha_nacimiento;
			e.setCarnet(carnet);
			e.setNombres(nombres);
			e.setApellidos(apellidos);
			e.setDireccion(direccion);
			e.setTelefono(telefono);
			e.setEmail(email);
			e.setFecha_Nacimiento(fecha_nacimiento);
			e.Actualizar();
			break;
		case 4:
			cout << "-------ELIMINAR ESTUDIANTE --------" << endl;
			e.leer();
			cout << "--------------------------------------------------" << endl;
			cout << "Ingrese el carnet del Estudiante que desea Eliminar:";
			getline(cin, carnet);
			getline(cin, carnet);
			e.setCarnet(carnet);
			e.eliminar();
			break;
		default:
			cout << "Opcion no encontrada" << endl;
		}
		cout << "Desea regresar al menu principal ingrese numero 1 - SI , 2- NO" << endl;
		cin >> menu;
	
	} while (menu == 1);
	system("pause");
	return 0;

}

