# ATACseq_benchmarking
Included in this repository are the Rscripts used to test DAR with various tools originally designed for RNAseq DEG analysis as well as an example c++ file for generating simulated ATACseq peak counts.  The standalone c++ file can be compiled using the command:

g++ --stedv c++11 simulate_ATAC.cpp -o simulate_ATAC

A simulated set of ATACseq peaks with read counts can then be created by running the compiled c++ code:

simulate_ATAC simulated_ATAC_peaks.txt

It has been our expereince that this software takes approximately 10 seconds to run.

The incldued Rscripts assume that all packages and their dependencies are installed and in the search path.

A file "data_table.txt" is included as the experimental design table.

Any of the Rscripts can be running using the following command:

Rscript <simulated_ATAC_tests_[limma/DESeq/DESeq2/edgeR/rank_based/t_test].R simulated_ATAC_peaks.txt data_table.txt

The Rscript will create 10 files int he the current diretory named [limma/DESeq/DESeq2/edgeR/rank_based/t_test]_simulated_ATAC_peaks.txt_[20/15/12/10/8/6/5/4/3/2]_reps.txt.  Each file contains the number of DAR called for each condition.
