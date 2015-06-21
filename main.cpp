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
  std::string nombre;
   
  do{
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
    std::cout << "6. Copia de seguridad" << std::endl;
    LUGAR(12,10);
    std::cout << "7. Salir" << std::endl;

    LUGAR(15,10);
    std::cout << "Opción: ";
    std::cin >> opcion;
  
    switch(opcion)
    {  
      case 1:
	
	break;
	
      case 2:
	BORRAR;
	p1=Paciente::rellenarDatosPaciente();
	agendaDentista.guardarEnBaseDeDatos(p1);
	break;
	
      case 3:
	
	break;
      
      case 4:
	BORRAR;
	LUGAR(5,10);
	std::cout << "Introduzca el nombre del paciente a eliminar: ";
	std::cin >> nombre;
	agendaDentista.eliminarDeBaseDeDatos(nombre);
	break;
	
      case 5:
	BORRAR;
	agendaDentista.listarBaseDeDatos();
	break;
	
      case 6:
	
	break;
	
      case 7:
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
    getchar();
    getchar();
    BORRAR;
    
  }while(opcion!=7);
  
  return (0);
}
