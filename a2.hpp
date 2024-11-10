/*  YOUR_FIRST_NAME
 *  YOUR_LAST_NAME
 *  YOUR_UBIT_NAME
 */

#ifndef A2_HPP
#define A2_HPP

#include <vector>
#include <mpi.h>

void isort(std::vector<short int>& Xi, MPI_Comm comm) {
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    long long int n = Xi.size();
    std::vector<short int> x(65536, 0);
    std::vector<short int> global_x(65536, 0);

    // if (rank == 0) for (int i = 0; i < n; i++) std::cout << Xi[i] << " " << rank << std::endl;
    // if (rank == 1) for (int i = 0; i < n; i++) std::cout << Xi[i] << " " << rank << std::endl;

    
    for(int i = 0; i < n; i++) x[Xi[i] + 32768] += 1;

    MPI_Reduce(x.data(), global_x.data(), 65536, MPI_SHORT, MPI_SUM, 0, comm);
    // if (rank == 0) for (int i = 0; i < 65536; i++)  if(global_x[i] != 0) std::cout << global_x[i] << " " << i << " " << rank << std::endl;
    // for (int i = 0; i < 65536; i++) 
    // if(rank == 0){
    //     for (int i = 0; i < 65536; i++){
    //         if(global_x[i] != 0){
    //             std::cout << global_x[i] << std::endl;             
    //         }
    //     }
    // }

    MPI_Bcast(global_x.data(), 65536, MPI_SHORT, 0, comm);
    // if (rank == 1) for (int i = 0; i < 65536; i++)  if(global_x[i] != 0) std::cout << global_x[i] << " " << i << " " << rank << std::endl;

    long long offset = rank * n;
    long long count = 0;
    // std::cout << "Offset: " << offset << " " << rank << std::endl;
    for (int i = 0; i < 65536; i++) {
        // std::cout << "counts " << count << " " << global_x[i] << std::endl;
        if(offset == 0){
            while (global_x[i] != 0 && count != n) {
                // std::cout << "hello" << std::endl;
                Xi[count] = i - 32768;
                count++;
                global_x[i] -= 1;
            }
            if(count == n) break;
        }
        else {
            while (global_x[i] != 0 && offset != 0) {
                offset -= 1;
                global_x[i] -= 1;
            }
        }
    }

    // if (rank == 0) for (int i = 0; i < n; i++) std::cout << Xi[i] << " " << rank << std::endl;
    // if (rank == 1) for (int i = 0; i < n; i++) std::cout << Xi[i] << " " << rank << std::endl;


    // MPI_Barrier(MPI_COMM_WORLD);
    return;
} // isort

#endif // A2_HPP
