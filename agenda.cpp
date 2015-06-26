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
  << p1.getCita().getHoraCita() << ";" << p1.getCita().getMinutosCita() << ";";
  
  if(p1.getHistorial().size()>0)
  {
    ficheroSalida << p1.getHistorial().size() << ";";
    unsigned int i=0;
    while(i<p1.getHistorial().size())
    {
      ficheroSalida << p1.getHistorial().at(i).getDiaFechaCita() << ";" << p1.getHistorial().at(i).getMesFechaCita() << ";" << p1.getHistorial().at(i).getYearFechaCita() << ";"
      << p1.getHistorial().at(i).getMotivo() << ";" << p1.getHistorial().at(i).getHoraCita() << ";" << p1.getHistorial().at(i).getMinutosCita() << ";"; 
      i++;
    }
  }
  else
  {
    ficheroSalida << "0" << ";";
  }
  
  ficheroSalida << "\n";
  
  LUGAR(15,10);
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
  
  std::string horaC, minutosC, dni, aux, historial;
  std::string diaN, mesN, yearN, diaC, mesC, yearC;
  std::string nombre, apellidos, telefono, motivo;
  int i=6, j=0;
  
  LUGAR(5,5);
  std::cout << "Posición" << "\tNombre" << "\t\t   DNI" << "\t\tApellidos" << "\t\tFecha de Nacimiento" << "\tTelefono" << "\tFecha Cita" << "\tHora Cita" << "\tMotivo Cita";

  while(getline(ficheroEntrada, nombre, ';') and getline(ficheroEntrada, apellidos, ';') and getline(ficheroEntrada, dni, ';') and getline(ficheroEntrada, diaN, ';')
  and getline(ficheroEntrada, mesN, ';') and getline(ficheroEntrada, yearN, ';') and getline(ficheroEntrada, telefono, ';') and  getline(ficheroEntrada, diaC, ';')
  and getline(ficheroEntrada, mesC, ';') and getline(ficheroEntrada, yearC, ';') and getline(ficheroEntrada, motivo, ';') and getline(ficheroEntrada, horaC, ';')
  and getline(ficheroEntrada, minutosC, ';') and getline(ficheroEntrada, historial, ';'))
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
    i++; // Se utiliza para la correcta visualización
    j++; // Para la posición
    
    //Sino hay mas citas en el historial
    if(std::stoi(historial)==0)
    {
      getline(ficheroEntrada, aux, '\n');
    }
    else
    {
      //Si hay citas en el historial
      int contador=0;
      do{
	getline(ficheroEntrada, diaC, ';');
	getline(ficheroEntrada, mesC, ';');
	getline(ficheroEntrada, yearC, ';');
	getline(ficheroEntrada, motivo, ';');
	getline(ficheroEntrada, horaC, ';');
	getline(ficheroEntrada, minutosC, ';');
	
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
	i++; //Correcta visualización
	contador++;
      }while(contador<std::stoi(historial));
      
      getline(ficheroEntrada, aux, '\n');
      
    }
    
    i++; //Correcta visualización
    
  } //end while
  
}

