function(GRPC_PROTO_GENERATE FN_PROTO LIB_NAME BIN_DIR)
    # Proto file
    get_filename_component(proto_file ${FN_PROTO} ABSOLUTE)
    get_filename_component(proto_file_path "${proto_file}" PATH)

    # Generated sources
    set(proto_srcs "${BIN_DIR}/${LIB_NAME}.pb.cc")
    set(proto_hdrs "${BIN_DIR}/${LIB_NAME}.pb.h")
    set(grpc_srcs "${BIN_DIR}/${LIB_NAME}.grpc.pb.cc")
    set(grpc_hdrs "${BIN_DIR}/${LIB_NAME}.grpc.pb.h")
    add_custom_command(
        OUTPUT "${proto_srcs}" "${proto_hdrs}" "${grpc_srcs}" "${grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${BIN_DIR}"
            --cpp_out "${BIN_DIR}"
            -I "${proto_file_path}" 
            -I "/home/pi/repos/RobotGarden/build/_deps/grpc-src/third_party/protobuf/src/"
            --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
            "${proto_file}"
        DEPENDS "${proto_file}"
        COMMENT "Running C++ gRPC and proto compiler")

    # Include generated *.pb.h files
    add_library(${LIB_NAME} ${grpc_srcs} ${proto_srcs})
    target_link_libraries(${LIB_NAME} PRIVATE libprotobuf grpc++)
    include_directories("${BIN_DIR}")
endfunction()