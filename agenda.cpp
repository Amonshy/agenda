#include "agenda.hpp"
#include "macros.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void Agenda::guardarEnBaseDeDatos(const Paciente &p1) const
{
  std::ofstream ficheroSalida;
  ficheroSalida.open(getBaseDeDatos(), ios::app);
  
  if(!ficheroSalida)
  {
    LUGAR(14,10);
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
  ficheroEntrada.open(getBaseDeDatos());
  
  if(!ficheroEntrada)
  {
    LUGAR(5,10);
    std::cout << "Error al abrir el fichero" << std::endl;
    exit (-1);
  }
  
  std::string horaC, minutosC, dni, aux;
  std::string diaN, mesN, yearN, diaC, mesC, yearC;
  std::string nombre, apellidos, telefono, motivo;
  int i=6, j=0;
  
  LUGAR(5,5);
  std::cout << "Posición" << "\tNombre" << "\t\t   DNI" << "\t\tApellidos" << "\t\tFecha de Nacimiento" << "\tTelefono" << "\tFecha Cita" << "\tHora Cita" << "\tMotivo Cita";

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
    LUGAR(i,140);
    std::cout << "\t" << motivo << "\t";
    
    if(std::stoi(minutosC)<10)
    {
      LUGAR(i,129);
      std::cout << horaC << ":0" << minutosC;
    }
    else
    {
      LUGAR(i,129);
      std::cout << horaC << ":" << minutosC;
    }
    i+=1; // Se utiliza para la correcta visualización
    j++; // Para la posición
    
  } //end while
  
}

int Agenda::eliminarDeBaseDeDatos(const string& nombreEliminar) const
{
  std::ifstream ficheroEntrada;
  std::ofstream ficheroSalida;
  std::string nombre, aux;
  int borrar=0;
  
  ficheroEntrada.open(getBaseDeDatos());
  ficheroSalida.open(getBaseDeDatosAuxiliar());
  
  if(!ficheroEntrada or !ficheroSalida)
  {
    LUGAR(7,10);
    std::cout << "Error al abrir el fichero";
    exit (-1);
  }
  
  //Buscamos por el nombre de paciente y ademas obtenemos toda la línea restante con los datos
  while(getline(ficheroEntrada, nombre, ';') and getline(ficheroEntrada, aux, '\n'))
  {
    //Si el nombre coincide con el que buscamos, lo eliminamos
    if(nombre.compare(nombreEliminar)==0)
    {
      borrar++;
    }
    else
    {
      ficheroSalida << nombre << ";" << aux << "\n";
    }
  }
  
  remove(getBaseDeDatos().c_str());
  rename(getBaseDeDatosAuxiliar().c_str(),getBaseDeDatos().c_str());
  
  return(borrar);

}

void Agenda::buscarPacienteEnBaseDeDatos(const string& nombrePaciente) const
{
  std::ifstream ficheroEntrada;
  ficheroEntrada.open(getBaseDeDatos());
  std::string nombre, aux;
  
  if(!ficheroEntrada)
  {
    LUGAR(7,10);
    std::cout << "Error al abrir el fichero";
    exit (-1);
  }
  
  int i=6, j=0;
  std::string horaC, minutosC, dni;
  std::string diaN, mesN, yearN, diaC, mesC, yearC;
  std::string apellidos, telefono, motivo;
  
  LUGAR(5,5);
  std::cout << "Posición" << "\tNombre" << "\t\t   DNI" << "\t\tApellidos" << "\t\tFecha de Nacimiento" << "\tTelefono" << "\tFecha Cita" << "\tHora Cita" << "\tMotivo Cita";
  
  while(getline(ficheroEntrada, nombre, ';'))
  {
    //Si el nombre coincide con el que buscamos, lo eliminamos
    if(nombre.compare(nombrePaciente)==0)
    {     
      getline(ficheroEntrada, apellidos, ';');
      getline(ficheroEntrada, dni, ';');
      getline(ficheroEntrada, diaN, ';');
      getline(ficheroEntrada, mesN, ';');
      getline(ficheroEntrada, yearN, ';');
      getline(ficheroEntrada, telefono, ';');
      getline(ficheroEntrada, diaC, ';');
      getline(ficheroEntrada, mesC, ';');
      getline(ficheroEntrada, yearC, ';');
      getline(ficheroEntrada, motivo, ';');
      getline(ficheroEntrada, horaC, ';');
      getline(ficheroEntrada, minutosC, ';');
      getline(ficheroEntrada, aux, '\n');
      
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
      LUGAR(i,140);
      std::cout << "\t" << motivo << "\t";
      
      if(std::stoi(minutosC)<10)
      {
	LUGAR(i,129);
	std::cout << horaC << ":0" << minutosC;
      }
      else
      {
	LUGAR(i,129);
	std::cout << horaC << ":" << minutosC;
      }
      i+=1; // Se utiliza para la correcta visualización
      j++; // Para la posición
      }
    else
    {
      //Si no coincide, pasamos por alto el resto de información
      getline(ficheroEntrada, aux, '\n');
    }
  } //endwhile

}

