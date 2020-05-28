macro(run_manual_third_party_getter)
    include(FetchContent)
    FetchContent_Declare(
        gRPC
            GIT_REPOSITORY https://github.com/grpc/grpc
            GIT_TAG        v1.28.0  # e.g v1.28.0
    )
    set(FETCHCONTENT_QUIET OFF)
    FetchContent_MakeAvailable(gRPC)
endmacro()