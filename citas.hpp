/*!
  \file   citas.hpp
  \brief  Definición de la la clase Cita
  \author Fernando Aguilera Madueño
  \date   23/05/2015
*/

#ifndef _CITAS_HPP_
#define _CITAS_HPP_
#include "fecha.hpp"

//!  Definición de la clase Fecha
class Cita
{
  //! \name Atributos privados de la clase Cita
private:
  Fecha _fechaCita;	//!< Fecha de la cita del paciente
  std::string _motivo;	//!< Motivo de la cita
  int _horaCita;	//!< Hora de la cita
  int _minutosCita;	//!< Minutos de la cita
  
public:
  
  
};
#endif