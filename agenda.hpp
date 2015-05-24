/*!
  \file   agenda.hpp
  \brief  Definición de la la clase Agenda
  \author Fernando Aguilera Madueño
  \date   24/05/2015
*/

#ifndef _AGENDA_HPP_
#define _AGENDA_HPP_

#include "paciente.hpp"

//!  Definición de la clase Agenda
class Agenda
{
  //! \name Atributos privados de la clase Agenda
private:
  std::string _baseDeDatos;
  
public:
  
  //Constructor
  //! \name Constructor de la clase Agenda
  
  Agenda(const std::string &nuevaBaseDeDatos="bbdd")
  {
    _baseDeDatos=nuevaBaseDeDatos;
  }
  
  //Observers
  //! \name Funciones de consulta de Agenda
  
  inline std::string getBaseDeDatos()const
  {
    return (_baseDeDatos);
  }
  
protected:
  
  //Modifiers
  //! \name Funciones de modificación de Agenda
  inline void setBaseDeDatos(const std::string & nuevaBaseDeDatos)
  {
    _baseDeDatos=nuevaBaseDeDatos;
  }
};

#endif