int Agenda::modificarPacienteEnBaseDeDatos(const string& DNI) const
{
  std::ifstream ficheroEntrada;
  std::ofstream ficheroSalida;
  
  ficheroEntrada.open(getBaseDeDatos());
  ficheroSalida.open(getBaseDeDatosAuxiliar());
  
  Paciente p1;
  int modificar=0;
  int opcion;
  
  if(!ficheroEntrada or !ficheroSalida)
  {
    LUGAR(7,10);
    std::cout << "Error al abrir el fichero";
    exit (-1);
  }
  
  std::string auxfecha, auxhoracita;
  int posicionBarra, posicionBarra2;
  
  std::string nombre, aux;
  std::string horaC, minutosC, dniF;
  std::string diaN, mesN, yearN, diaC, mesC, yearC;
  std::string apellidos, telefono, motivo;
  
  while(getline(ficheroEntrada, nombre, ';') && getline(ficheroEntrada, apellidos, ';') && getline(ficheroEntrada, dniF, ';') && modificar!=10)
  {
    //std::cout << DNI << std::endl;
    //std::cout << dniF << std::endl;
    
    if(dniF.compare(DNI)==0)
    {
      //Nombre;Apellidos;DNI;DiaNacimiento;MesNacimiento;AñoNacimiento;Telefono;DiaCita;MesCita;AñoCita;MotivoCita;HoraCita;MinutosCita
      do{
      LUGAR(7,10);
      std::cout << "Seleccione una opción";
      LUGAR(9,11);
      std::cout << "1. Modificar nombre";
      LUGAR(10,11);
      std::cout << "2. Modificar apellidos";
      LUGAR(11,11);
      std::cout << "3. Modificar DNI";
      LUGAR(12,11);
      std::cout << "4. Modificar fecha de nacimiento";
      LUGAR(13,11);
      std::cout << "5. Modificar telefono";
      LUGAR(14,11);
      std::cout << "6. Modificar fecha de la cita";
      LUGAR(15,11);
      std::cout << "7. Modificar motivo de la cita";
      LUGAR(16,11);
      std::cout << "8. Modificar hora de la cita";
      LUGAR(17,11);
      std::cout << "9. No modificar nada";
      
      LUGAR(19,10);
      std::cout << "Opción: ";
      std::cin >> opcion;
      
      }while(opcion<0 or opcion>9);
      
      BORRAR;
      getchar();
      
      switch(opcion)
      {
	case 1:
	  //NOMBRE DEL PACIENTE
	  LUGAR(5,10);
	  std::cout << "Introduzca el nuevo nombre del paciente: ";
	  std::getline(std::cin, nombre);
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << aux << "\n";
	  
	  modificar=1;
	  break;
	  
	case 2:
	  //APELLIDOS DEL PACIENTE
	  LUGAR(5,10);
	  std::cout << "Introduzca los nuevos apellidos del paciente: ";
	  std::getline(std::cin, apellidos);
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << aux << "\n";
	  
	  modificar=2;
	  break;
	  
	case 3:
	  //DNI DEL PACIENTE
	  LUGAR(5,10);
	  std::cout << "Introduzca el nuevo DNI del paciente: ";
	  std::cin >> dniF;
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << aux << "\n";
	  
	  modificar=3;
	  break;
	  
	case 4:
	  //FECHA DE NACIMIENTO DEL PACIENTE
	  LUGAR(5,10);
	  std::cout << "Introduzca la nueva fecha de nacimiento (DD/MM/YYYY): ";
	  std::cin >> auxfecha;

	  //Obtenemos la fecha de nacimiento antigua
	  getline(ficheroEntrada, diaN, ';');
	  getline(ficheroEntrada, mesN, ';');
	  getline(ficheroEntrada, yearN, ';');
	  
	  //Obtenemos la posición de la primera barra
	  posicionBarra=auxfecha.find_first_of("/");
	  diaN=auxfecha.substr(0,posicionBarra);

	  //Obtenemos la posición de la segunda barra
	  posicionBarra2=auxfecha.find_first_of("/",posicionBarra+1);
	  mesN=auxfecha.substr(posicionBarra+1,posicionBarra2-3); //El -3 es pq sale un error que no tiene ni pies ni cabeza

	  yearN=auxfecha.substr(posicionBarra2+1);

	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << diaN << ";" << mesN << ";" << yearN << ";" << aux << "\n";
	  
	  modificar=4;
	  break;
	  
	case 5:
	  //TELEFONO DEL PACIENTE
	  getline(ficheroEntrada, diaN, ';');
	  getline(ficheroEntrada, mesN, ';');
	  getline(ficheroEntrada, yearN, ';');
	  getline(ficheroEntrada, telefono, ';');

	  LUGAR(5,10);
	  std::cout << "Introduzca el nuevo telefono del paciente: ";
	  std::cin >> telefono;

	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << diaN << ";" << mesN << ";" << yearN << ";" << telefono << ";" << aux << "\n";
     
	  modificar=5;
	  break;
	  
	case 6:
	  //FECHA DE LA CITA DEL PACIENTE
	  LUGAR(5,10);
	  std::cout << "Introduzca la nueva fecha de la cita (DD/MM/YYYY): ";
	  std::cin >> auxfecha;
	  
	  getline(ficheroEntrada, diaN, ';');
	  getline(ficheroEntrada, mesN, ';');
	  getline(ficheroEntrada, yearN, ';');
	  getline(ficheroEntrada, telefono, ';');
	  
	  //Obtenemos la fecha antigua
	  getline(ficheroEntrada, diaC, ';');
	  getline(ficheroEntrada, mesC, ';');
	  getline(ficheroEntrada, yearC, ';');
	  
	  //Obtenemos la posición de la primera barra
	  posicionBarra=auxfecha.find_first_of("/");
	  diaC= auxfecha.substr(0,posicionBarra);

	  //Obtenemos la posición de la segunda barra
	  posicionBarra2=auxfecha.find_first_of("/",posicionBarra+1);
	  mesC= auxfecha.substr(posicionBarra+1,posicionBarra2-3);  //El -3 es pq sale un error que no tiene ni pies ni cabeza

	  //Obtenemos el año
	  yearC=auxfecha.substr(posicionBarra2+1);
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << diaN << ";" << mesN << ";" << yearN << ";"
	  << telefono << ";" << diaC << ";" << mesC << ";" << yearC << ";" << aux << "\n";
	  
	  modificar=6;
	  break;
	  
	case 7:
	  //MOTIVO DE LA CITA DEL PACIENTE
	  getline(ficheroEntrada, diaN, ';');
	  getline(ficheroEntrada, mesN, ';');
	  getline(ficheroEntrada, yearN, ';');
	  getline(ficheroEntrada, telefono, ';');
	  getline(ficheroEntrada, diaC, ';');
	  getline(ficheroEntrada, mesC, ';');
	  getline(ficheroEntrada, yearC, ';');
	  
	  //Obtenemos el motivo antiguo
	  getline(ficheroEntrada, motivo, ';');

	  LUGAR(5,10);
	  std::cout << "Introduzca el nuevo motivo de la cita del paciente: ";
	  std::getline(std::cin, motivo);
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << diaN << ";" << mesN << ";" << yearN << ";"
	  << telefono << ";" << diaC << ";" << mesC << ";" << yearC << ";" << motivo << ";" << aux << "\n";
	  modificar=7;
	  break;
	  
	case 8:
	  //HORA DE LA CITA DEL PACIENTE
	  LUGAR(5,10);
	  std::cout << "Introduzca la hora de la cita (HH:MM): ";
	  std::cin >> auxhoracita;
	  
	  getline(ficheroEntrada, diaN, ';');
	  getline(ficheroEntrada, mesN, ';');
	  getline(ficheroEntrada, yearN, ';');
	  getline(ficheroEntrada, telefono, ';');
	  getline(ficheroEntrada, diaC, ';');
	  getline(ficheroEntrada, mesC, ';');
	  getline(ficheroEntrada, yearC, ';');
	  getline(ficheroEntrada, motivo, ';');
	  
	  //Obtenemos la hora antigua
	  getline(ficheroEntrada, horaC, ';');
	  getline(ficheroEntrada, minutosC, ';');
	  
	  //Obtenemos la posición de los :
	  posicionBarra=auxhoracita.find_first_of(":");
	  horaC=auxhoracita.substr(0,posicionBarra);
	  
	  minutosC=auxhoracita.substr(posicionBarra+1);
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << diaN << ";" << mesN << ";" << yearN << ";"
	  << telefono << ";" << diaC << ";" << mesC << ";" << yearC << ";" << motivo << ";" << horaC << ";" << minutosC << ";" << aux << "\n";
	  
	  modificar=8;

	  break;
	  
	case 9:
	  modificar=10;
	  break;
	
      }
    }
    else
    {
      //Si no coincide, pasamos por alto el resto de información
      getline(ficheroEntrada, aux, '\n');
      ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << aux << "\n";
    }
  }
  
  if(modificar>0 && modificar<10)
  {
    remove(getBaseDeDatos().c_str());
    rename(getBaseDeDatosAuxiliar().c_str(),getBaseDeDatos().c_str());
  }
  else
  {
    remove(getBaseDeDatosAuxiliar().c_str());
  }

  return (modificar);
}