int Agenda::eliminarDeBaseDeDatos(const string& DNI) const
{
  std::ifstream ficheroEntrada;
  std::ofstream ficheroSalida;
  std::string nombre, apellidos, dniExtraido, aux, respuesta;
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
  while(getline(ficheroEntrada, nombre, ';') and getline(ficheroEntrada, apellidos, ';') and getline(ficheroEntrada, dniExtraido, ';') and getline(ficheroEntrada, aux, '\n'))
  {
    //Si el nombre coincide con el que buscamos, lo eliminamos
    if(dniExtraido.compare(DNI)==0)
    {
      do{
	BORRAR;
	LUGAR(5,10);
	std::cout << "¿Esta seguro que desea eliminar al paciente " << nombre << " ? (S/N): ";
	std::cin >> respuesta;
	
      }while(respuesta!="S" and respuesta!="N");
      
      if(respuesta.compare("N")==0)
      {
	ficheroSalida << nombre << ";" << apellidos << ";" << dniExtraido << ";" << aux << "\n";
      }
      else
      {
	borrar++;
      }
    }
    else
    {
      ficheroSalida << nombre << ";" << apellidos << ";" << dniExtraido << ";" << aux << "\n";
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
  
  Paciente p1;
  
  int i=6, j=0;
  std::string horaC, minutosC, dni, historial;
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
      getline(ficheroEntrada, historial, ';');
      
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
      
      //Sino hay mas citas en el historial
      if(std::stoi(historial)==0)
      {
	getline(ficheroEntrada, aux, '\n');
      }
      else
      {
	//Si hay citas en el historial
	int contador=0;
	do{
	  getline(ficheroEntrada, diaC, ';');
	  getline(ficheroEntrada, mesC, ';');
	  getline(ficheroEntrada, yearC, ';');
	  getline(ficheroEntrada, motivo, ';');
	  getline(ficheroEntrada, horaC, ';');
	  getline(ficheroEntrada, minutosC, ';');
	  
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
	  i++; //Correcta visualización
	  contador++;
	}while(contador<std::stoi(historial));
	
	getline(ficheroEntrada, aux, '\n');
      } 
      i++; //Correcta visualización  
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
  
  Cita antigua;
  int modificar=0, numCasos;
  int opcion;
  
  if(!ficheroEntrada or !ficheroSalida)
  {
    LUGAR(7,10);
    std::cout << "Error al abrir el fichero";
    exit (-1);
  }
  
  std::string auxfecha, auxhoracita, casosHistorial;
  int posicionBarra, posicionBarra2;
  
  std::string nombre, aux;
  std::string horaC, minutosC, dniF;
  std::string diaN, mesN, yearN, diaC, mesC, yearC;
  std::string apellidos, telefono, motivo;
  
  while(getline(ficheroEntrada, nombre, ';') && getline(ficheroEntrada, apellidos, ';') && getline(ficheroEntrada, dniF, ';') && modificar!=10)
  {
   
    if(dniF.compare(DNI)==0)
    {
      //Nombre;Apellidos;DNI;DiaNacimiento;MesNacimiento;AñoNacimiento;Telefono;DiaCita;MesCita;AñoCita;MotivoCita;HoraCita;MinutosCita;Número;Historial
      do{
      BORRAR;
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
      std::cout << "9. Añadir nueva cita";
      LUGAR(18,11);
      std::cout << "10. No modificar nada";
      
      LUGAR(20,10);
      std::cout << "Opción: ";
      std::cin >> opcion;
      
      }while(opcion<0 or opcion>10);
      
      BORRAR;
      getchar();
      
      switch(opcion)
      {
	case 1:
	  //NOMBRE DEL PACIENTE
	  do{
	  LUGAR(5,10);

	  std::cout << "Introduzca el nuevo nombre del paciente: ";
	  std::getline(std::cin, nombre);
	  }while(nombre.empty());
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << aux << "\n";
	  
	  modificar=1;
	  break;
	  
	case 2:
	  //APELLIDOS DEL PACIENTE
	  do{
	  LUGAR(5,10);
	  std::cout << "Introduzca los nuevos apellidos del paciente: ";
	  std::getline(std::cin, apellidos);
	  }while(apellidos.empty());
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << aux << "\n";
	  
	  modificar=2;
	  break;
	  
	case 3:
	  //DNI DEL PACIENTE
	  do{
	  LUGAR(5,10);
	  std::cout << "Introduzca el nuevo DNI del paciente: ";
	  std::cin >> dniF;
	  }while(dniF.empty());
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << aux << "\n";
	  
	  modificar=3;
	  break;
	  
	case 4:
	  //FECHA DE NACIMIENTO DEL PACIENTE
	  do{
	  LUGAR(5,10);
	  std::cout << "Introduzca la nueva fecha de nacimiento (DD/MM/YYYY): ";
	  std::cin >> auxfecha;
	  }while(auxfecha.empty());

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
	  do{
	  LUGAR(5,10);
	  std::cout << "Introduzca la nueva fecha de la cita (DD/MM/YYYY): ";
	  std::cin >> auxfecha;
	  }while(auxfecha.empty());
	  
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
	  << telefono << ";" << std::stoi(diaC) << ";" << std::stoi(mesC) << ";" << yearC << ";" << aux << "\n";
	  
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

	  do{
	  LUGAR(5,10);
	  std::cout << "Introduzca el nuevo motivo de la cita del paciente: ";
	  std::getline(std::cin, motivo);
	  }while(motivo.empty());
	  
	  getline(ficheroEntrada, aux, '\n');
	  ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << diaN << ";" << mesN << ";" << yearN << ";"
	  << telefono << ";" << diaC << ";" << mesC << ";" << yearC << ";" << motivo << ";" << aux << "\n";
	  modificar=7;
	  break;
	  
	case 8:
	  //HORA DE LA CITA DEL PACIENTE
	  do{
	  LUGAR(5,10);
	  std::cout << "Introduzca la hora de la cita (HH:MM): ";
	  std::cin >> auxhoracita;
	  }while(auxhoracita.empty());
	  
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
	  //NUEVA CITA A INCLUIR
	  //---------------------------------------------------------------------------------------------------------------------
	  do{
	  LUGAR(5,10);
	  std::cout << "Introduzca la fecha de la cita (DD/MM/YYYY): ";
	  std::cin >> auxfecha;
	  }while(auxfecha.empty());
	  
	  getline(ficheroEntrada, diaN, ';');
	  getline(ficheroEntrada, mesN, ';');
	  getline(ficheroEntrada, yearN, ';');
	  getline(ficheroEntrada, telefono, ';');
	  
	  //Obtenemos la fecha antigua
	  getline(ficheroEntrada, diaC, ';');
	  getline(ficheroEntrada, mesC, ';');
	  getline(ficheroEntrada, yearC, ';');
	  antigua.setDiaFechaCita(std::stoi(diaC));
	  antigua.setMesFechaCita(std::stoi(mesC));
	  antigua.setYearFechaCita(std::stoi(yearC));
	  
	  //Obtenemos la posición de la primera barra
	  posicionBarra=auxfecha.find_first_of("/");
	  diaC= auxfecha.substr(0,posicionBarra);

	  //Obtenemos la posición de la segunda barra
	  posicionBarra2=auxfecha.find_first_of("/",posicionBarra+1);
	  mesC= auxfecha.substr(posicionBarra+1,posicionBarra2-3);  //El -3 es pq sale un error que no tiene ni pies ni cabeza
	  
	  //Obtenemos el año
	  yearC=auxfecha.substr(posicionBarra2+1);
	  
	  //---------------------------------------------------------------------------------------------------------------------
	  //Obtenemos el motivo antiguo
	  getline(ficheroEntrada, motivo, ';');
	  antigua.setMotivo(motivo);
	  
	  getchar();
	  do{
	  LUGAR(6,10);
	  std::cout << "Introduzca el motivo de la cita del paciente: ";
	  std::getline(std::cin, motivo);
	  }while(motivo.empty());

	  //---------------------------------------------------------------------------------------------------------------------
	  
	  //HORA DE LA CITA DEL PACIENTE
	  do{
	  LUGAR(7,10);
	  std::cout << "Introduzca la hora de la cita (HH:MM): ";
	  std::cin >> auxhoracita;
	  }while(auxhoracita.empty());
	  
	  //Obtenemos la hora antigua
	  getline(ficheroEntrada, horaC, ';');
	  antigua.setHoraCita(std::stoi(horaC));
	  getline(ficheroEntrada, minutosC, ';');
	  antigua.setMinutosCita(std::stoi(minutosC));
	  
	  //Obtenemos la posición de los :
	  posicionBarra=auxhoracita.find_first_of(":");
	  horaC=auxhoracita.substr(0,posicionBarra);
	  
	  minutosC=auxhoracita.substr(posicionBarra+1); 
	  
	  getline(ficheroEntrada, casosHistorial, ';');
	  numCasos=std::stoi(casosHistorial)+1; 
	  
	  getline(ficheroEntrada, aux, '\n');

	   ficheroSalida << nombre << ";" << apellidos << ";" << dniF << ";" << diaN << ";" << mesN << ";" << yearN << ";"
	   << telefono << ";" << std::stoi(diaC) << ";" << std::stoi(mesC) << ";" << yearC << ";" << motivo << ";" << horaC << ";" << minutosC << ";" << numCasos << ";"
	   << antigua.getDiaFechaCita() << ";" << antigua.getMesFechaCita() << ";" << antigua.getYearFechaCita() << ";" << antigua.getMotivo() << ";"
	   << antigua.getHoraCita() << ";" << antigua.getMinutosCita() << ";" << aux << "\n";
	  
	  modificar=9;
	  break;
	  
	case 10:
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



