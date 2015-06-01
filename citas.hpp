/*!
  \file   citas.hpp
  \brief  Definición de la la clase Cita
  \author Fernando Aguilera Madueño
  \date   23/05/2015
*/

#ifndef _CITAS_HPP_
#define _CITAS_HPP_
#include "fecha.hpp"
#include <string>

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
  //Observers
  //! \name Funciones de consulta de Fecha
  
  inline std::string getMotivo()const
  {
    return (_motivo);
  }
  
  inline int getHoraCita()const
  {
    return (_horaCita);
  }
  
  inline int getMinutosCita()const
  {
    return (_minutosCita);
  }
  
  inline Fecha getFechaCita()const
  {
    return (_fechaCita);
  }
  
  //Modifiers
  //! \name Funciones de modificación de Cita
  
  inline void setMotivo(const std::string & nuevoMotivo)
  {
    _motivo=nuevoMotivo;
  }
  
  inline void setHoraCita(const int & nuevaHoraCita)
  {
    _horaCita=nuevaHoraCita;
  }
  
  inline void setMinutosCita(const int & nuevoMinutosCita)
  {
    _minutosCita=nuevoMinutosCita;
  }
  
};
#endif