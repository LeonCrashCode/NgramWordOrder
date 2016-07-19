cmake_minimum_required (VERSION 2.8.0)
project ("ZGen - A collections of sentence linearization tools")

set (BOOST_ROOT "/home/ljm/boost_1_57_0")

find_package (Boost REQUIRED)

add_definitions (-DBOOST_LOG_DYN_LINK)

set (CMAKE_CXX_FLAGS "-std=c++11 -g -O3 -DNDEBUG -DKENLM_MAX_ORDER=6")
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (SOURCE_DIR             ${PROJECT_SOURCE_DIR}/src)

include_directories (${Boost_INCLUDE_DIRS} ${SOURCE_DIR})

link_directories (${Boost_LIBRARY_DIRS} "/usr/local/lib")

add_executable (testkenlm
	${SOURCE_DIR}/lm/bhiksha.cc
	${SOURCE_DIR}/lm/binary_format.cc
	#	${SOURCE_DIR}/lm/build_binary_main.cc
	${SOURCE_DIR}/lm/config.cc
	#	${SOURCE_DIR}/lm/fragment_main.cc
	#	${SOURCE_DIR}/lm/kenlm_benchmark_main.cc
	${SOURCE_DIR}/lm/left_test.cc
	${SOURCE_DIR}/lm/lm_exception.cc
	${SOURCE_DIR}/lm/model.cc
	#${SOURCE_DIR}/lm/model_test.cc
	#${SOURCE_DIR}/lm/partial_test.cc
	${SOURCE_DIR}/lm/quantize.cc
	#${SOURCE_DIR}/lm/query_main.cc
	${SOURCE_DIR}/lm/read_arpa.cc
	${SOURCE_DIR}/lm/search_hashed.cc
	${SOURCE_DIR}/lm/search_trie.cc
	${SOURCE_DIR}/lm/sizes.cc
	${SOURCE_DIR}/lm/trie.cc
	${SOURCE_DIR}/lm/trie_sort.cc
	${SOURCE_DIR}/lm/value_build.cc
	${SOURCE_DIR}/lm/virtual_interface.cc
	${SOURCE_DIR}/lm/vocab.cc
	
	${SOURCE_DIR}/util/bit_packing.cc
	#${SOURCE_DIR}/util/bit_packing_test.cc
	#${SOURCE_DIR}/util/cat_compressed_main.cc
	${SOURCE_DIR}/util/ersatz_progress.cc
	${SOURCE_DIR}/util/exception.cc
	${SOURCE_DIR}/util/file.cc
	${SOURCE_DIR}/util/file_piece.cc
	#${SOURCE_DIR}/util/file_piece_test.cc
	${SOURCE_DIR}/util/float_to_string.cc
	${SOURCE_DIR}/util/integer_to_string.cc
	#${SOURCE_DIR}/util/integer_to_string_test.cc
	#${SOURCE_DIR}/util/joint_sort_test.cc
	${SOURCE_DIR}/util/mmap.cc
	#${SOURCE_DIR}/util/multi_intersection_test.cc
	${SOURCE_DIR}/util/murmur_hash.cc
	${SOURCE_DIR}/util/parallel_read.cc
	#${SOURCE_DIR}/util/pcqueue_test.cc
	${SOURCE_DIR}/util/pool.cc
	#${SOURCE_DIR}/util/probing_hash_table_benchmark_main.cc
	#${SOURCE_DIR}/util/probing_hash_table_test.cc
	${SOURCE_DIR}/util/read_compressed.cc
	#${SOURCE_DIR}/util/read_compressed_test.cc
	${SOURCE_DIR}/util/scoped.cc
	#${SOURCE_DIR}/util/sized_iterator_test.cc
	#${SOURCE_DIR}/util/sorted_uniform_test.cc
	${SOURCE_DIR}/util/spaces.cc
	${SOURCE_DIR}/util/string_piece.cc
	#${SOURCE_DIR}/util/string_stream_test.cc
	#${SOURCE_DIR}/util/tokenize_piece_test.cc
	${SOURCE_DIR}/util/usage.cc
	${SOURCE_DIR}/util/double-conversion/bignum-dtoa.cc
    ${SOURCE_DIR}/util/double-conversion/bignum.cc
	${SOURCE_DIR}/util/double-conversion/cached-powers.cc
	${SOURCE_DIR}/util/double-conversion/diy-fp.cc
	${SOURCE_DIR}/util/double-conversion/double-conversion.cc
	${SOURCE_DIR}/util/double-conversion/fast-dtoa.cc
	${SOURCE_DIR}/util/double-conversion/fixed-dtoa.cc
	${SOURCE_DIR}/util/double-conversion/strtod.cc
	${SOURCE_DIR}/util/stream/chain.cc
	${SOURCE_DIR}/util/stream/count_records.cc
	${SOURCE_DIR}/util/stream/io.cc
	#	${SOURCE_DIR}/util/stream/io_test.cc
	${SOURCE_DIR}/util/stream/line_input.cc
	${SOURCE_DIR}/util/stream/multi_progress.cc
	${SOURCE_DIR}/util/stream/rewindable_stream.cc
	#${SOURCE_DIR}/util/stream/rewindable_stream_test.cc
	#${SOURCE_DIR}/util/stream/sort_test.cc
	#${SOURCE_DIR}/util/stream/stream_test.cc
	${SOURCE_DIR}/main.cc
	${SOURCE_DIR}/Process.cc
	)	

target_link_libraries (testkenlm
    boost_program_options
    boost_log_setup
    boost_log
    boost_regex
    boost_serialization
    boost_thread
    boost_system
	boost_unit_test_framework
    pthread)

