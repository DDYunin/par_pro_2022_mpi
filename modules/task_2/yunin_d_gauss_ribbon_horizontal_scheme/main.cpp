// Copyright 2022 Yunin Daniil
#include <gtest/gtest.h>
#include <vector>
#include "./gauss_ribbon_horizontal_scheme.h"
#include <gtest-mpi-listener.hpp>

TEST(Solving_Method_Gauss_Ribbon_Horizontal_Scheme, Test) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<double> global_vec;
    const int count_size_vector = 5;
    if (rank == 0) {
        global_vec = GaussConsequent(count_size_vector);
        for (int i = 0; i < count_size_vector; i++) {
            for (int j = 0; j < count_size_vector; j++) {
                std::cout << global_vec[i*count_size_vector+j] << ' ';
            }
            std::cout << std::endl;
        }
        
        ASSERT_EQ(1, 1);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    MPI_Init(&argc, &argv);

    ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();

    listeners.Release(listeners.default_result_printer());
    listeners.Release(listeners.default_xml_generator());

    listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
    return RUN_ALL_TESTS();
}
