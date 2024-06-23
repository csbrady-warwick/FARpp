PROGRAM test
  USE ISO_FORTRAN_ENV
  IMPLICIT NONE
  INTEGER, PARAMETER :: NX=10000, NY=10000, NITS=200
  REAL(REAL64), DIMENSION(:,:), ALLOCATABLE, TARGET :: T, T2
  REAL(REAL64), DIMENSION(:,:), POINTER :: shiftm0,shiftp0,shift0m,shift0p
  INTEGER :: i, j, its, start,end
  REAL :: count_rate
  ALLOCATE(T(0:NX+1,0:NY+1), T2(0:NX+1,0:NY+1))
  T=0
  T(0,:)=1
  T(NX+1,:)=1
  T(:,0)=1
  T(:,NY+1)=1
  CALL SYSTEM_CLOCK(start,count_rate)
  shiftm0=>T(0:NX-1,1:NY)
  shiftp0=>T(2:NX+1,1:NY)
  shift0m=>T(1:NX,0:NY-1)
  shift0p=>T(1:NX,2:NY+1)
  !$OMP PARALLEL
  DO its=1,NITS
  !$OMP WORKSHARE
    T2(1:NX,1:NY)=0.25_REAL64 * (shiftm0+shiftp0+shift0m+shift0p)
    T(1:NX,1:NY)=T2(1:NX,1:NY)
    !$OMP END WORKSHARE
  ENDDO
  !$OMP END PARALLEL
  CALL SYSTEM_CLOCK(end)
  PRINT *, 'Time for main loop is ', REAL(end-start)/count_rate
  PRINT *, MAXVAL(T(1:NX,1:NY)),MINVAL(T(1:NX,1:NY))
  PRINT *, SUM(T(1:NX,1:NY))/REAL(SIZE(T,KIND=INT64))

END PROGRAM test
