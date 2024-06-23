MODULE test
    USE, INTRINSIC :: ISO_C_BINDING
    IMPLICIT NONE
    REAL(C_FLOAT), DIMENSION(:,:), TARGET,ALLOCATABLE :: A
    CONTAINS
    FUNCTION getA(nx,ny) BIND(C,name="getA") !Bind C with name to get capitalisation
        INTEGER(C_INT), VALUE :: nx,ny
        TYPE(C_PTR) :: getA
        INTEGER :: i, j
        IF (ALLOCATED(A)) DEALLOCATE(A)
        ALLOCATE(A(nx,ny))
        DO j=1,ny
            DO i=1,nx
                A(i,j) = (i-1)+(j-1)*nx + 1
            END DO
        END DO
        getA = C_LOC(A)
    END FUNCTION getA

    SUBROUTINE printA() BIND(C,name="printA")
        PRINT *, 'A:', A
    END SUBROUTINE printA
END MODULE test