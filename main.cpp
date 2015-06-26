/*!
  \file   main.cpp
  \brief  Programa principal de la agenda del dentista
  \author Fernando Aguilera Madueño
  \date   23/05/2015
*/
#include <iostream>
#include <stdio.h>
#include "macros.hpp"
#include "agenda.hpp"

/*! 
  \fn     int main()
  \brief  Programa principal
  \return Valor de control 0
*/
int main(int argc, char **argv) 
{
  int opcion;
  Paciente p1;
  Agenda agendaDentista;
  std::string nombre, dni;
  int borrar, modificar=0;
   
  do{
    do{
      modificar=0;
      BORRAR;
      LUGAR(5,10);
      std::cout << "Bienvenido al menú de selección: " << std::endl;
      LUGAR(6,10);
      std::cout << "1. Buscar paciente" << std::endl;
      LUGAR(7,10);
      std::cout << "2. Añadir paciente" << std::endl;
      LUGAR(8,10);
      std::cout << "3. Modificar paciente" << std::endl;
      LUGAR(9,10);
      std::cout << "4. Eliminar paciente" << std::endl;
      LUGAR(10,10);
      std::cout << "5. Listar agenda" << std::endl;
      LUGAR(11,10);
      std::cout << "6. Salir" << std::endl;

      LUGAR(15,10);
      std::cout << "Opción: ";
      std::cin >> opcion;
    }while(opcion<0 or opcion>6);
  
    switch(opcion)
    {  
      case 1:
	//Buscar paciente
	BORRAR;
	LUGAR(5,10);
	getchar();
	std::cout << "Introduzca el nombre del paciente a buscar: ";
	std::getline(std::cin, nombre);
	LUGAR(10,10);
	std::cout << "Para la correcta visualización, abra su terminal en modo pantalla completa";
	APAGA;
	LUGAR(23,25);
	std::cout << "pulse ";
	SUBRAYADO;
	std::cout << "ENTER";
	APAGA;
	std::cout << " para ";
	INVERSO;
	std::cout << "continuar"; 
	APAGA;
	getchar();
	BORRAR;
	agendaDentista.buscarPacienteEnBaseDeDatos(nombre);
	break;
	
      case 2:
	//Añadir paciente
	BORRAR;
	p1.rellenarDatosPaciente();
	agendaDentista.guardarEnBaseDeDatos(p1);
	break;
	
      case 3:
	//Modificar paciente
	BORRAR;
	do{
	LUGAR(5,10);
	std::cout << "Introduzca el dni del paciente a modificar: ";
	std::cin >> dni;
	}while(dni.empty());
	
	modificar=agendaDentista.modificarPacienteEnBaseDeDatos(dni);
	if(modificar==0)
	{
	  LUGAR(7,10);
	  std::cout << "No se ha encontrado ninguna coincidencia con el dni: " << dni;
	}
	else
	{
	  if(modificar==10)
	  {
	    LUGAR(7,10);
	    std::cout << "Ha decidido abortar la operación de modificación";
	  }
	  else
	  {
	    if(modificar==9)
	    {
	      LUGAR(10,10);
	      std::cout << "La modificación nueva cita ha sido insertada correctamente";
	    }
	    else
	    {
	      LUGAR(10,10);
	      std::cout << "La modificación ha sido un exito";
	    }
	  }
	}
	dni.clear(); //Limpiamos el contenido de dni
	break;
      
      case 4:
	//Eliminar paciente
	BORRAR;
	do{
	LUGAR(5,10);
	std::cout << "Introduzca el DNI del paciente a eliminar: ";
	std::cin >> dni;
	}while(dni.empty());
	borrar=agendaDentista.eliminarDeBaseDeDatos(dni);
	dni.clear(); //Limpiamos el contenido de dni
	if(borrar>0)
	{
	  LUGAR(10,10);
	  std::cout << "Se han eliminado " << borrar << " coincidencias";
	  
	}
	else
	{
	  LUGAR(10,10);
	  std::cout << "No se ha encontrado ninguna coincidencia";
	  getchar();
	}
	break;
	
      case 5:
	//Listar pacientes
	BORRAR;
	LUGAR(10,10);
	std::cout << "Para la correcta visualización, abra su terminal en modo pantalla completa";
	APAGA;
	LUGAR(23,25);
	std::cout << "pulse ";
	SUBRAYADO;
	std::cout << "ENTER";
	APAGA;
	std::cout << " para ";
	INVERSO;
	std::cout << "continuar"; 
	APAGA;
	getchar();
	getchar();
	BORRAR;
	agendaDentista.listarBaseDeDatos();
	break;
	
      case 6:
	//Salir del programa
	BORRAR;
	LUGAR(5,10);
	std::cout << "Gracias por usar el programa" << std::endl;
	break;
	
      default:
	BORRAR;
	LUGAR(5,10);
	std::cout << "Opción desconocida" << std::endl;

	break; 
    }

    LUGAR(23,25);
    std::cout << "pulse ";
    SUBRAYADO;
    std::cout << "ENTER";
    APAGA;
    std::cout << " para ";
    INVERSO;
    std::cout << "continuar"; 
    APAGA;
    if(opcion==1 or opcion==5 or modificar==1 or modificar==2 or modificar==10)
    {
      getchar();
    }
    else
    {
      getchar();
      getchar();
    }    
    BORRAR;
    
  }while(opcion!=6);
  
  return (0);
}
