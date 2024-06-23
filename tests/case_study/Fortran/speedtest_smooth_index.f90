PROGRAM jacobi
  USE ISO_FORTRAN_ENV
  IMPLICIT NONE
  INTEGER, PARAMETER :: NX=10000, NY=10000, NITS=200
  REAL(REAL64), DIMENSION(:,:), ALLOCATABLE,TARGET :: data, data2
  INTEGER :: i, j, its, start,end
  REAL :: count_rate
  ALLOCATE(data(0:NX+1,0:NY+1), data2(0:NX+1,0:NY+1))
  data=0
  data(0,:)=1
  data(NX+1,:)=1
  data(:,0)=1
  data(:,NY+1)=1
  CALL SYSTEM_CLOCK(start,count_rate)
  !$OMP PARALLEL
  DO its=1,NITS
    DO j=1,NY
      !$OMP DO
      DO i=1,NX
        data2(i,j)=0.25_REAL64 * (data(i-1,j)+data(i+1,j)+data(i,j-1)+data(i,j+1))
      ENDDO
    ENDDO
    data(1:NX,1:NY)=data2(1:NX,1:NY)
  ENDDO
  !$OMP END PARALLEL
  CALL SYSTEM_CLOCK(end)
  PRINT *, 'Time for main loop is ', REAL(end-start)/count_rate
  PRINT '(F24.17)', MAXVAL(data(1:NX,1:NY))
  PRINT '(F24.17)', MINVAL(data(1:NX,1:NY))
  PRINT '(F24.17)', SUM(data(1:NX,1:NY))/REAL(SIZE(data(1:NX,1:NY),KIND=INT64),REAL64)

END PROGRAM jacobi
