#set(CORE
#        main.cpp
#        )

set(SFML_SRCS
        Sfml/App.cpp
        )

set(IMGUI_SRC
        Imgui/imgui.cpp
        Imgui/imgui_draw.cpp
        Imgui/imgui_demo.cpp
)

set(IMGUI_SFML_SRC
        Imgui/imgui-sfml/examples/main.cpp
        Imgui/imgui-sfml/imgui-SFML.cpp
)


set(SRCS
        ${SFML_SRCS}
	${IMGUI_SRC}
        ${IMGUI_SFML_SRC}
        )