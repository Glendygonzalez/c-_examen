#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class Estudiante{
protected: string carnet, nombres, apellidos, direccion, email, fecha_nacimiento;
	int telefono=0;

public:
	Estudiante() {
	}
	Estudiante(string carn ,string nom, string ape, string dire, int tel,string ema, string fn) {
		carnet = carn;
		nombres = nom;
		apellidos = ape;
		direccion = dire;
		telefono = tel;
		email = ema;
		fecha_nacimiento = fn;
	}
	// METODOS
	//set (modificar)
	void setCarnet(string carn) { carnet = carn; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dire) { direccion = dire; }
	void setEmail(string ema) { email = ema;}
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getEmail() {  return email; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO Estudiantes(carnet,nombres,apellidos,direccion,telefono,email,fecha_nacimiento)VALUES('"+carnet+"','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + email + "','" + fecha_nacimiento + "');";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			string consulta = "select * from Estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout <<" ID: "<< fila[0] << " Carnet: " << fila[1] << " Nombre:" << fila[2] << " Apellido: " << fila[3] << " Direccion: " << fila[4] << " Telefono: " << fila[5] << " Email: " << fila[6] << " Fecha de Nacimiento: " << fila[7] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string update = "UPDATE Estudiantes SET nombres='" + nombres + "',apellidos ='" + apellidos + "',direccion='" + direccion + "',telefono=" + t + ", email = '" + email + "',fecha_nacimiento = '"+fecha_nacimiento+"' where  carnet = '" + carnet + "';";
			const char* i = update.c_str();                               
			q_estado = mysql_query(cn.getConectar(), i);                        
			if (!q_estado) {
				cout << "Actualizacion Exitosa..." << endl;

			}
			else {
				cout << "xxxxError en la Actualización xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = "DELETE from Estudiantes where  carnet = '" + carnet + "';";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminado Correctamente..." << endl;

			}
			else {
				cout << "xxxxError al Eliminar xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};

