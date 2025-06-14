#include<iostream>
#include"far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reshape " << argv[0] << "\n";

    Array<int,1> src = linspace(1,2*3*4,2*3*4);
    {
        Array<int,2> dest = reshape(src,8,3);
        Array<int,2> ref;
#ifndef FAR_USE_C_INDEX
        ref = {{1,2,3,4,5,6,7,8},{9,10,11,12,13,14,15,16},{17,18,19,20,21,22,23,24}};
#else
				ref = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24}};
#endif
        if (any(dest!=ref)) {
            std::cout << "reshape (1d to 2d) failed\n";
            return 1;
        }

        dest = reshape(src,std::array<int,2>{8,3});
        if (any(dest!=ref)) {
            std::cout << "reshape (1d to 2d, array as shape) failed\n";
            return 1;
        }


        if (any(reshape(dest,2*3*4)!=src)) {
            std::cout << "reshape failed(1d to 2d to 1d)\n";
            return 1;
        }
    }

    {
        Array<int,3> dest = reshape(src,2,3,4);
        Array<int,3> ref;
#ifndef FAR_USE_C_INDEX
        ref =   {   {{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}},
                    {{13,14},{15,16},{17,18}}, {{19,20},{21,22},{23,24}}
                };
#else
				ref = {
				    {   // First row
				        {1, 2, 3, 4},      // First column
				        {5, 6, 7, 8},      // Second column
				        {9, 10, 11, 12}    // Third column
				    },
				    {   // Second row
				        {13, 14, 15, 16},
				        {17, 18, 19, 20},
				        {21, 22, 23, 24}
				    }
				};
#endif
        if (any(dest!=ref)) {
            std::cout << "reshape (1d to 3d) failed\n";
            return 1;
        }

        if (any(reshape(dest,2*3*4)!=src)) {
            std::cout << "reshape failed(1d to 3d to 1d)\n";
            return 1;
        }
    }

    {
        Array<int,2> src2d;
#ifndef FAR_USE_C_INDEX
        src2d = {{1,2,3,4,5,6,7,8},{9,10,11,12,13,14,15,16},{17,18,19,20,21,22,23,24}};
#else
				src2d = {
			    {1, 9, 17},
			    {2, 10, 18},
			    {3, 11, 19},
			    {4, 12, 20},
			    {5, 13, 21},
			    {6, 14, 22},
			    {7, 15, 23},
			    {8, 16, 24}
			};
#endif
        Array<int,3> dest = reshape(src2d,2,3,4);
        Array<int,3> ref;
#ifndef FAR_USE_C_INDEX
        ref =   {   {{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}},
                    {{13,14},{15,16},{17,18}}, {{19,20},{21,22},{23,24}}
                };
#else
				ref = {{{1,9,17,2},{10,18,3,11},{19,4,12,20}},{{5,13,21,6},{14,22,7,15},{23,8,16,24}}};
#endif

        if (any(dest!=ref)){
            std::cout << "reshape (2d to 3d) failed\n";
            return 1;
        }

        if (any(reshape(dest,2*3*4)!=reshape(src2d,2*3*4))) {
            std::cout << "reshape failed(2d to 3d to 1d)\n";
            return 1;
        }
    }

    std::cout << "All tests passed\n\n";
}
