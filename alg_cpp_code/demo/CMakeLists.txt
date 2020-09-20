# PROJECT(algorithm_data_structure)

# SET(array_struct_pointer array_struct_pointer.cpp)
# SET(test_avl test_avl.cpp)
# SET(test_binaryTree test_binaryTree.cpp)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/inc)

ADD_EXECUTABLE(array_struct_pointer array_struct_pointer.cpp)
ADD_EXECUTABLE(test_avl test_avl.cpp)
ADD_EXECUTABLE(test_binaryTree test_binaryTree.cpp)
