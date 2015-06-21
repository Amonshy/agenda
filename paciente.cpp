#include "paciente.hpp"
#include <iostream>
#include "macros.hpp"

Paciente Paciente::rellenarDatosPaciente()
{
  Paciente p1;

  int posicionBarra, posicionBarra2;
  std::string aux, aux2;
  std::string cita;
  
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
  
  //Obtenemos la posición de la segunda barra
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
  std::cin >> cita;
  
  //Obtenemos la posicón de la primera barra
  posicionBarra=cita.find_first_of("/");
  aux2= cita.substr(0,posicionBarra);
  
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.setDiaFechaCita(std::stoi(aux2));
  }
  
  //Obtenemos la posición de la segunda barra
  posicionBarra2=cita.find_first_of("/",posicionBarra+1);
  aux2= cita.substr(posicionBarra+1,posicionBarra2);

  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.setMesFechaCita(std::stoi(aux2));
  }
  
  //Obtenemos el año
  aux2=cita.substr(posicionBarra2+1);
  
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.setYearFechaCita(std::stoi(aux2));
  }
  
  getchar();
  LUGAR(11,10);
  std::cout << "Introduzca el motivo de la cita: ";
  std::getline(std::cin, aux);
  p1._citaPaciente.setMotivo(aux); 
  
  LUGAR(12,10);
  std::cout << "Introduzca la hora de la cita (HH:MM): ";
  std::cin >> aux;
  
  //Obtenemos la posicón de los :
  posicionBarra=aux.find_first_of(":");
  aux2= aux.substr(0,posicionBarra);
   
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.setHoraCita(std::stoi(aux2));
  }
  
  aux2=aux.substr(posicionBarra+1);
  
  if(std::stoi(aux2)) //La función stoi requiere del standard c++11
  {
    p1._citaPaciente.setMinutosCita(std::stoi(aux2));
  }
   
  //-----------------------------------------------------------------------------------------------------------

  
  return (p1);
  
}

