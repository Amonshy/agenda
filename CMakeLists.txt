project(agenda)

add_executable(agenda main.cpp paciente.cpp)

install(TARGETS agenda RUNTIME DESTINATION bin)
