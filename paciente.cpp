#include "paciente.hpp"
#include <iostream>
#include "macros.hpp"

Paciente Paciente::rellenarDatosPaciente()
{
  Paciente p1;

  int posicionBarra, posicionBarra2;
  std::string aux, aux2;
  
  getchar();
  //-----------------------------------------------------------------------------------------------------------
  //NOMBRE DEL PACIENTE
  LUGAR(5,10);
  std::cout << "Introduzca el "; SUBRAYADO; std::cout << "nombre"; APAGA; std::cout << " del paciente: ";
  std::getline(std::cin, p1._nombre);
  //-----------------------------------------------------------------------------------------------------------

  
  //-----------------------------------------------------------------------------------------------------------
  //APELLIDOS DEL PACIENTE
  LUGAR(6,10);
  std::cout << "Introduzca los apellidos del paciente: ";
  std::getline(std::cin, p1._apellidos);
  //-----------------------------------------------------------------------------------------------------------

  
  //-----------------------------------------------------------------------------------------------------------
  //DNI DEL PACIENTE
  LUGAR(7,10);
  std::cout << "Introduzca el DNI del paciente: ";
  std::cin >> p1._DNI;
  //-----------------------------------------------------------------------------------------------------------

  
  //-----------------------------------------------------------------------------------------------------------
  //FECHA DE NACIMIENTO DEL PACIENTE
  LUGAR(8,10);
  std::cout << "Introduzca la fecha de nacimiento (DD/MM/YYYY): ";
  std::cin >> aux;
  
  //Obtenemos la posicón de la primera barra
  posicionBarra=aux.find_first_of("/");
  aux2= aux.substr(0,posicionBarra);
  
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._fechaNacimiento.setDia(std::stoi(aux2));
  }
  
  //Obtenemos la posicón de la segunda barra
  posicionBarra2=aux.find_first_of("/",posicionBarra+1);
  aux2= aux.substr(posicionBarra+1,posicionBarra2);

  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._fechaNacimiento.setMes(std::stoi(aux2));
  }
  
  //Obtenemos el año
  aux2=aux.substr(posicionBarra2+1);
  
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._fechaNacimiento.setYear(std::stoi(aux2));
  }
  //-----------------------------------------------------------------------------------------------------------

  
  //-----------------------------------------------------------------------------------------------------------
  //TELEFONO DEL PACIENTE
  LUGAR(9,10);
  std::cout << "Introduzca el "; SUBRAYADO; std::cout << "telefono"; APAGA; std::cout << " del paciente: ";
  std::cin >> p1._telefono;
  //-----------------------------------------------------------------------------------------------------------

  //-----------------------------------------------------------------------------------------------------------
  //CITA DEL PACIENTE
  LUGAR(10,10);
  std::cout << "Introduzca la cita del paciente (DD/MM/YYYY): ";
  std::cin >> aux;
  
  //Obtenemos la posicón de la primera barra
  posicionBarra=aux.find_first_of("/");
  aux2= aux.substr(0,posicionBarra);
  
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.getFechaCita().setDia(std::stoi(aux2));
  }
  
  //Obtenemos la posicón de la segunda barra
  posicionBarra2=aux.find_first_of("/",posicionBarra+1);
  aux2= aux.substr(posicionBarra+1,posicionBarra2);

  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.getFechaCita().setMes(std::stoi(aux2));
  }
  
  //Obtenemos el año
  aux2=aux.substr(posicionBarra2+1);
  
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.getFechaCita().setYear(std::stoi(aux2));
  }
  
  //-----------------------------------------------------------------------------------------------------------

  
  return (p1);
  
}

