PROGRAM test
  USE ISO_FORTRAN_ENV
  IMPLICIT NONE
  INTEGER, PARAMETER :: NX=1000, NY=1000, NZ=1000, NITS=20
  REAL(REAL64), DIMENSION(:,:,:), ALLOCATABLE,TARGET :: T, T2
  INTEGER :: i, j, its, start,end
  REAL :: count_rate
  ALLOCATE(T(0:NX+1,0:NY+1,0:NZ+1), T2(0:NX+1,0:NY+1,0:NZ+1))
  T=0
  T(0,:,:)=1
  T(NX+1,:,:)=1
  T(:,0,:)=1
  T(:,NY+1,:)=1
  T(:,:,0)=1
  T(:,:,NZ+1)=1
  CALL SYSTEM_CLOCK(start,count_rate)
  !$OMP PARALLEL
  DO its=1,NITS
  !$OMP WORKSHARE
    T2(1:NX,1:NY,1:NZ)= (T(0:NX-1,1:NY,1:NZ)+T(2:NX+1,1:NY,1:NZ)+T(1:NX,0:NY-1,1:NZ)+T(1:NX,2:NY+1,1:NZ) + &
      T(1:NX,1:NY,0:NZ-1) + T(1:NX,1:NY,2:NZ+1))/6.0_real64
    T(1:NX,1:NY,1:NZ)=T2(1:NX,1:NY,1:NZ)
    !$OMP END WORKSHARE
  ENDDO
  !$OMP END PARALLEL
  CALL SYSTEM_CLOCK(end)
  PRINT *, 'Time for main loop is ', REAL(end-start)/count_rate
  PRINT *, MAXVAL(T(1:NX,1:NY,1:NZ)),MINVAL(T(1:NX,1:NY,1:NZ))
  PRINT *, SUM(T(1:NX,1:NY,1:NZ))/REAL(SIZE(T,KIND=INT64))

END PROGRAM test
