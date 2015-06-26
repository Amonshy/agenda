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
  std::string _baseDeDatosAuxiliar;
  
public:
  
  //Constructor
  //! \name Constructor de la clase Agenda
  
  Agenda(const std::string &nuevaBaseDeDatos="bbdd", const std::string &nuevaBaseDeDatosAux="bbddAux")
  {
    _baseDeDatos=nuevaBaseDeDatos;
    _baseDeDatosAuxiliar=nuevaBaseDeDatosAux;
  }
  
  //Observers
  //! \name Funciones de consulta de Agenda
  
  inline std::string getBaseDeDatos()const
  {
    return (_baseDeDatos);
  }
  
  inline std::string getBaseDeDatosAuxiliar()const
  {
    return (_baseDeDatosAuxiliar);
  }
  
  void guardarEnBaseDeDatos(const Paciente& p1)const;
  
  void listarBaseDeDatos()const;
  
  int eliminarDeBaseDeDatos(const std::string& DNI)const;
  
  void buscarPacienteEnBaseDeDatos(const std::string &nombrePaciente)const;
  
  int modificarPacienteEnBaseDeDatos(const std::string& DNI)const;
  
protected:
  
  //Modifiers
  //! \name Funciones de modificación de Agenda
  inline void setBaseDeDatos(const std::string & nuevaBaseDeDatos)
  {
    _baseDeDatos=nuevaBaseDeDatos;
  }
};

#endif