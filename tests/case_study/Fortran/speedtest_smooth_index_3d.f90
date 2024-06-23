PROGRAM jacobi
  USE ISO_FORTRAN_ENV
  IMPLICIT NONE
  INTEGER, PARAMETER :: NX=1000, NY=1000, NZ=1000, NITS=20
  REAL(REAL64), DIMENSION(:,:,:), ALLOCATABLE,TARGET :: data, data2
  INTEGER :: i, j, k, its, start,end
  REAL :: count_rate
  ALLOCATE(data(0:NX+1,0:NY+1,0:NZ+1), data2(0:NX+1,0:NY+1,0:NZ+1))
  data=0
  data(0,:,:)=1
  data(NX+1,:,:)=1
  data(:,0,:)=1
  data(:,NY+1,:)=1
  data(:,:,0)=1
  data(:,:,NZ+1)=1
  CALL SYSTEM_CLOCK(start,count_rate)
  DO its=1,NITS
    DO k=1,NZ
      DO j=1,NY
        DO i=1,NX
          data2(i,j,k)=(data(i-1,j,k)+data(i+1,j,k)+data(i,j-1,k)+data(i,j+1,k)+data(i,j,k-1)+data(i,j,k+1))/6.0_REAL64
        ENDDO
      ENDDO
    ENDDO
    data(1:NX,1:NY,1:NZ)=data2(1:NX,1:NY,1:NZ)
  ENDDO
  CALL SYSTEM_CLOCK(end)
  PRINT *, 'Time for main loop is ', REAL(end-start)/count_rate
  PRINT '(F24.17)', MAXVAL(data(1:NX,1:NY,1:NZ))
  PRINT '(F24.17)', MINVAL(data(1:NX,1:NY,1:NZ))
  PRINT '(F24.17)', SUM(data(1:NX,1:NY,1:NZ))/REAL(SIZE(data(1:NX,1:NY,1:NZ),KIND=INT64),REAL64)

END PROGRAM jacobi
