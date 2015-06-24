/*!
  \file   paciente.hpp
  \brief  Definición de la la clase Paciente
  \author Fernando Aguilera Madueño
  \date   23/05/2015
*/

#ifndef _PACIENTE_HPP_
#define _PACIENTE_HPP_
#include <string>
#include "citas.hpp"
#include <vector>

//!  Definición de la clase Paciente
class Paciente
{
  //! \name Atributos privados de la clase Paciente
private:
  std::string _nombre; 		//!< Nombre del paciente
  std::string _apellidos;	//!< Apellidos del paciente
  std::string _DNI;		//!< DNI del paciente
  Fecha _fechaNacimiento;	//!< Fecha de nacimiento del paciente
  int _telefono;		//!< Telefono del paciente
  Cita _citaPaciente;		//!< Cita del paciente
  std::vector <Cita> _historial; //!< Historico de citas
  
public:
  //Observers
  //! \name Funciones de consulta de Paciente
  
  inline std::string getNombre()const
  {
    return (_nombre);
  }
  
  inline std::string getApellidos()const
  {
    return (_apellidos);
  }
  
  inline std::string getDni()const
  {
    return (_DNI);
  }
  
  inline int getTelefono()const
  {
    return (_telefono); 
  }
  
  inline Fecha getFechaNacimiento()const
  {
    return (_fechaNacimiento);
  }
  
  inline Cita getCita()const
  {
    return (_citaPaciente); 
  }
  
  inline std::vector<Cita> getHistorial()const
  {
     return (_historial); 
  }
  
  //Modifiers
  //! \name Funciones de modificación de Paciente
  
  inline void setNombre(const std::string & nuevoNombre)
  {
    _nombre=nuevoNombre;
  }
  
  inline void setApellidos(const std::string & nuevosApellidos)
  {
    _apellidos=nuevosApellidos;
  }
  
  inline void setDni(const std::string & nuevoDni)
  {
    _DNI=nuevoDni;
  }
  
  inline void setTelefono(const int &nuevoTelefono)
  {
    _telefono=nuevoTelefono;
  }
  
  void rellenarDatosPaciente();
};

#endif