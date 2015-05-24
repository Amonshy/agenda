/*!
  \file   fecha.hpp
  \brief  Definición de la la clase Fecha
  \author Fernando Aguilera Madueño
  \date   23/05/2015
*/

#ifndef _FECHA_HPP_
#define _FECHA_HPP_

//!  Definición de la clase Fecha
class Fecha 
{
  //! \name Atributos privados de la clase Fecha
private:
  int _dia;	//!< Día de la fecha introducida
  int _mes;	//!< Més de la fecha introducida
  int _year;	//!< Año de la fecha introducida
  
public:
  //Observers
  
  //! \name Funciones de consulta de Fecha
  
  inline int getDia()const
  {
    return (_dia);
  }
  
  inline int getMes()const
  {
    return (_mes);
  }
  
  inline int getYear()const
  {
    return (_year);
  }
  
  //Modifiers
  
  //! \name Funciones de modificación de Fecha
  
  inline void setDia(const int & nuevoDia)
  {
    _dia=nuevoDia;
  }
  
  inline void setMes(const int & nuevoMes)
  {
    _mes=nuevoMes;
  }
  
  inline void setYear(const int & nuevoYear)
  {
    _year=nuevoYear;
  }
  
};

#endif