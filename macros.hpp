/*!
  \file  macros.hpp
  \brief Macros para el diseño de pantallas
*/

#ifndef MACROS_HPP
#define MACROS_HPP

#define LUGAR(x,y)   printf("\033[%d;%dH",x,y) //!< Macro LUGAR
#define BORRAR       printf("\33[2J") //!< Macro BORRAR
#define PARPADEO     printf("%c[5m",27) //!< Macro PARPADEO
#define APAGA        printf("%c[0m",27) //!< Macro APAGA
#define INVERSO      printf("%c[7m",27) //!< Macro INVERSO
#define SUBRAYADO    printf("%c[4m",27) //!< Macro SUBRAYADO
#define INTENSIDAD   printf("%c[1m",27) //!< Macro INTENSIDAD

#endif