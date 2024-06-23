MODULE linkmod

    USE ISO_C_BINDING
    IMPLICIT NONE

    INTERFACE
        FUNCTION createArray(nx,ny) BIND(C,name="createArray")
            USE ISO_C_BINDING
            IMPLICIT NONE
            INTEGER(C_INT), VALUE :: nx,ny
            TYPE(C_PTR) :: createArray
        END FUNCTION createArray

        SUBROUTINE printArray() BIND(C,name="printArray")
            USE ISO_C_BINDING
            IMPLICIT NONE
        END SUBROUTINE printArray
    END INTERFACE

END MODULE linkmod

PROGRAM test
    USE linkmod
    IMPLICIT NONE

    INTEGER :: nx, ny, i
    TYPE(C_PTR) :: arrayPtr
    INTEGER(C_INT), POINTER, DIMENSION(:,:) :: A

    nx = 3
    ny = 4

    arrayPtr = createArray(nx,ny)
    CALL C_F_POINTER(arrayPtr, A, [nx,ny])
    PRINT *, "In Fortran array is ", A
    PRINT *, "Reversing order and printing from C++"
    A(:,:) = RESHAPE([(i,i=1,nx*ny)], [nx,ny])
    CALL printArray()


END PROGRAM test