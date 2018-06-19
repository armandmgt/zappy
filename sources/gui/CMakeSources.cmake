set(CORE
        main.cpp
        )

set(SFML_SRCS
        Sfml/App.cpp
		Sfml/Scene.cpp
        )

set(IMGUI_SRCS
        Imgui/imgui.cpp
        Imgui/imgui_draw.cpp
        Imgui/imgui_demo.cpp
)

set(IMGUI_SFML_SRCS
        Imgui/imgui-sfml/imgui-SFML.cpp
)


set(SRCS
	${CORE}
        ${SFML_SRCS}
	${IMGUI_SRCS}
        ${IMGUI_SFML_SRCS}
        )