project(payroll)


set(HEADER_FILES Payroll.h)

set(SOURCE_FILES Payroll.cpp)

add_library(payroll_library ${SOURCE_FILES} ${HEADER_FILES})
project(payroll)
to
project(payroll_library)
