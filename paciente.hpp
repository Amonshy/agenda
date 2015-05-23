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
  
public:
  
};

#endif