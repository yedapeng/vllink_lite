# CMakeLists head

target_sources(vsfkernel INTERFACE
    vsf_tgui_v.c
)

add_subdirectory(simple_view)
add_subdirectory(template)
