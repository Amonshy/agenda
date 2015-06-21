#include "agenda.hpp"
#include "macros.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void Agenda::guardarEnBaseDeDatos(const Paciente &p1) const
{
  std::ofstream ficheroSalida;
  ficheroSalida.open(_baseDeDatos, ios::app);
  
  if(!ficheroSalida)
  {
    std::cout << "Error al abrir el fichero" << std::endl;
    exit (-1);
  }
  //Nombre;Apellidos;DNI;DiaNacimiento;MesNacimiento;AñoNacimiento;Telefono;DiaCita;MesCita;AñoCita;MotivoCita;HoraCita;MinutosCita
  
  ficheroSalida << p1.getNombre() << ";" << p1.getApellidos() << ";" << p1.getDni() << ";" << p1.getFechaNacimiento().getDia() << ";"
  << p1.getFechaNacimiento().getMes() << ";" << p1.getFechaNacimiento().getYear() << ";" << p1.getTelefono() << ";" << p1.getCita().getDiaFechaCita() 
  << ";" << p1.getCita().getMesFechaCita() << ";" << p1.getCita().getYearFechaCita() << ";" << p1.getCita().getMotivo() << ";" 
  << p1.getCita().getHoraCita() << ";" << p1.getCita().getMinutosCita() << ";" << "\n";
  
  LUGAR(14,10);
  std::cout << "Paciente añadido correctamente en el fichero correctamente en el fichero." << std::endl;
  
  ficheroSalida.close();

}

void Agenda::listarBaseDeDatos() const
{
  std::ifstream ficheroEntrada;
  ficheroEntrada.open(_baseDeDatos);
  std::string horaC, minutosC, dni, aux;
  std::string diaN, mesN, yearN, diaC, mesC, yearC;
  std::string nombre, apellidos, telefono, motivo;
  int i=6, j=0;
  
  LUGAR(5,5);
  std::cout << "Posición" << "\tNombre" << "\t\t   DNI" << "\t\tApellidos" << "\t\tFecha de Nacimiento" << "\tTelefono" << "\tFecha Cita" << "\tMotivo Cita" << "\t\tHora de la Cita";

  while(getline(ficheroEntrada, nombre, ';') and getline(ficheroEntrada, apellidos, ';') and getline(ficheroEntrada, dni, ';') and getline(ficheroEntrada, diaN, ';')
  and getline(ficheroEntrada, mesN, ';') and getline(ficheroEntrada, yearN, ';') and getline(ficheroEntrada, telefono, ';') and  getline(ficheroEntrada, diaC, ';')
  and getline(ficheroEntrada, mesC, ';') and getline(ficheroEntrada, yearC, ';') and getline(ficheroEntrada, motivo, ';') and getline(ficheroEntrada, horaC, ';')
  and getline(ficheroEntrada, minutosC, ';') and getline(ficheroEntrada, aux, '\n'))
  {
    LUGAR(i,5);
    std::cout << j;
    LUGAR(i,17);
    std::cout <<  nombre;
    LUGAR(i,36);
    std::cout << dni;
    LUGAR(i,49);
    std::cout << apellidos;
    LUGAR(i,73);
    std::cout << diaN << "/" << mesN << "/" << yearN;
    LUGAR(i,83);
    std::cout << "\t\t" << telefono;
    LUGAR(i,105);
    std::cout << "\t" << diaC << "/" << mesC << "/" << yearC;
    LUGAR(i,126);
    std::cout << "\t" << motivo << "\t";
    
    if(std::stoi(minutosC)<10)
    {
      LUGAR(i,153);
      std::cout << horaC << ":0" << minutosC;
    }
    else
    {
      LUGAR(i,153);
      std::cout << horaC << ":" << minutosC;
    }
    i+=1;
    j++; //Para la posición
    
  }

  
}
