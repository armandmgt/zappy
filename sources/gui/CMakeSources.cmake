set(CORE
        main.cpp
        )

set(CORE_SCENES
        Scenes/GameScene.cpp
        )

set(CORE_NETWORK
        Network/Network.cpp
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
        ${CORE_SCENES}
        ${CORE_NETWORK}
        ${SFML_SRCS}
        ${IMGUI_SRCS}
        ${IMGUI_SFML_SRCS}
        )